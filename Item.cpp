#include <string>
using namespace std;

class Item {
public:
    Item(const string& name, double price, int stock)
        : name(name), price(price), stock(stock) {}

    string get_name() const { return this->name; }
    double get_price() const { return this->price; }
    int get_stock() const { return this->stock; }

    bool update_stock(int quantity) {
        if (quantity <= this->stock) {
            this->stock -= quantity;
            total_items_sold += quantity;  // Update total items sold
            total_revenue += quantity * this->price;  // Update total revenue
            return true;
        }
        return false;
    }

    // Static member function to get the total revenue
    static double get_total_revenue() {
        return total_revenue;
    }

    // Static member function to get the total items sold
    static int get_total_items_sold() {
        return total_items_sold;
    }

private:
    string name;
    double price;
    int stock;

    // Static variables to track total items sold and total revenue
    static int total_items_sold;
    static double total_revenue;
};

// Initialize the static variables outside the class definition
int Item::total_items_sold = 0;
double Item::total_revenue = 0.0;
