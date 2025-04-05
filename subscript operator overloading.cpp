#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Customer {
    string name;
    double billAmount;

public:
    Customer(string n, double amount) : name(n), billAmount(amount) {}
    void display() const {
        cout << "Customer Name: " << name << ", Bill Amount: " << billAmount << endl;
    }
};

class CustomerList {
    vector<Customer> customers; // Store customers in a vector

public:
    // Add a customer to the list
    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    // Overload subscript operator to access customers
    Customer& operator[](int index) {
        return customers[index]; // Return customer at index
    }

    // Get number of customers
    size_t size() const {
        return customers.size();
    }
};

int main() {
    CustomerList customerList;
    // Adding customers to the list
    customerList.addCustomer(Customer("Zehrah", 50.0));
    customerList.addCustomer(Customer("Riya", 30.0));
    customerList.addCustomer(Customer("Shreya", 20.0));

    // Displaying customer details using subscript operator
    cout << "Customer Details:" << endl;
    for (size_t i = 0; i < customerList.size(); ++i) {
        customerList[i].display(); // Access customers using []
    }

    return 0;
}

