#include "CheckoutSystem.cpp"

int main() {
    Item apple("Apple", 0.5, 10);
    Item milk("Milk", 1.2, 20);

    CheckoutSystem checkout_system;
    checkout_system.add_item(apple);
    checkout_system.add_item(milk);

    checkout_system.display_items();

    return 0;
}
