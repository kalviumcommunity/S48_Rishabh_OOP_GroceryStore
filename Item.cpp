#include <string>
using namespace std;

class Item {
public:
    Item(const string& name, double price, int stock)
        : name(name), price(price), stock(stock) {}

    string get_name() const { return this->name; }
    double get_price() const { return this->price; }
    int get_stock() const { return this->stock; }

    bool update_stock(int quantity) {
        if (quantity <= this->stock) {
            this->stock -= quantity;
            return true;
        }
        return false;
    }

private:
    string name;
    double price;
    int stock;
};
