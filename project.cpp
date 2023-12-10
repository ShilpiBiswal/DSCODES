#include<iostream>
#include<time.h>
using namespace std;
class ticket
{
    char moviename;
    int time;
    int date;
    int seatno;
public:
    void display(){
        cout<<"movie name: "<<moviename;
        cout<<"\ntime: "<<time;
        cout<<"\ndate: "<<date;
        cout<<"\nseatno: "<<seatno;
    }

};
