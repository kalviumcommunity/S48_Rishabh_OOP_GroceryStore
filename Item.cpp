#include <string>
using namespace std;

class Item {
public:
    static int total_items_sold;   // Static variable to track total items sold
    static double total_revenue;   // Static variable to track total revenue

    Item(const string& name, double price, int stock)
        : name(name), price(price), stock(stock) {}

    string get_name() const { return this->name; }
    double get_price() const { return this->price; }
    int get_stock() const { return this->stock; }

    bool update_stock(int quantity) {
        if (quantity <= this->stock) {
            this->stock -= quantity;
            total_items_sold += quantity;        // Update total items sold
            total_revenue += quantity * price;   // Update total revenue
            return true;
        }
        return false;
    }

    // Static function to get the total revenue
    static double get_total_revenue() {
        return total_revenue;
    }

private:
    string name;
    double price;
    int stock;
};

// Initialize static variables
int Item::total_items_sold = 0;
double Item::total_revenue = 0.0;
