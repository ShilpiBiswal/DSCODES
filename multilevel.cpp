#include <iostream>
using namespace std;

class Item {
protected:
    string title; // You might want to use string instead of int for the title
    int price;
};

class Sale {
protected:
    int sm1, sm2, sm3;
};

class hwitem : public Item, public Sale { // Using public inheritance for both base classes
public:
    void getdata() {
        cout << "Enter title of hardware item:" << endl;
        cin >> title;
        cout << "Enter price of hardware item:" << endl;
        cin >> price;
        cout << "Enter sales figures of three months for hardware item:" << endl;
        cin >> sm1 >> sm2 >> sm3;
    }

    void displaydata() {
        cout << "Hardware Title: " << title << "\nHardware Price: " << price;
        printf("\nSales Figures:\n1st month %d\n2nd month %d\n3rd month %d\n", sm1, sm2, sm3);
    }
};

class switem : public Item, public Sale { // Using public inheritance for both base classes
public:
    void getdata() {
        cout << "Enter title of software item:" << endl;
        cin >> title;
        cout << "Enter price of software item:" << endl;
        cin >> price;
        cout << "Enter sales figures of three months for software item:" << endl;
        cin >> sm1 >> sm2 >> sm3;
    }

    void displaydata() {
        cout << "Software Title: " << title << "\nSoftware Price: " << price;
        printf("\nSales Figures:\n1st month %d\n2nd month %d\n3rd month %d\n", sm1, sm2, sm3);
    }
};

int main() {
    hwitem hw1;
    switem sw1;
    int option;
    while(true){
        cout<<"1.Check Hardware Sales";
        cout<<"\n2.Check Software Sales";
        cout<<"\n3.Quit";
        cout<<"\nEnter option:"<<endl;
        cin>>option;
        switch(option){
            case 1:
                hw1.getdata();
                hw1.displaydata();
                break;
            case 2:
                sw1.getdata();
                sw1.displaydata();
                break;
            case 3:
                cout<<"\nThank You";
                return 0;
            dafault:
                cout<<"Option Invalid";
                
        }
    }
}
