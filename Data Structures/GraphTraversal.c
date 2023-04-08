#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n;
void breadthFirstSearch(int adj[MAX][MAX], int start) {
    int visited[MAX]={0},queue[MAX],rear=-1,front=-1,i;
    queue[++rear]=start;
    visited[start]=1;
    printf("BFS: ");
    while(rear!=front) {
        start=queue[++front];
        printf("%c ",start+65);
        for(i=0;i<n;i++) {
            if(adj[start][i]==1 && visited[i]==0) {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
void depthFirstSearch(int adj[MAX][MAX], int start) {
    int visited[MAX]={0},stack[MAX],top=-1,i;
    stack[++top]=start;
    visited[start]=1;
    printf("DFS: ");
    while(top!=-1) {
        start=stack[top--];
        printf("%c ",start+65);
        for(i=0;i<n;i++) {
            if(adj[start][i]==1 && visited[i]==0) {
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
}
void main() {
    int adj[MAX][MAX],i,j,ch;
    printf("Graph Traversal\nEnter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    printf("1.Breadth First Search(BFS)\n2.Depth First Search(DFS)\n3.Exit");
    do {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                breadthFirstSearch(adj,0);
                break;
            case 2: 
                depthFirstSearch(adj,0);
                break;
            case 3:
                exit(1);
            default:
                printf("Invalid Input...");
        }
    }while(ch!=3);
}


