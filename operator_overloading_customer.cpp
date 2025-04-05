#include <iostream>
#include <string>
using namespace std;
class Customer {
    string name;
    double billAmount;
public:
    Customer() : name(""), billAmount(0.0) {}
    Customer(string n, double amount) : name(n), billAmount(amount) {}
    // Overload + operator to combine bills
    Customer operator+(const Customer& other) const {
        return Customer(name + " & " + other.name, billAmount + other.billAmount);
    }
    // Overload - operator to subtract bills
    Customer operator-(const Customer& other) const {
        return Customer(name, billAmount - other.billAmount);
    }
    // Overload * operator to multiply bill by a factor
    Customer operator*(double factor) const {
        return Customer(name, billAmount * factor);
    }
    // Overload ++ operator to add a service charge
    Customer& operator++() {
        billAmount += 10.0; 
        return *this;
    }
    // Overload ++ operator to add a service charge
    Customer operator++(int) {
        Customer temp = *this; 
        billAmount += 10.0; 
        return temp; 
    }
    // Overload -- operator  to apply discount
    Customer& operator--() {
        billAmount -= 5.0; 
        return *this;
    }
    // Overload -- operator to apply discount
    Customer operator--(int) {
        Customer temp = *this; 
        billAmount -= 5.0; 
        return temp; 
    }
    void display() const {
        cout << "Customer Name: " << name << ", Bill Amount:" << billAmount << endl;
    }
};
int main() {
    Customer customer1("Zehrah", 80.0);
    Customer customer2("Riya", 50.0);
    cout << "Initial Customers' Details:" << endl;
    customer1.display();
    customer2.display();
    // Increment bill for customer1
    ++customer1; 
    cout << "\nAfter Service Charge for Zehrah:" << endl;
    customer1.display();
    // Combining bills of two customers
    Customer totalBill = customer1 + customer2;
    cout << "\nTotal Bill for Both Customers:" << endl;
    totalBill.display();
    // Subtracting Riya's bill from Zehrah's bill
    Customer difference = customer1 - customer2;
    cout << "\nDifference in Bills:" << endl;
    difference.display();
    // Multiplying bill by a factor
    Customer multipliedBill = customer1 * 2.0;
    cout << "\nZehrah's Bill After Doubling:" << endl;
    multipliedBill.display();
    // Resetting the bill amount for zehrah
    customer1--;
    cout << "\nAfter Applying Discount to Zehrah's Bill:" << endl;
    customer1.display();
    // Resetting the bill amount for customer2 
    --customer2;
    cout << "\nAfter Applying Discount to Riya's Bill:" << endl;
    customer2.display();
    return 0;
}

