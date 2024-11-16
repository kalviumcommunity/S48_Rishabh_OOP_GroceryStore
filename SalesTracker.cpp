#include <iostream>
using namespace std;

class SalesTracker {
public:
    static void add_sale(int quantity, double price) {
        total_items_sold += quantity;
        total_revenue += quantity * price;
    }

    static double get_total_revenue() {
        return total_revenue;
    }

    static int get_total_items_sold() {
        return total_items_sold;
    }

private:
    static int total_items_sold;
    static double total_revenue;
};

// Initialize static members
int SalesTracker::total_items_sold = 0;
double SalesTracker::total_revenue = 0.0;
