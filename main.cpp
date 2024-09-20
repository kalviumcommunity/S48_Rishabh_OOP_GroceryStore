#include "CheckoutSystem.cpp"
#include <iostream>

int main() {
    Item apple("Apple", 0.5, 10);
    Item milk("Milk", 1.2, 20);

    CheckoutSystem checkout_system;
    checkout_system.add_item(apple);
    checkout_system.add_item(milk);

    checkout_system.display_items();

    // Simulate selling some items
    apple.update_stock(2);  // Sold 2 apples
    milk.update_stock(3);    // Sold 3 bottles of milk

    // Display total sales and revenue
    checkout_system.display_total_sales();

    return 0;
}
