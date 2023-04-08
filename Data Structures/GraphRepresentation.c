#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void init(int Graph[MAX][MAX]) {
    int i,j;
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            Graph[i][j]=0;
}

void addEdge(int Graph[MAX][MAX], int i, int j) {
    Graph[i][j]=1;
    Graph[j][i]=1;
}

void printAdjMatrix(int Graph[MAX][MAX]) {
    int i,j;
    for(i=0;i<MAX;i++) {
        printf("%c: ",i+65);
        for(j=0;j<MAX;j++) {
            printf("%d ",Graph[i][j]);
        }
        printf("\n");
    }
}

void printAdjList(int Graph[MAX][MAX]) {
    int i,j;
    for(i=0;i<MAX;i++) {
        printf("%c: ",i+65);
        for(j=0;j<MAX;j++) {
            if(Graph[i][j]==1)
                printf("%c ",j+65);
        }
        printf("\n");
    }
}

void main() {
    int Graph[MAX][MAX],ch;
    init(Graph);
    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 2);
    addEdge(Graph, 0, 4);
    addEdge(Graph, 1, 4);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 3, 4);
    printf("Graph Representation\n1.Adjacency Matrix\n2.Adjacency List\n3.Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Adjacency Matrix Representation\n");
                printAdjMatrix(Graph);
                break;
            case 2: 
                printf("Adjacency List Representation\n");
                printAdjList(Graph);
                break;
            case 3:
                exit(1);
            default:
                printf("Invalid Input...");
        }
    }while(ch!=3);
}

