#include<iostream>
#include<string>
using namespace std;
class Customer
{
public:
    string name, item, ph_no, pincode;
    int age, no_of_items;
    float price;
    Customer() : name(""), item(""), ph_no(""), pincode(""), age(0), no_of_items(0), price(0.0) {}
    Customer(string n, int a, int noi, string ph, string pin, string it, float pr)
        : name(n), age(a), no_of_items(noi), ph_no(ph), pincode(pin), item(it), price(pr) {}
    void getdetails()
    {
        cout << "Enter customer name:" << endl;
        getline(cin, name);
        cout << "Enter customer age:" << endl;
        cin >> age;
        cout << "Enter number of items ordered:" << endl;
        cin >> no_of_items;
        cout << "Enter phone number of customer:" << endl;
        cin.ignore();
        getline(cin, ph_no);
        cout << "Enter the pincode of the customer's place:" << endl;
        getline(cin, pincode);
        cout << "Enter the item ordered:" << endl;
        getline(cin, item);
        cout << "Enter the total price:" << endl;
        cin >> price;
    }
    void getdetails(string n, int a, int noi, string ph, string pin, string it, float pr)
    {
        name = n;
        age = a;
        no_of_items = noi;
        ph_no = ph;
        pincode = pin;
        item = it;
        price = pr;
    }
    void displaydetails()
    {
        cout << "Customer Name: " << name << endl;
        cout << "Customer Age: " << age << endl;
        cout << "Number Of Items Ordered: " << no_of_items << endl;
        cout << "Phone Number: " << ph_no << endl;
        cout << "Pincode: " << pincode << endl;
        cout << "Item Ordered: " << item << endl;
        cout << "Total Amount: " << price << endl;
        cout << "Discounted Amount: " << calculatediscount() << endl;
    }
    float calculatediscount()
    {
        if(price >= 1000)
        {
            return price - (price * 0.20);
        }
        return price;
    }
};
int main()
{
    Customer customer1;
    customer1.getdetails("John Smith", 30, 1, "9086757890", "560098", "Cake", 1200.0);
    cout << "\nCustomer Details:\n";
    customer1.displaydetails();
    Customer customer2;
    cout << "\nEnter details for another customer:\n";
    customer2.getdetails();
    cout << "\nCustomer Details:\n";
    customer2.displaydetails();
    return 0;
}


