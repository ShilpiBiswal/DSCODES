#include<stdio.h>
#include<stdlib.h>
struct treenode
{
    struct treenode* right;
    int data;
    struct treenode* left;
};
struct treenode *createnode(int value){
    struct treenode *newnode;
    newnode=(struct treenode*)malloc(sizeof(struct treenode*));
    newnode->right=NULL;
    newnode->data=value;
    newnode->left=NULL;
    return newnode;
}
struct treenode *insertnode(struct treenode* root, int value)
{
    if(root==NULL){
        return createnode(value);
    }
    if(value>root->data){
        root->right=insertnode(root->right,value);
    }
    else if(value<root->data){
       root->left= insertnode(root->left,value);
    }
    return root;
}
void inorder(struct treenode *root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(struct treenode *root)
{
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct treenode*root)
{
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
struct treenode*searchnode(struct treenode*root,int value)
{
    if(root==NULL||root->data==value){
        return root;
    }
    if(value>root->data){
        return searchnode(root->right,value);
    }
    else if(value<root->data){
        return searchnode(root->left,value);
    }
}
int main()
{
    struct treenode* root=NULL;
    int opt,value,node;
    while(1)
    {
        printf("\n1.Insert Nodes");
        printf("\n2.Inorder Traversal");
        printf("\n3.Preorder Traversal");
        printf("\n4.Postorder Traversal");
        printf("\n5.Search for Node");
        printf("\n6.Quit");
        printf("\nEnter option : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            printf("enter value to be inserted : ");
            scanf("%d",&value);
            root=insertnode(root,value);
            break;

            case 2:
            printf("\nInorder Traversal : ");
            inorder(root);
            break;

            case 3:
            printf("\nPreorder Traversal : ");
            preorder(root);
            break;

            case 4:
            printf("\nPostorder Traversal : ");
            postorder(root);
            break;

            case 5:
            printf("\nEnter node to be searched for : ");
            scanf("%d",&node);
            if(searchnode(root,node)==NULL){
                printf("\nValue not found in tree");
            }
            else{
                printf("\nValue found in tree");
            }
            break;


            case 6:
            printf("\nThank you");
            return 0;

            default:
            printf("\nenter valid option please");

        }
        
    }
    return 0;
}