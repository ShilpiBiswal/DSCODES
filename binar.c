#include<stdio.h>
int binary(int a[],int n,int key)
{
    int l,r,mid;
    l=0;
    r=n-1;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>key){
            r=mid-1;
        }
        else if(a[mid]<key){
            l=mid+1;
        }
    }
    return -1;
}
int main(){
    int n,key;
    printf("\nEnter number of items : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter items : ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter item to be searched : ");
    scanf("%d",&key);
    int result=binary(a,n,key);
    if(result!=-1){
        printf("\nValue found at %d ",result);
    }
    else{
        printf("\nValue not found in list");
    }

}