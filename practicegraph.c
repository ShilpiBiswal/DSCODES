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
struct graph* creategraph(int numofvertices){
    struct graph* newgraph;
    newgraph=(struct graph*)malloc(sizeof(struct graph));
    newgraph->numvertices=numofvertices;
    newgraph->adjacencylist=(struct node**)malloc(numofvertices*sizeof(struct node*));
    newgraph->visited=(int*)malloc(numofvertices*sizeof(int*));
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
void deletenode(struct graph*newgraph,int value)
{
    struct node*temp,*prev;
    for(int i=0;i<newgraph->numvertices;i++){
        temp=newgraph->adjacencylist[i];
        prev=NULL;
        while(temp!=NULL){
            if(temp->data==value)
            {
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
void dfs(struct graph* newgraph,int start){
    struct node* temp;
    temp=newgraph->adjacencylist[start];
    newgraph->visited[start]=1;
    printf("\nValue visited in the graph is %d ",start);
    while(temp!=NULL){
        int adjnode=temp->data;
        if(newgraph->visited[adjnode]==0){
            dfs(newgraph,adjnode);
        }
        temp=temp->next;
    }
    
}
void bfs(struct graph* newgraph, int start) {
    int* queue = (int*)malloc(newgraph->numvertices * sizeof(int));
    int front = 0, rear = 0;

    queue[rear] = start;
    newgraph->visited[start] = 1;
    printf("\nValue visited is %d", start);

    while (front <= rear) {
        int current = queue[front++];
        struct node* temp = newgraph->adjacencylist[current];
        while (temp != NULL) {
            int adjnode = temp->data;
            if (newgraph->visited[adjnode] == 0) {
                queue[++rear] = adjnode;
                newgraph->visited[adjnode] = 1;
                printf("\nVisited node is %d", adjnode);
            }
            temp = temp->next;
        }
    }

    free(queue); // Free the queue after its usage
}

void display(struct graph* newgraph){
    for(int i=0;i<newgraph->numvertices;i++){
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
    struct graph* newgraph=NULL;
    int vertices,src,dest,nodetodelete;
    int edges;
    printf("\nEnter number of vertices : ");
    scanf("%d",&vertices);
    newgraph=creategraph(vertices);
    printf("\nEnter number of edges : ");
    scanf("%d",&edges);
    for(int i=0;i<edges;i++){
        printf("\nEnter source : ");
        scanf("%d",&src);
        printf("\nEnter destination : ");
        scanf("%d",&dest);
        addedge(newgraph,src,dest);
    }
    display(newgraph);
    printf("\nEnter node to delete : ");
    scanf("%d",&nodetodelete);
    deletenode(newgraph,nodetodelete);
    display(newgraph);
    int start;
    printf("\nenter start for bfs and dfs : ");
    scanf("%d",&start);
    dfs(newgraph,start);
    bfs(newgraph,start);

}
