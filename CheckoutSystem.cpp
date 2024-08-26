#include <iostream>
#include <vector>
#include "Item.cpp"
using namespace std;

class CheckoutSystem {
public:
    void add_item(const Item& item) {
        items.push_back(item);
    }

    void display_items() const {
        cout << "Available items:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            const Item& item = items[i];
            cout << i + 1 << ". " << item.get_name() << " - $" << item.get_price()
                      << " (Stock: " << item.get_stock() << ")\n";
        }
    }

private:
    vector<Item> items;
};
