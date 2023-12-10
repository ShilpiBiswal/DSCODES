#include<iostream>
using namespace std;
int factorial(int n,int fac=1){
    if(n==0||n==1){
        return 1;
    }
    else{
        for(int i=1;i<=n;i++){
           fac=fac*i;
            
        }
        return fac;
    }
}
int main(){
    int r=factorial(3,1);
    cout<<r;

}