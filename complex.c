#include<stdio.h>
struct complex
{
    float r;
    float i;
};
int main()
{
    struct complex c1,c2,c3;
    
    printf("enter real part of c1:");
    scanf("%f",&c1.r);
    printf("enter img part of c1:");
    scanf("%f",&c1.i);
    printf("enter real part of c2:");
    scanf("%f",&c2.r);
    printf("enter img part of c2:");
    scanf("%f",&c2.i);
    c3.r=c1.r+c2.r;
    c3.i=c1.i+c2.i;
    printf("the addition between two complex numbers gives:");
    if(c3.i>=0)
    {
        printf("%.2f+%.2fi \n",c3.r,c3.i);

    }
    else{
        printf("%.2f %.2fi \n",c3.r,c3.i);
    }


}