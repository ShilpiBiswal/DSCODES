#include <stdio.h>

int main()
{
    int i,j,n,temp;
    printf("enter number of members:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;

    }
    printf("display sorted array");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}