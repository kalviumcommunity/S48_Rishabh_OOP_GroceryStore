#include <iostream>
#include "CheckoutSystem.cpp"

int main() {
    Item apple("Apple", 0.5, 10);
    Item milk("Milk", 1.2, 20);

    CheckoutSystem checkout_system;
    checkout_system.add_item(apple);
    checkout_system.add_item(milk);

    // Simulate a purchase
    apple.update_stock(3);  // 3 apples purchased
    milk.update_stock(2);   // 2 milk cartons purchased

    // Demonstrate mutator usage (changing price of milk)
    checkout_system.set_item_price(1, 1.5);  // Update milk price to 1.5

    // Display items and updated prices
    checkout_system.display_items();
    checkout_system.display_total_sales();  // Display total sales and revenue

    return 0;
}
