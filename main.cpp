#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Forward declaration of SalesTracker
class SalesTracker;

// Define the abstract Product class
class Product {
public:
    virtual double get_price() const = 0;  // Pure virtual function
    virtual string get_name() const = 0;
    virtual int get_stock() const = 0;
    virtual ~Product() = default;
};

// Define the Item class inheriting from Product
class Item : public Product {
public:
    Item() : name("Unknown"), price(0.0), stock(0) {
        cout << "Default constructor called for item: " << name << endl;
    }

    Item(const string& name, double price, int stock)
        : name(name), price(price), stock(stock) {
        cout << "Parameterized constructor called for item: " << name << endl;
    }

    ~Item() {
        cout << "Destructor called for item: " << name << endl;
    }

    string get_name() const override { return this->name; }
    double get_price() const override { return this->price; }  
    int get_stock() const override { return this->stock; }

    void set_price(double new_price) { this->price = new_price; }
    void set_stock(int new_stock) { this->stock = new_stock; }

    bool update_stock(int quantity);

protected:
    string name;
    double price;
    int stock;
};

// Static members for sales tracking (moved out of the class)
class SalesTracker {
public:
    static void add_sale(int quantity, double price) {
        total_items_sold += quantity;
        total_revenue += quantity * price;
    }

    static int get_total_items_sold() { return total_items_sold; }
    static double get_total_revenue() { return total_revenue; }

private:
    static int total_items_sold;
    static double total_revenue;
};

int SalesTracker::total_items_sold = 0;
double SalesTracker::total_revenue = 0.0;

// Method implementation for Item (defined after SalesTracker is available)
bool Item::update_stock(int quantity) {
    if (quantity <= this->stock) {
        this->stock -= quantity;
        SalesTracker::add_sale(quantity, this->price); // Delegate the sales tracking
        return true;
    }
    return false;
}

class DiscountedItem : public Item {
public:
    DiscountedItem(const string& name, double price, int stock, double discount_rate)
        : Item(name, price, stock), discount_rate(discount_rate) {}

    double get_price() const override {
        return price * (1.0 - discount_rate);
    }

private:
    double discount_rate;
};

class SeasonalDiscountedItem : public DiscountedItem {
public:
    SeasonalDiscountedItem(const string& name, double price, int stock, double discount_rate, double seasonal_discount)
        : DiscountedItem(name, price, stock, discount_rate), seasonal_discount(seasonal_discount) {}

    double get_price() const override {
        return DiscountedItem::get_price() * (1.0 - seasonal_discount);
    }

private:
    double seasonal_discount;
};

class CheckoutSystem {
public:
    void add_item(const Product& product) {
        this->items.push_back(&product);
    }

    void display_items() const {
        cout << "Available items:\n";
        for (size_t i = 0; i < this->items.size(); ++i) {
            const Product* product = this->items[i];
            cout << i + 1 << ". " << product->get_name() << " - $" << product->get_price()
                 << " (Stock: " << product->get_stock() << ")\n";
        }
    }

    void display_total_sales() const {
        cout << "Total items sold: " << SalesTracker::get_total_items_sold() << "\n";
        cout << "Total revenue: $" << SalesTracker::get_total_revenue() << "\n";
    }

private:
    vector<const Product*> items;
};

int main() {
    Item default_item;
    default_item.set_price(2.0);
    default_item.set_stock(5);

    DiscountedItem apple("Apple", 0.5, 10, 0.10);
    SeasonalDiscountedItem milk("Milk", 1.2, 20, 0.05, 0.10);

    CheckoutSystem checkout_system;
    checkout_system.add_item(default_item);
    checkout_system.add_item(apple);
    checkout_system.add_item(milk);

    checkout_system.display_items();
    checkout_system.display_total_sales();

    return 0;
}
