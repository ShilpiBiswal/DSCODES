#include <stdio.h>
#include<stdlib.h>
struct treenode
{
    struct treenode *right;
    int data;
    struct treenode *left;
};

struct treenode *createnode(int value)
{
    struct treenode *newnode;
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
    
}
struct treenode *insertleft(struct treenode *root, int value){
    root->left=createnode(value);
    return root->left;
}
struct treenode *insertright(struct treenode *root, int value){
    root->right=createnode(value);
    return root->right;
}
void preorder(struct treenode *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct treenode *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
void postorder(struct treenode *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
        
    }
}
int main(){
    struct treenode *root=createnode(20);
    insertleft(root,18);
    insertright(root,22);
    insertleft(root->left,15);
    insertright(root->left,19);
    insertleft(root->right,21);
    insertright(root->right,26);
    printf("preorder traversal is : \n");
    preorder(root);
    printf("inorder traversal is : \n");
    preorder(root);
    printf("postorder traversal is : \n");
    preorder(root);
    
}