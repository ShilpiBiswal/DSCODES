#include<iostream>
using namespace std;
class Student
{protected:
    int rn;
public:
    void getno(int a){
        rn=a;
    }
    void putno(){
        cout<<"roll no : "<<rn<<"\n";
    }
    
};
class Marks:public Student
{
    protected:
    float sub1,sub2;
    public:
    void getmarks(float a, float b)
    {
        sub1=a;
        sub2=b;
    }
    void putmarks(){
        cout<<"\nMarks in subject 1: "<<sub1;
        cout<<"\nMarks in subject 2: "<<sub2;
    }
};
class Result : public Marks
{
    protected:
    float total;
    public:
    void display(){
        total=sub1+sub2;
        putno();
        putmarks();
        
    }
};
int main()
{
    Result stu1;
    stu1.getno(11);
    stu1.getmarks(89.0,63.0);
    stu1.display();
}