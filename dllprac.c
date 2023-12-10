#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* right;
    int data;
    struct node*left;
};
struct node* head;
struct node *createnode()
{
    struct node* newnode;
    int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d",&data);
    newnode->right=NULL;
    newnode->data=data;
    newnode->left=NULL;
    return newnode;
}
struct node* createlist(int n)
{
    struct node* newnode,*temp;
    for(int i=0;i<n;i++){
        newnode=createnode();
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
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\nList empty");
    }
    else{
        printf("\nEnter data : ");
        scanf("%d",&ptr->data);
        ptr->right=head;
        head=ptr;
        printf("\nNode inserted");
    }
}
void insertend()
{
    struct node* ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\nOverflow");
    }
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(head==NULL){
            ptr->right=head;
            head=ptr;
            printf("\nOnly node inserted in list");
        }
        else{
            temp=head;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right=ptr;
            ptr->right=NULL;
        }
    }
}
void randinsert()
{
    int loc;
    struct node *ptr,*temp;
     ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\nOverflow");
    }
    else{
        printf("\nEnter location where node is to be inserted : ");
        scanf("%d",&loc);
        printf("\nEnter data : ");
        scanf("%d",&ptr->data);
        temp=head;
        for(int i=0;i<loc;i++){
            while(temp->right!=NULL){
                temp=temp->right;
            }
        }
        ptr->right=temp->right;
        temp->right=ptr;
        temp->right->left=ptr;
    }
}
void begdelete()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
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
void endelete()
{
     struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        printf("\nOverflow");
    }
    else{
        ptr=head;
        while(temp->right!=NULL){
            temp=ptr;
            ptr=ptr->right;
        }
        temp->right=NULL;
        temp->left=ptr->left;
        free(ptr);
        printf("\nNode deleted from end");
    }

}
void randelete()
{
    int loc;
    struct node *ptr,*temp;
     ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\nOverflow");
    }
    else{
        printf("\nEnter location : ");
        scanf("%d",&loc);
        printf("\nEnter data : ");
        scanf("%d",&ptr->data);
        temp=head;
        for(int i=0;i<loc;i++){
            while(temp->right!=NULL){
                temp=temp->right;
            }
        }
        ptr=temp->right;
        temp->right=ptr->right;
        free(ptr);
    }

}
struct node* concatenate(struct node* a, struct node* b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    struct node* temp=a;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    temp->right=b;
    return a;
}
void display()
{
    struct node* temp;
    temp=head;
    while(temp->right!=NULL){
        printf("%d\t",temp->data);
        temp=temp->right;
    }
}