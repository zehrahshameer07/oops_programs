#include <iostream>
#include <string>
using namespace std;
class Customer
{
public:
    string name, item, ph_no, pincode;
    int age, no_of_items;
    float price;
    // Default constructor
    Customer()
        : name(""), item(""), ph_no(""), pincode(""), age(0), no_of_items(0), price(0.0) {
    }
    // Parameterized constructor
    Customer(string n, int a, int noi, string ph, string pin, string it, float pr)
        : name(n), age(a), no_of_items(noi), ph_no(ph), pincode(pin), item(it), price(pr) {
    }
    // Copy constructor
    Customer(const Customer &other)
        : name(other.name), age(other.age), no_of_items(other.no_of_items),
          ph_no(other.ph_no), pincode(other.pincode), item(other.item), price(other.price) {
    }
    void getdetails(string n = "", int a = 0, int noi = 0, string ph = "", string pin = "", string it = "", float pr = 0.0) {
        if (n.empty()) {
            cout << "Enter customer name: ";
            getline(cin, name);
        } else {
            name = n;
        }

        if (a == 0) {
            cout << "Enter customer age: ";
            cin >> age;
        } else {
            age = a;
        }

        if (noi == 0) {
            cout << "Enter number of items ordered: ";
            cin >> no_of_items;
        } else {
            no_of_items = noi;
        }
        

        if (ph.empty()) {
            cout << "Enter phone number of customer: ";
            getline(cin, ph_no);
        } else {
            ph_no = ph;
        }

        if (pin.empty()) {
            cout << "Enter the pincode of the customer's place: ";
            getline(cin, pincode);
        } else {
            pincode = pin;
        }

        if (it.empty()) {
            cout << "Enter the item ordered: ";
            getline(cin, item);
        } else {
            item = it;
        }

        if (pr == 0.0) {
            cout << "Enter the total price: ";
            cin >> price;
        } else {
            price = pr;
        }
    }
    void displaydetails() const {
        cout << "Customer Name: " << name << endl;
        cout << "Customer Age: " << age << endl;
        cout << "Number Of Items Ordered: " << no_of_items << endl;
        cout << "Phone Number: " << ph_no << endl;
        cout << "Pincode: " << pincode << endl;
        cout << "Item Ordered: " << item << endl;
        cout << "Total Amount: " << price << endl;
        cout << "Discounted Amount: " << calculatediscount() << endl;
    }
    float calculatediscount() const {
        float discounted_price = price; 
        if (discounted_price >= 1000) {
            discounted_price -= (discounted_price * 0.20);
        }
        return discounted_price;
    }
};

int main()
{
    Customer customer1;
    customer1.getdetails(); 
    cout << "\nCustomer Details (Default Constructor):\n";
    customer1.displaydetails();
    Customer customer2("Alice", 30, 5, "1234567890", "123456", "Laptop", 1200.0);
    cout << "\nCustomer Details (Parameterized Constructor):\n";
    customer2.displaydetails();
    Customer customer3(customer2); 
    cout << "\nCustomer Details (Copy Constructor):\n";
    customer3.displaydetails();

    return 0;
}
