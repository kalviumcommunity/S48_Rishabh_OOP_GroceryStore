#include <iostream>
#include <vector>
#include "Item.cpp"

class CheckoutSystem {
public:
    void add_item(const Product& product) {
        this->items.push_back(&product);
    }

    void display_items() const {
        std::cout << "Available items:\n";
        for (size_t i = 0; i < this->items.size(); ++i) {
            const Product* product = this->items[i];
            std::cout << i + 1 << ". " << product->get_name() << " - $" << product->get_price()
                      << " (Stock: " << product->get_stock() << ")\n";
        }
    }

    void display_total_sales() const {
        std::cout << "Total items sold: " << Item::get_total_items_sold() << "\n";
        std::cout << "Total revenue: $" << Item::get_total_revenue() << "\n";
    }

private:
    std::vector<const Product*> items;
};
