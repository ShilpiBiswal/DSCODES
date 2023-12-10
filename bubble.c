#include<stdio.h>
void bubble(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j+1]<a[j]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main()
{
    int n,i;
    printf("\nenter number of terms : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter terms : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nAfter bubble Sorting : ");
    bubble(a,n);
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}