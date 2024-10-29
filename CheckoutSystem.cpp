#include <iostream>
#include <vector>
#include "Item.cpp"

class CheckoutSystem {
public:
    // Add an item to the system
    void add_item(const Item& item) {
        this->items.push_back(&item);  // Store pointers for polymorphism
    }

    // Display the items in the system
    void display_items() const {
        std::cout << "Available items:\n";
        for (size_t i = 0; i < this->items.size(); ++i) {
            const Item* item = this->items[i];  // Access the item via pointer
            std::cout << i + 1 << ". " << item->get_name() << " - $" << item->get_price()
                      << " (Stock: " << item->get_stock() << ")\n";
        }
    }

    // Display total sales and revenue
    void display_total_sales() const {
        std::cout << "Total items sold: " << Item::get_total_items_sold() << "\n";
        std::cout << "Total revenue: $" << Item::get_total_revenue() << "\n";
    }

private:
    std::vector<const Item*> items; // Use a vector of pointers for polymorphism
};