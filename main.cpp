#include "CheckoutSystem.cpp"

int main() {
    // Create an array of Item objects
    Item items[] = {
        Item("Apple", 0.5, 10),
        Item("Milk", 1.2, 20),
        Item("Bread", 1.0, 15)
    };

    // Initialize the CheckoutSystem
    CheckoutSystem checkout_system;

    // Add items from the array to the checkout system
    for (const auto& item : items) {
        checkout_system.add_item(item);
    }

    // Display the items in the checkout system
    checkout_system.display_items();

    return 0;
}
