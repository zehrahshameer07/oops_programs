#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    string name, item, ph_no, pincode;
    int age, no_of_items;
    float price;
    static int customerCount; 

    Customer() {
        customerCount++; 
    }

    void getdetails() {
        cout << "Enter customer name: ";
        getline(cin, name);
        cout << "Enter customer age: ";
        cin >> age;
        cout << "Enter number of items ordered: ";
        cin >> no_of_items;
        cin.ignore(); 
        cout << "Enter phone number of customer: ";
        getline(cin, ph_no);
        cout << "Enter the pincode of the customer's place: ";
        getline(cin, pincode);
        cout << "Enter the item ordered: ";
        getline(cin, item);
        cout << "Enter the total price: ";
        cin >> price;
    }

    friend void displayCustomerDetails(const Customer& customer);

    
    float calculateDiscountedAmount() const {
        if (price >= 1000) {
            return price - (price * 0.20); 
        }
        return price; 
    }

    
    static int getCustomerCount() {
        return customerCount;
    }
};
int Customer::customerCount = 0;

void displayCustomerDetails(const Customer& customer) {
    cout << "Customer Name: " << customer.name << endl;
    cout << "Customer Age: " << customer.age << endl;
    cout << "Number Of Items Ordered: " << customer.no_of_items << endl;
    cout << "Phone Number: " << customer.ph_no << endl;
    cout << "Pincode: " << customer.pincode << endl;
    cout << "Item Ordered: " << customer.item << endl;
    cout << "Total Amount: " << customer.price << endl;
    cout << "Discounted Amount: " << customer.calculateDiscountedAmount() << endl; 
}

int main() {
    Customer customer; 
    customer.getdetails(); 

    cout << "\nCustomer Details:\n";
    displayCustomerDetails(customer); 

    cout << "\nTotal Customers: " << Customer::getCustomerCount() << endl; 
    return 0;
}

