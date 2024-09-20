#include <iostream>
#include <vector>
#include "Item.cpp"

class CheckoutSystem {
public:
    void add_item(const Item& item);
    void display_items() const;
    void display_total_sales() const;

private:
    vector<Item> items;
};

void CheckoutSystem::add_item(const Item& item) {
    this->items.push_back(item);
}

void CheckoutSystem::display_items() const {
    cout << "Available items:\n";
    for (size_t i = 0; i < this->items.size(); ++i) {
        const Item& item = this->items[i];
        cout << i + 1 << ". " << item.get_name() << " - $" << item.get_price()
              << " (Stock: " << item.get_stock() << ")\n";
    }
}

void CheckoutSystem::display_total_sales() const {
    cout << "Total items sold: " << Item::get_total_items_sold() << "\n";
    cout << "Total revenue: $" << Item::get_total_revenue() << "\n";
}
