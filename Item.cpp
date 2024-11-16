#include <iostream>
#include <string>
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

    bool update_stock(int quantity);

private:
    string name;
    double price;
    int stock;
};

bool Item::update_stock(int quantity) {
    if (quantity <= this->stock) {
        this->stock -= quantity;
        SalesTracker::add_sale(quantity, this->price); // Delegate the sales tracking
        return true;
    }
    return false;
}
