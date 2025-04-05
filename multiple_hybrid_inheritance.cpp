#include <iostream>
#include <string>

using namespace std;

// Base class for the Cafe
class Cafe {
public:
    void showMenu() {
        cout << "Welcome to the Cafe!\n";
        cout << "1. Food\n";
        cout << "2. Beverages\n";
        cout << "3. Exit\n";
    }
};

// Derived class for Food items
class Food : virtual public Cafe {
public:
    string foodMenu[3];
    float foodPrices[3];

    // Constructor to initialize food items
    Food() {
        foodMenu[0] = "Burger";
        foodMenu[1] = "Pasta";
        foodMenu[2] = "Salad";
        foodPrices[0] = 150;
        foodPrices[1] = 200;
        foodPrices[2] = 100;
    }

    void showFoodMenu() {
        cout << "Food Menu:\n";
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". " << foodMenu[i] << " - Rs " << foodPrices[i] << endl;
        }
    }

    float getFoodPrice(int index) {
        return foodPrices[index];
    }
};

// Derived class for Beverage items
class Beverage : virtual public Cafe {
public:
    string beverageMenu[3];
    float beveragePrices[3];

    // Constructor to initialize beverage items
    Beverage() {
        beverageMenu[0] = "Coffee";
        beverageMenu[1] = "Tea";
        beverageMenu[2] = "Juice";
        beveragePrices[0] = 100;
        beveragePrices[1] = 50;
        beveragePrices[2] = 120;
    }

    void showBeverageMenu() {
        cout << "Beverage Menu:\n";
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". " << beverageMenu[i] << " - Rs " << beveragePrices[i] << endl;
        }
    }

    float getBeveragePrice(int index) {
        return beveragePrices[index];
    }
};

// Hybrid class that inherits from both Food and Beverage
class Customer : public Food, public Beverage {
public:
    void order() {
        int choice;
        float total = 0;

        while (true) {
            showMenu();  // Now unambiguous due to virtual inheritance
            cout << "Please select an option: ";
            cin >> choice;

            if (choice == 1) {
                showFoodMenu();
                int foodChoice;
                cout << "Select food item by number: ";
                cin >> foodChoice;
                total += getFoodPrice(foodChoice - 1);
                cout << "Added to your order: " << foodMenu[foodChoice - 1] << endl;
            } else if (choice == 2) {
                showBeverageMenu();
                int beverageChoice;
                cout << "Select beverage item by number: ";
                cin >> beverageChoice;
                total += getBeveragePrice(beverageChoice - 1);
                cout << "Added to your order: " << beverageMenu[beverageChoice - 1] << endl;
            } else if (choice == 3) {
                cout << "Your total bill is: Rs " << total << endl;
                cout << "Thank you for visiting!\n";
                break;
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    Customer customer;
    customer.order();
    return 0;
}

