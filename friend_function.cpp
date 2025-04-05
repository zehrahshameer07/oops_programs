#include <iostream>
#include <string>
using namespace std;
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
    // Friend function declaration
    friend void displayMenu(const Cafe &cafe);
    void takeOrder();
};
// Friend function definition
void displayMenu(const Cafe &cafe) {
    cout << "\nCafe Menu:\n";
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". " << cafe.items[i] << " - Rs" << cafe.prices[i] << endl;
    }
}
void Cafe::takeOrder() {
    int choice;
    int quantity;
    float totalCost = 0.0;
    cout << "\nPlease enter the item number to order (1-5): ";
    cin >> choice;
    if (choice < 1 || choice > 5) {
        cout << "Invalid choice!" << endl;
        return;
    }
    cout << "Enter quantity: ";
    cin >> quantity;
    // Calculate total cost
    totalCost = prices[choice - 1] * quantity;
    cout << "You ordered " << quantity << " " << items[choice - 1]
         << "\nCost: Rs" << totalCost << endl;
        if (totalCost > 500) {
        totalCost *= 0.9; // 10% discount
        cout << "\nA 10% discount has been applied!\n";
    }
    cout << "Total cost after discount: Rs" << totalCost << endl;
}
int main() {
    Cafe cafe; 
    displayMenu(cafe); // Call the friend function to display the menu
    cafe.takeOrder();  
    return 0;
}

