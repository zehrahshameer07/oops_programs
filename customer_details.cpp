//Program to enter and display customer details using class and object
#include<iostream>
#include<string>
using namespace std;
class Customer
{
	public:
		string name,item,ph_no,pincode;
		int age,no_of_items;
		float price;
		void getdetails()
		{
			cout<<"Enter customer name:"<<endl;
			getline(cin,name);
			cout<<"Enter customer age:"<<endl;
			cin>>age;
			cout<<"Enter number of items ordered:"<<endl;
			cin>>no_of_items;
			cout<<"Enter phone number of customer:"<<endl;
			getline(cin,ph_no);
			cout<<"Enter the pincode of the customer's place:"<<endl;
			getline(cin,pincode);
			cout<<"Enter the item ordered:"<<endl;
			getline(cin,item);
			cout<<"Enter the total price:"<<endl;
			cin>>price;
		}
		void displaydetails()
		{
			cout<<"Customer Name:"<<name<<endl;
			cout<<"Customer Age:"<<age<<endl;
			cout<<"Number Of Items Ordered:"<<no_of_items<<endl;
			cout<<"Phone Number:"<<ph_no<<endl;
			cout<<"Pincode:"<<pincode<<endl;
			cout<<"Item Ordered:"<<item<<endl;
			cout<<"Total Amount:"<<price<<endl;
			cout<<"Discounted Amount:"<<calculatediscount()<<endl;
		}
		float calculatediscount()
		{
			if(price>=1000)
			{
				price=price-(price*0.20);
				return price;
			}
			return price;
		}		
};
int main()
{
	Customer customer;
	customer.getdetails();
	cout<<"\nCustomer Details:\n";
	customer.displaydetails();
	return 0;
}
