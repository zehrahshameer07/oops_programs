#include <iostream>
#include <string>
using namespace std;
// Base class
class Cafe {
private:
    string items[5];    
    float prices[5];    
public:
    Cafe() {
        items[0] = "Espresso"; prices[0] = 100.0;
        items[1] = "Cappuccino"; prices[1] = 150.0;
        items[2] = "Latte"; prices[2] = 150.0;
        items[3] = "Croissant"; prices[3] = 200.0;
        items[4] = "Sandwich"; prices[4] = 350.0;
    }
    void displayMenu() {
        cout << "\nCafe Menu:\n";
        for (int i = 0; i < 5; ++i) {
            cout << i + 1 << ". " << items[i] << " - Rs" << prices[i] << endl;
        }
    }
    void takeOrder() {
        int choice, quantity;
        float totalCost = 0.0;
        cout << "\nPlease enter the item number to order (1-5): ";
        cin >> choice;
        if (choice < 1 || choice > 5) {
            cout << "Invalid choice!" << endl;
            return;
        }
        cout << "Enter quantity: ";
        cin >> quantity;
        totalCost = prices[choice - 1] * quantity;
        cout << "You ordered " << quantity << " " << items[choice - 1]
             << "\nCost: Rs" << totalCost << endl;

        if (totalCost > 500) {
            totalCost *= 0.9; // 10% discount
            cout << "\nA 10% discount has been applied!\n";
        }
        cout << "Total cost after discount: Rs" << totalCost << endl;
    }
};
// single level inheritance
class TakeawayCafe : public Cafe {
public:
    void takeAwayOrder() {
        cout << "\nTakeaway Order:\n";
        takeOrder(); // Call the base class takeOrder method
        cout << "Your order will be ready for takeaway!\n";
    }
};
// multilevel inheritance
class OnlineOrderCafe : public TakeawayCafe {
public:
    void onlineOrder() {
        cout << "\nOnline Order:\n";
        takeOrder(); // Call the base class takeOrder method
        cout << "Your order will be delivered to your address!\n";
    }
};

int main() {
    OnlineOrderCafe onlineCafe;
    onlineCafe.displayMenu(); // Display the menu
    onlineCafe.takeAwayOrder(); // Place a takeaway order
    onlineCafe.onlineOrder(); // Place an online order
    return 0;
}

