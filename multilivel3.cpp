#include<iostream>
using namespace std;
class Person
{
    protected:
    string name;
    int age;
    public:
    void getdata()
    {
        cout<<"\nEnter name : ";
        cin>>name;
        cout<<"\nEnter age : ";
        cin>>age;
    }
    void putdata()
    {
        cout<<"Name : "<<name;
        cout<<"\nAge : "<<age;
        
    }
};
class Student : public Person
{
    protected:
    int prn;
    string schoolname;
    public:
    void getdata()
    {
        Person::getdata();
        cout<<"\nEnter prn : ";
        cin>>prn;
        cout<<"\nEnter schoolname : ";
        cin>>schoolname;
    }
    void putdata()
    {
        Person::putdata();
        cout<<"\nPRN : "<<prn;
        cout<<"\nSchoolName : "<<schoolname;
    }
    
    
};
class Employee : public Person
{
    protected:
    int empid;
    string compname;
    public:
    void getdata()
    {
        Person::getdata();
        cout<<"\nEnter empid : ";
        cin>>empid;
        cout<<"\nEnter compname : ";
        cin>>compname;
    }
    void putdata()
    {
        Person::putdata();
        cout<<"\nEmp_id : "<<empid;
        cout<<"\nCompany_Name : "<<compname;
    }
};
int main()
{
    Student s1;
    s1.getdata();
    s1.putdata();
    Employee e1;
    e1.getdata();
    e1.putdata();
}