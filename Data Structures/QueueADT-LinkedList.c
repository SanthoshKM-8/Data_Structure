#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *front,*rear,*newnode,*tempnode;
int choice,data,s,t;
void print();
void newNode();
void main(){
	printf("Linked List Implementation of Queue ADT\n1.isEmpty\n2.Enqueue\n3.Dequeue\n4.Search\n5.Print\n6.Exit\n");
	do{
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(front==NULL && rear==NULL){
					printf("Yes,This queue is Empty.");
				}
				else{
					printf("No,This queue has some elements.");
				}
				break;
			case 2:
			    newNode();
			    if(front==NULL && rear==NULL){
			        front=newnode;
			        rear=newnode;
			        newnode->next=NULL;
			    }
			    else{
			        rear->next=newnode;
			        rear=newnode;
			        newnode->next=NULL;
			    }
			    print();
				break;
			case 3:
			    if(front==NULL && rear==NULL){
			        printf("Underflow.");
			    }
			    else{
			        tempnode=front;
			        if(tempnode->next==NULL){
			            rear=tempnode->next;
			        }
			        front=tempnode->next;
			        free(tempnode);
			        print();
			    }
				break;
			case 4:
				printf("Enter the data to search:");
				scanf("%d",&s);
				tempnode=front;
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
			case 5:
				print();
				break;
			case 6:
				exit(1);
			default:
				printf("Invalid Input...");
		}
		printf("\n------------------------------------\n");
	}while(1);
}
void newNode(){
	printf("Enter the data:");
	scanf("%d",&data);
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("No memory will be allocated");
	}
	else{
		newnode->data=data;
	}
}
void print(){
	tempnode=front;
	while(tempnode!=NULL){
		printf("%d ",tempnode->data);
		tempnode=tempnode->next;
	}	
}
