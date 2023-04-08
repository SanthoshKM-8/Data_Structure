#include<stdio.h>
#include<stdlib.h>
int n,k,i,data;
void newNode();
struct node{
    int data;
    struct node*next;
};
struct node *start,*newnode,*tempnode,*prenode;
void main(){
    printf("Enter the number of players:");
    scanf("%d",&n);
    printf("Enter the skip value:");
    scanf("%d",&k);
    newNode();
    start=newnode;
    newnode->next=start;
    for(i=1;i<n;i++){
        newNode();
        tempnode=start;
		while(tempnode->next!=start){
			tempnode=tempnode->next;
		}
		newnode->next=start;
		tempnode->next=newnode;
    }
    tempnode=start;
    while(tempnode->next!=tempnode){
        i=1;
        while(i!=k){
        	prenode=tempnode;
            tempnode=tempnode->next;
            i++;
        }
        prenode->next=tempnode->next;
        free(tempnode);
        tempnode=prenode->next;
    }
    printf("The winner is %d",tempnode->data);
}
void newNode(){
    printf("Enter Player ID:");
	scanf("%d",&data);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
}
