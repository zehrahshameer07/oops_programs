#include <iostream>
#include <string>
using namespace std;

class MenuItem {
private:
    string name;  // dynamic string
    double price;

public:
    // Constructor
    MenuItem(const string& itemName, double itemPrice)
        : name(itemName), price(itemPrice) {
        cout << "MenuItem created: " << name << " - Rs" << price << endl;
    }

    // Destructor
    ~MenuItem() {
        cout << "MenuItem destroyed: " << name << endl;
    }

    // Function to display the menu item
    void display() const {
        cout << name << ": Rs" << price << endl;
    }
};

int main() {
    const int itemCount = 3;  // Number of menu items
    MenuItem** menu = new MenuItem*[itemCount];  // Dynamic array of pointers to MenuItem

    // Adding menu items
    menu[0] = new MenuItem("Coffee", 100);
    menu[1] = new MenuItem("Tea", 100);
    menu[2] = new MenuItem("Sandwich", 250);

    // Displaying the menu
    cout << "Cafe Menu:" << endl;
    for (int i = 0; i < itemCount; ++i) {
        menu[i]->display();  // Display each MenuItem
    }

    // Deallocating memory
    for (int i = 0; i < itemCount; ++i) {
        delete menu[i];  // Deallocate each MenuItem
    }
    delete[] menu;  // Deallocate the menu array
    cout << "Memory deallocated." << endl;

    return 0;
}

