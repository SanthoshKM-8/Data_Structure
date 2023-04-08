#include<stdio.h>
#include<stdlib.h>
struct node{
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
	start=newnode;
	newnode->next=start;
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
				tempnode=start;
				while(tempnode->next!=start){
					tempnode=tempnode->next;
				}
				tempnode->next=newnode;
				newnode->next=start;
				start=newnode;
				printList();
				break;
			case 3:
				newNode();
				tempnode=start;
				while(tempnode->next!=start){
					tempnode=tempnode->next;
				}
				newnode->next=start;
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
				tempnode->next=newnode;
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
					tempnode->next=newnode;
				}
				else{
					newnode->next=start;
					start=newnode;
				}
				printList();
				break;
			case 6:
				tmp=start;
				tempnode=start;
				while(tempnode->next!=start){
					tempnode=tempnode->next;
				}
				start=tmp->next;
				tempnode->next=start;
				free(tmp);
				printList();
				break;
			case 7:
				tempnode=start;
				while(tempnode->next->next!=start){
					tempnode=tempnode->next;
				}
				free(tempnode->next);
				tempnode->next=start;
				printList();
				break;
			case 8:
				printf("Enter the data to delete a node after this data:");
				scanf("%d",&pos);
				tempnode=start;
				tmp=start->next;
				while(tempnode->data!=pos){
					tmp=tmp->next;
					tempnode=tempnode->next;
				}
				tempnode->next=tmp->next;
				free(tmp);
				printList();
				break;
			case 9:
				printf("Enter the data to delete a node before this data:");
				scanf("%d",&pos);
				tempnode=start;
				if(tempnode->next->data!=pos){
					while(tempnode->next->data!=pos){
						tmp=tempnode;
						tempnode=tempnode->next;
					}
					tmp->next=tempnode->next;
					free(tempnode);
				}
				else{
					start=tempnode->next;
					start->next=tempnode->next;
					free(tempnode);
				}
				printList();
				break;
			case 10:
				printf("Enter the data to search:");
				scanf("%d",&s);
				tempnode=start;
				while(tempnode->next!=start||tempnode->next==start){
					if(tempnode->data==s){
						printf("Data Found");
						t=1;
						break;
					}
					if(tempnode->next==start){
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
	while(tempnode->next!=start){
		printf("%d ",tempnode->data);
		tempnode=tempnode->next;
	}
	printf("%d",tempnode->data);	
}
