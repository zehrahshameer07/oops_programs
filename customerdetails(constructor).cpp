#include <iostream>
using namespace std;
class cusInfo
{

    int cusid;
    string cusname,item,ph_no,pincode;
    int age,no_of_items;
    float price;
    public:
    cusInfo()
    {
        cusid=0;
        cusname=" ";
        item=" ";
        ph_no=" ";
        pincode=" ";
        age=0;
        no_of_items=0;
        price=0.0;
    }
    cusInfo(int cusid, string cusname, string item, string ph_no, string pincode, int age, int no_of_items, float price)
    {
        this->cusid= cusid;
        this->cusname= cusname;
        this->item= item;
        this->ph_no= ph_no;
        this->pincode= pincode;
        this->age= age;
        this->no_of_items= no_of_items;
        this->price= price;
    }
    cusInfo(cusInfo &X)
    {
    cusid= X.cusid;
    cusname= X.cusname;
    item= X.item;
    ph_no= X.ph_no;
    pincode= X.pincode;
    age= X.age;
    no_of_items= X.no_of_items;
    price= X.price;
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
    void putdata();
};
void cusInfo::putdata()
{
        cout<<"Customer ID:"<<cusid<<endl;
    	cout<<"Customer Name:"<<cusname<<endl;
		cout<<"Customer Age:"<<age<<endl;
		cout<<"Number Of Items Ordered:"<<no_of_items<<endl;
		cout<<"Phone Number:"<<ph_no<<endl;
		cout<<"Pincode:"<<pincode<<endl;
		cout<<"Item Ordered:"<<item<<endl;
		cout<<"Total Amount:"<<price<<endl;
		cout<<"Discounted Amount:"<<calculatediscount()<<endl;
}
int main()
{
    cusInfo X(1, "John","cake","908746456","23465",20,1,1500);
    X.putdata();
    return 0;
}
