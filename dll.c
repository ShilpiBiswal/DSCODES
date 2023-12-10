#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* right;
    int data;
    struct node* left;
}; 
struct node* head;
struct node* getnode(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("\nEnter data:");
    scanf("%d",&data);
    newnode->right=NULL;
    newnode->data=data;
    newnode->left=NULL;
    return newnode;
}
void createnode(int n)
{
    struct node* newnode,*temp;
    for(int i=0;i<n;i++)
    {
        newnode=getnode();
        if(head==NULL){
            newnode->right=head;
            head=newnode;
        }
        else{
            temp=head;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right=newnode;
        }
    }
}
void insertbeg()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        printf("\nList empty");
    }
    else{
       printf("\nEnter data:");
       scanf("%d",&ptr->data);
       ptr->right=head;
       head=ptr;
    }
}
void insertend()
{
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        printf("\nOverflow");
    }
    else{
        printf("\nEnter data:");
        scanf("%d",&ptr->data);
        if(head==NULL){
            ptr->right=head;
            head=ptr;
            printf("\nOnly Node Inserted in Empty List");
        }
        else{
            temp=head;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right=ptr;
            ptr->left=temp;
            ptr->right=NULL;
            printf("\nNode inserted at end of list");
        }
    }
}
void randomins(){
    int loc;
    struct node*ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        printf("\nCannot Insert");
    }
    else{
        printf("\nEnter data : ");
        scanf("%d",&ptr->data);
        printf("\nenter location where node is to be inserted : ");
        scanf("%d",&loc);
        temp=head;
        for(int i=1;i<loc-1;i++){
            temp=temp->right;
            if(temp==NULL){
                printf("\nLocation not found, cannot insert.");
            }
        }
        ptr->right=temp->right;
        temp->right=ptr;
        temp->right->left=ptr;
    }
}
void deletebeg(){
    struct node *ptr;
    if(head==NULL){
        printf("\nList Empty");
    }
    else{
        ptr=head;
        head=ptr->right;
        free(ptr);
        printf("\nNode deleted from beginning");
    }
}
void deletend(){
    struct node *ptr,*temp;
    if(head==NULL){
        printf("\nOverflow");
    }
    else{
        ptr=head;
        while(ptr->right!=NULL){
            temp=ptr;
            ptr=ptr->right;
        }
        temp->right=NULL;
        temp->left=ptr->left;
        free(ptr);
        printf("\nNode deleted from end");
    }
}
void randomdel(){
    struct node *ptr,*temp;
    int loc;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter location to perform deletion : ");
    scanf("%d",&loc);
    if(ptr==NULL){
        printf("\nList Empty");
    }
    else{
        temp=head;
        for(int i=1;i<loc-1;i++){
        temp=temp->right;
        if(temp==NULL){
            printf("\nCannot delete");
        }
        
      } 
      ptr=temp->right;
      temp->right=ptr->right;
      free(ptr);

    }
}
struct node* concatenate(struct node *a, struct node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    struct node *temp=a;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    temp->right=b;
    return a;

}
void reverse(){
    struct node* temp=NULL;
    struct node* current =head;
    while(current!=NULL){
        temp=current->left;
        current->left=current->right;
        current->right=temp;
        current=current->left;
    }
    if(temp!=NULL){
        head=temp->left;
    }
}
void display(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("\nList Empty");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->right;
        }
    }
}
int main()
{
    int opt,n;
    struct node *a,*b;
    while(1){
        printf("\n1.Create list");
        printf("\n2.Insert element at its beginning");
        printf("\n3.Insert element at its end");
        printf("\n4.Insert element at random location");
        printf("\n5.Delete from beginning");
        printf("\n6.Delete from ending");
        printf("\n7.Delete from a random location");
        printf("\n8.Concatenate");
        printf("\n9.Display");
        printf("\n10.Quit");
        printf("\nEnter an option : ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
            printf("Enter number of terms in double list : ");
            scanf("%d",&n);
            createnode(n);
            break;

            case 2:
            insertbeg();
            break;

            case 3:
            insertend();
            break;

            case 4:
            randomins();
            break;

            case 5:
            deletebeg();
            break;

            case 6:
            deletend();
            break;

            case 7:
            randomdel();
            break;

            case 8:
            printf("\nenter number of terms in list a :");
            scanf("%d",&n);
            createnode(n);
            printf("\nenter number of terms in list b :");
            scanf("%d",&n);
            createnode(n);
            concatenate(a,b);
            break;

            case 9:
            display();
            break;

            case 10:
            printf("\nThank You");
            return 0;

            default:
            printf("\nEnter a valid option : ");

        }
    }
    return 0;

}