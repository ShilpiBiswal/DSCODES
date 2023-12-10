/*to create a shopping cart using 
classes and objects that contains 
information like itemname, itemid
itemprice and allows users to perform 
operations like adding, deleting and
displaying total value of order*/

#include<iostream>
using namespace std;
class shopping
{
    string itemname[20];
    int itemid[20];
    int itemprice[20];
    int count;
public:
     void cnt()
     {
        count=0;
     }
     void additem();
     void removeitem();
     void displaysum();
     void displayall();

};
void shopping::additem(){
    cout<<"enter item name:"<<endl;
    cin>>itemname[count];
    cout<<"enter item id:"<<endl;
    cin>>itemid[count];
    cout<<"enter price of item: Rs "<<endl;
    cin>>itemprice[count];
    count++;
}
void shopping::removeitem(){
    int z;
    cout<<"enter id of item to be deleted: "<<endl;
    cin>>z;
    for(int i=0;i<count;i++){
        if (itemid[i]==itemid[z])
        {
            itemid[i]=0;
        }
    }
}
void shopping::displaysum(){
    int sum=0;
    for(int i=0;i<count;i++){
        sum=sum+itemprice[i];

    }
    cout<<"the total value is "<<sum<<endl;
}
void shopping::displayall(){
    cout<<"id"   "name"    "price";
    for(int i=0;i<count;i++)
    {
        cout<<itemid[i]  <<itemname[i]  <<itemprice[i];
    }
}
int main()
{
    shopping order;
    order.cnt();
    int d;
    while(true)
    {
        cout<<"Welcome to shopping cart";
        cout<<"You can perform below operations";
        cout<<"\n1.Add items to your cart";
        cout<<"\n2.Remove item from your cart";
        cout<<"\n3.Display total value";
        cout<<"\n4.Display all items";
        cout<<"\n5.Quit";
        cout<<"enter your choice:"<<endl;
        cin>>d;

        switch(d)
        {
            case 1 :
              order.additem();
              break;
            case 2:
             order.removeitem();
             break;
            case 3:
              order.displaysum();
              break;
            case 4:
               order.displayall();
               break;
            default:
               cout<<"enter valid choice";
               break;

        }

    }

}

