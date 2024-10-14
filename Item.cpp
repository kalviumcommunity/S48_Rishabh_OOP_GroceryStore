#include <string>
using namespace std;

class Item {
public:
    // Constructor
    Item(const string& name, double price, int stock)
        : name(name), price(price), stock(stock) {}

    // Accessor methods (getters)
    string get_name() const { return this->name; }
    double get_price() const { return this->price; }
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

private:
    static int total_items_sold;   // Static variable to track total items sold
    static double total_revenue;   // Static variable to track total revenue
    string name;                   // Private member
    double price;                  // Private member
    int stock;                     // Private member
};

// Initialize static variables
int Item::total_items_sold = 0;
double Item::total_revenue = 0.0;
