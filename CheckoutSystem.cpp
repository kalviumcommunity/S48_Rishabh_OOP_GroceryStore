#include <iostream>
#include <vector>
#include "Item.cpp"
#include "SalesTracker.cpp"

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
