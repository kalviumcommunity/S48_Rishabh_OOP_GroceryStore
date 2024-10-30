#include <string>
#include <iostream>
using namespace std;

class Product {
public:
    virtual double get_price() const = 0;
    virtual string get_name() const = 0;
    virtual int get_stock() const = 0;
    virtual ~Product() = default;
};

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

    bool update_stock(int quantity) {
        if (quantity <= this->stock) {
            this->stock -= quantity;
            total_items_sold += quantity;
            total_revenue += quantity * price;
            return true;
        }
        return false;
    }

    static double get_total_revenue() { return total_revenue; }
    static int get_total_items_sold() { return total_items_sold; }

protected:
    string name;
    double price;
    int stock;

private:
    static int total_items_sold;
    static double total_revenue;
};

int Item::total_items_sold = 0;
double Item::total_revenue = 0.0;
