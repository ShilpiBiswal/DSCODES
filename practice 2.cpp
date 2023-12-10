#include <iostream>
using namespace std;
int sum(int x, int y)
{
    int c;
    c=x+y;
    return c;
}
int main()
{
    int a, b;
    cout<<"enter first number"<<endl;
    cin>>a;
    cout<<"enter second number"<<endl;
    cin>>b;
    cout<<"the sum of the two numbers is"<<sum(a,b);
    return 0;
}