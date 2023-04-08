#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *start,*newnode,*tempnode,*tmp;
int choice,ele,pos,s,t;
void printList();
void newNode();
void main(){
	printf("Creating a Start Node:-\n");
	newNode();
	newnode->prev=NULL;
	newnode->next=NULL;
	start=newnode;
	printf("1.Check whether the list is empty or not?\n2.Insert a node at beginning\n3.Insert a node at end\n4.Insert a node at after the given node\n5.Insert a node at before the given node\n6.Delete a node at beginning\n7.Delete a node at end\n8.Delete a node at after the given node\n9.Delete a node at before the given node\n10.To Search an element in the list\n11.To Print the list\n12.Exit\n");
	do{
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(start==NULL){
					printf("Yes,This list is Empty.");
				}
				else{
					printf("No,This list has some elements.");
				}
				break;
			case 2:
				newNode();
				start->prev=newnode;
				newnode->next=start;
				newnode->prev=NULL;
				start=newnode;
				printList();
				break;
			case 3:
				newNode();
				tempnode=start;
				while(tempnode->next!=NULL){
					tempnode=tempnode->next;
				}
				newnode->next=NULL;
				newnode->prev=tempnode;
				tempnode->next=newnode;
				printList();
				break;
			case 4:
				newNode();
				printf("Enter the data to insert a node after this data:");
				scanf("%d",&pos);
				tempnode=start;
				while(tempnode->data!=pos){
					tempnode=tempnode->next;
				}
				newnode->next=tempnode->next;
				newnode->prev=tempnode;
				tempnode->next=newnode;
				tempnode->next->prev=newnode;
				printList();
				break;
			case 5:
				newNode();
				printf("Enter the data to insert a node before this data:");
				scanf("%d",&pos);
				tempnode=start;
				if(tempnode->data!=pos){
					while(tempnode->next->data!=pos){
						tempnode=tempnode->next;
					}
					newnode->next=tempnode->next;
					newnode->prev=tempnode;
					tempnode->next=newnode;
					tempnode->next->prev=newnode;
				}
				else{
					start->prev=newnode;
					newnode->next=start;
					newnode->prev=NULL;
					start=newnode;
				}
				printList();
				break;
			case 6:
				tempnode=start;
				start=tempnode->next;
				start->prev=NULL;
				free(tempnode);
				printList();
				break;
			case 7:
				tempnode=start;
				while(tempnode->next->next!=NULL){
					tempnode=tempnode->next;
				}
				free(tempnode->next);
				tempnode->next=NULL;
				printList();
				break;
			case 8:
				printf("Enter the data to delete a node after this data:");
				scanf("%d",&pos);
				tempnode=start;
				while(tempnode->data!=pos){
					tempnode=tempnode->next;
				}
				tmp=tempnode->next;
				tempnode->next=tmp->next;
				tmp->next->prev=tmp->prev;
				free(tmp);
				printList();
				break;
			case 9:
				printf("Enter the data to delete a node before this data:");
				scanf("%d",&pos);
				tempnode=start;
				if(tempnode->next->data!=pos){
					while(tempnode->next->data!=pos){
						tempnode=tempnode->next;
					}
					tempnode->next->prev=tempnode->prev;
					tempnode->prev->next=tempnode->next;
					free(tempnode);
				}
				else{
					start=tempnode->next;
					start->prev=NULL;
					free(tempnode);
				}
				printList();
				break;
			case 10:
				printf("Enter the data to search:");
				scanf("%d",&s);
				tempnode=start;
				while(tempnode!=NULL){
					if(tempnode->data==s){
						printf("Data Found");
						t=1;
						break;
					}
					tempnode=tempnode->next;
					t=0;
				}
				if(t==0){
					printf("Data not Found");
				}
				break;
			case 11:
				printList();
				break;
			case 12:
				exit(1);
			default:
				printf("Invalid Input...");
		}
		printf("\n------------------------------------------------------\n");
	}while(1);
}
void newNode(){
	printf("Enter the data:");
	scanf("%d",&ele);
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("No memory will be allocated");
	}
	else{
		newnode->data=ele;
	}
}
void printList(){
	tempnode=start;
	while(tempnode!=NULL){
		printf("%d ",tempnode->data);
		tempnode=tempnode->next;
	}	
}
