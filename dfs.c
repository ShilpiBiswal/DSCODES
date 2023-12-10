#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct graph
{
    int numvertices;
    struct node** adjacencylist;
    int* visited;
};
struct node* createnode(int value){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
struct graph* creategraph(int numofvertices)
{
    struct graph* newgraph;
    newgraph=(struct graph*)malloc(sizeof(struct graph));
    newgraph->numvertices=numofvertices;
    newgraph->adjacencylist=(struct node**)malloc(numofvertices*sizeof(struct node*));
    newgraph->visited = (int*)malloc(numofvertices * sizeof(int));
    for(int i=0;i<numofvertices;i++){
        newgraph->adjacencylist[i]=NULL;
        newgraph->visited[i]=0;
    }
    return newgraph;
}
void addedge(struct graph* newgraph,int src,int dest)
{
    struct node* newnode=createnode(dest);
    newnode->next=newgraph->adjacencylist[src];
    newgraph->adjacencylist[src]=newnode;

    newnode=createnode(src);
    newnode->next=newgraph->adjacencylist[dest];
    newgraph->adjacencylist[dest]=newnode;
}
void deletenode(struct graph *newgraph, int node)
{
    struct node* temp,*prev;
    for(int i=0;i<newgraph->numvertices;i++)
    {
        temp=newgraph->adjacencylist[i];
        prev=NULL;
        while(temp!=NULL){
            if(temp->data==node){
                if(prev==NULL){
                    newgraph->adjacencylist[i]=temp->next;
                    free(temp);
                    temp=newgraph->adjacencylist[i];
                }
                else{
                    prev->next=temp->next;
                    free(temp);
                    temp=prev->next;
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
    }
}
void dfs(struct graph* newgraph,int start)
{
    struct node* temp=newgraph->adjacencylist[start];
    newgraph->visited[start]=1;
    printf("Visited node : %d",start);
    while(temp!=NULL){
        int adjnode=temp->data;
        if(newgraph->visited[adjnode]==0){
            dfs(newgraph,adjnode);
        }
        temp=temp->next;

    }
}
void display(struct graph* newgraph)
{
    for(int i=0;i<newgraph->numvertices;i++){
        printf("Adjacency list of vertex %d: ", i);
        struct node* temp=newgraph->adjacencylist[i];
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    
    }
}
int main()
{
    int vertices,edges,nodetodelete;
    int src,dest;
    printf("\nEnter number of vertices : ");
    scanf("%d",&vertices);
    printf("\nEnter number of edges : ");
    scanf("%d",&edges);
    struct graph* newgraph=creategraph(vertices);
    for(int i=0;i<edges;i++)
    {
        printf("\nEnter source : ");
        scanf("%d",&src);
        printf("\nEnter destination : ");
        scanf("%d",&dest);
        addedge(newgraph,src,dest);
        
    }
    
    display(newgraph);
    int startnode=1;
    dfs(newgraph,startnode);
    printf("\nEnter node to be deleted : ");
    scanf("%d",&nodetodelete);
    deletenode(newgraph,nodetodelete);
    printf("\nAfter deleting node : ");
    display(newgraph);
    
}