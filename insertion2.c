#include<stdio.h>
void insertion(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int n,i;
    printf("\nEnter number of members : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nAfter Insertion Sorting : ");
    insertion(a,n);
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}