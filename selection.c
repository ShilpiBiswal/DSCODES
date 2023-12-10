#include<stdio.h>
void selection(int a[],int n){
    int i,j,temp,min;
    
    for( i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[min]<a[j]){
                min=j;
            }
           
        }
        if(min!=i){
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;

        }
        
    }
}
int main()
{
    int i,n;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nAfter Selection Sorting : ");
    selection(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}