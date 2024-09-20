#include "CheckoutSystem.cpp"

int main() {
    CheckoutSystem* checkout_system = new CheckoutSystem(); // Dynamically allocate CheckoutSystem

    // Dynamically allocate items
    Item* apple = new Item("Apple", 0.5, 10);
    Item* milk = new Item("Milk", 1.2, 20);

    checkout_system->add_item(apple);
    checkout_system->add_item(milk);

    checkout_system->display_items();

    // Cleanup dynamically allocated memory
    delete checkout_system; // Will call the destructor of CheckoutSystem

    return 0;
}
