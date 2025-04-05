#include<iostream>
#include<string>
using namespace std;
class Customer{
	private:
		int age;
		string name,email;
	public:
		Customer(){
			name="Unknown";
			age=0;
			email="None";
		}
		Customer(string name,int age,string email){
			this->name = name;
            this->age = age;
            this->email = email;
		}
		void display() const{
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "E-mail: " << email << endl;
		}		
};
int main() {
    const int numCustomers = 3;
    Customer customers[numCustomers];
    cout << "Customer Details (Default):" << endl;
    for (int i = 0; i < numCustomers; i++) {
        cout << "Customer " << i + 1 << ":" << endl;
        customers[i].display();
        cout << endl;
    }
    Customer customersWithDetails[numCustomers] = {
        Customer("Zehrah Shameer", 30, "zehrah.shameer@gmail.com"),
        Customer("Simran Rao", 25, "simran.rao@gmail.com"),
        Customer("Ramona Mary", 40, "ramona.mary@gmail.com")
    };
    cout << "Customer Details (Initialized):" << endl;
    for (int i = 0; i < numCustomers; ++i) {
        cout << "Customer " << i + 1 << ":" << endl;
        customersWithDetails[i].display();
        cout << endl;
    }
    return 0;
}
