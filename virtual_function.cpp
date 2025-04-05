#include <iostream>
#include <string>
class MenuItem {
public:
    virtual double getPrice() const = 0; // Pure virtual function
    virtual std::string getName() const = 0; // Pure virtual function
    virtual ~MenuItem() {} // Virtual destructor
};
class Cake : public MenuItem {
private:
    std::string name;
    double price;
public:
    Cake(const std::string& name, double price) : name(name), price(price) {}

    double getPrice() const override {
        return price;
    }
    std::string getName() const override {
        return name;
    }
};

class Order {
private:
    static const int MAX_ITEMS = 4; 
    MenuItem* items[MAX_ITEMS];
    int itemCount;

public:
    Order() : itemCount(0) {}

    void addItem(MenuItem* item) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount++] = item;
        } else {
            std::cout << "Order is full!" << std::endl;
        }
    }

    double calculateTotal() const {
        double total = 0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i]->getPrice();
        }
        return total;
    }

    void printOrder() const {
        std::cout << "Your Order:\n";
        for (int i = 0; i < itemCount; ++i) {
            std::cout << "- " << items[i]->getName() << ": Rs" << items[i]->getPrice() << '\n';
        }
        std::cout << "Total: Rs" << calculateTotal() << '\n';
    }
};

int main() {
    Order myOrder;

    Cake chocolateCake("Chocolate Cake", 500.0);
    Cake vanillaCake("Vanilla Cake", 450.0);
    Cake redVelvetCake("Red Velvet Cake", 600.0);
    Cake fruitCake("Fruit Cake", 550.0);

    myOrder.addItem(&chocolateCake);
    myOrder.addItem(&vanillaCake);
    myOrder.addItem(&redVelvetCake);
    myOrder.addItem(&fruitCake);

    myOrder.printOrder();

    return 0;
}

