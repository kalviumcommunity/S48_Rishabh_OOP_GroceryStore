#include <iostream>
#include <vector>
#include "Item.cpp"

class CheckoutSystem {
public:
    void add_item(Item* item); // Pointer to Item
    void display_items() const;
    ~CheckoutSystem(); // Destructor for cleanup

private:
    std::vector<Item*> items; // Store pointers to dynamically allocated items
};

void CheckoutSystem::add_item(Item* item) {
    this->items.push_back(item); // Add dynamically allocated item to the vector
}

void CheckoutSystem::display_items() const {
    std::cout << "Available items:\n";
    for (size_t i = 0; i < this->items.size(); ++i) {
        const Item* item = this->items[i]; // Access item pointer
        std::cout << i + 1 << ". " << item->get_name() << " - $" << item->get_price()
                  << " (Stock: " << item->get_stock() << ")\n";
    }
}

// Destructor to clean up dynamically allocated memory
CheckoutSystem::~CheckoutSystem() {
    for (size_t i = 0; i < this->items.size(); ++i) {
        delete this->items[i]; // Delete each dynamically allocated Item
    }
}
