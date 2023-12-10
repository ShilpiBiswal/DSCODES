#include<stdio.h>
void merge(int a[],int low,int mid,int high);
void mergesort(int a[],int low,int high);
void mergesort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }

}
void merge(int a[],int low,int mid,int high){
    int i,j,k,r,b[90];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=high){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(r=low;r<k;r++){
        a[r]=b[r];
    }
}
int main(){
    int i,n;
    printf("\nEnter number of members : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter terms of array : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("\nSorted Array : ");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}