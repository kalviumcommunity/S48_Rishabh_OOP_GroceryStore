#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define the Item class
class Item {
public:
    // Default constructor
    Item() : name("Unknown"), price(0.0), stock(0) {
        cout << "Default constructor called for item: " << name << endl;
    }

    // Parameterized constructor
    Item(const string& name, double price, int stock)
        : name(name), price(price), stock(stock) {
        cout << "Parameterized constructor called for item: " << name << endl;
    }

    // Destructor
    ~Item() {
        cout << "Destructor called for item: " << name << endl;
    }

    // Accessor methods (getters)
    string get_name() const { return this->name; }
    virtual double get_price() const { return this->price; }  // Virtual for polymorphism
    int get_stock() const { return this->stock; }

    // Mutator methods (setters)
    void set_price(double new_price) { this->price = new_price; }
    void set_stock(int new_stock) { this->stock = new_stock; }

    // Method to update stock and track total items sold and revenue
    bool update_stock(int quantity) {
        if (quantity <= this->stock) {
            this->stock -= quantity;
            total_items_sold += quantity;        // Update total items sold
            total_revenue += quantity * price;   // Update total revenue
            return true;
        }
        return false;
    }

    // Static functions to get the total revenue and items sold
    static double get_total_revenue() { return total_revenue; }
    static int get_total_items_sold() { return total_items_sold; }

protected:
    string name;    // Protected so derived classes can access it
    double price;
    int stock;

private:
    static int total_items_sold;   // Static variable to track total items sold
    static double total_revenue;   // Static variable to track total revenue
};

// Initialize static variables
int Item::total_items_sold = 0;
double Item::total_revenue = 0.0;


// Define the DiscountedItem class
class DiscountedItem : public Item {
public:
    DiscountedItem(const string& name, double price, int stock, double discount_rate)
        : Item(name, price, stock), discount_rate(discount_rate) {}

    // Override the get_price method to include the discount
    double get_price() const override {
        return price * (1.0 - discount_rate);  // Apply the discount
    }

private:
    double discount_rate;
};


// Define the SeasonalDiscountedItem class
class SeasonalDiscountedItem : public DiscountedItem {
public:
    SeasonalDiscountedItem(const string& name, double price, int stock, double discount_rate, double seasonal_discount)
        : DiscountedItem(name, price, stock, discount_rate), seasonal_discount(seasonal_discount) {}

    // Override the get_price method to apply both the discount and seasonal discount
    double get_price() const override {
        return DiscountedItem::get_price() * (1.0 - seasonal_discount);  // Apply both discounts
    }

private:
    double seasonal_discount;
};


// Define the CheckoutSystem class
class CheckoutSystem {
public:
    // Add an item to the system using an Item object
    void add_item(const Item& item) {
        this->items.push_back(&item);  // Store pointers for polymorphism
    }

    // Overloaded add_item method to add an item by providing item details directly
    void add_item(const string& name, double price, int stock) {
        Item* new_item = new Item(name, price, stock);
        this->items.push_back(new_item);
    }

    // Display the items in the system
    void display_items() const {
        cout << "Available items:\n";
        for (size_t i = 0; i < this->items.size(); ++i) {
            const Item* item = this->items[i];  // Access the item via pointer
            cout << i + 1 << ". " << item->get_name() << " - $" << item->get_price()
                 << " (Stock: " << item->get_stock() << ")\n";
        }
    }

    // Display total sales and revenue
    void display_total_sales() const {
        cout << "Total items sold: " << Item::get_total_items_sold() << "\n";
        cout << "Total revenue: $" << Item::get_total_revenue() << "\n";
    }

    // Destructor to free memory for dynamically created items
    ~CheckoutSystem() {
        for (auto item : items) {
            delete item;
        }
    }

private:
    vector<const Item*> items; // Use a vector of pointers for polymorphism
};


int main() {
    // Default item
    Item default_item;
    default_item.set_price(2.0);
    default_item.set_stock(5);

    // Discounted items
    DiscountedItem apple("Apple", 0.5, 10, 0.10);  // 10% discount
    SeasonalDiscountedItem milk("Milk", 1.2, 20, 0.05, 0.10);  // 5% discount + 10% seasonal discount

    CheckoutSystem checkout_system;
    checkout_system.add_item(default_item);
    checkout_system.add_item(apple);
    checkout_system.add_item(milk);
    
    // Add a new item using the overloaded add_item function
    checkout_system.add_item("Banana", 0.3, 15);

    // Simulate a purchase
    apple.update_stock(3);  // 3 apples purchased
    milk.update_stock(2);   // 2 milk cartons purchased

    // Display items and total sales
    checkout_system.display_items();
    checkout_system.display_total_sales();  // Display total sales and revenue

    return 0;
}
