#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *getnode(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data:");
    scanf("%d",&newnode->data);
  
    newnode->next=NULL;
    return newnode;
}
void createlist(int n)
{
    struct node *newnode,*temp;
    for(int i=0;i<n;i++){
        newnode=getnode();
        if(head==NULL){
            newnode->next=head;
            head=newnode;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    
}
void insertbeg(){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\nList empty");
    }
    else{
        printf("enter data:");
        scanf("%d",&ptr->data);
        
        ptr->next=head;
        head=ptr;
        printf("\nNode inserted");
    }
}
void insertend(){
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\nOverflow");
    }
    else{
        printf("Enter data:");
        scanf("%d",&ptr->data);
     
        if(head==NULL)
        {
        ptr->next=NULL;
        head=ptr;
        printf("\nonly node inserted");
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("node inserted at end");
        }
    }
}
void randomin(){
    int loc;
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data:");
    scanf("%d",&ptr->data);
    printf("\nenter location where node is to be inserted : ");
    scanf("%d",&loc);
     if(ptr==NULL){
        printf("\nList empty");
    }
    else{
        temp=head;
        for(int i=0;i<loc-1;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("\nCannot Insert");
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("\nNode Inserted");

    }

}
void randomdel(){
    int loc;
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter location where node is to be deleted : ");
    scanf("%d",&loc);
     if(ptr==NULL){
        printf("\nList empty");
    }
    else{
        temp=head;
        for(int i=1;i<loc-1;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("\nCannot delete");
            }
        }
        ptr=temp->next;
        temp->next=ptr->next;
        free(ptr);
        printf("\nNode Deleted");

    }

}
void deletebeg()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node*));
     if(ptr==NULL){
        printf("\nList empty");
    }
    else{
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("\nNode deleted from beginning");
    }
}
void deletend()
{
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        printf("\nOverflow");
    }
    else{
        if(head==NULL){
            printf("List empty");
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                temp=ptr;
                ptr=ptr->next;
            }
            temp->next=NULL;
            free(ptr);
            printf("\nNode deleted from the end");
        }
    }
}
struct node* concatenate(struct node *a, struct node *b) {
    if (a == NULL) {
        return b; // If 'a' is empty but 'b' is not, return 'b'
    }

    if (b == NULL) {
        return a; // If 'b' is empty but 'a' is not, return 'a'
    }

    struct node *temp = a;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = b;
    return a; // Return 'a' as the head of the concatenated list
}
struct node *reverse(struct node* head){
    struct node* next=NULL;
    struct node* current=head;
    struct node* prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}


void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("\nList empty, nothing to display");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
           
        }
    }
}
int main(){
    int opt,n;
    struct node *a,*b;
    while(1){
        printf("\n1.Create List");
        printf("\n2.Insert at beginning");
        printf("\n3.Insert at end");
        printf("\n4.Insert at random");
        printf("\n5.Delete from beginning");
        printf("\n6.Delete from end");
        printf("\n7.Delete at random");
        printf("\n8.Concatenate");
        printf("\n9.Display");
        printf("\n10.Reverse");
        printf("\nenter valid option : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            printf("\nenter number of terms in list : ");
            scanf("%d",&n);
            createlist(n);
            break;
            
            case 2:
            insertbeg();
            break;
            
            case 3:
            insertend();
            break;

            case 4:
            randomin();
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
            
            printf("\nenter number of terms in list a : ");
            scanf("%d",&n);
            createlist(n);
            printf("\nenter number of terms in list b : ");
            scanf("%d",&n);
            createlist(n);
            concatenate(a,b);
            display();
            break;

            case 9:
            display();
            break;
            
            case 10:
            head=reverse(head);
            display();
            return 0;
            
            default:
            printf("\nOption Invalid, Try again");
        }
    }
    return 0;
}