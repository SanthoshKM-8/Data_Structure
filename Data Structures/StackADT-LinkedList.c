#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *top,*newnode,*tempnode;
int choice,data,s,t;
void print();
void newNode();
void main(){
	printf("Linked List Implementation of Stack ADT\n1.isEmpty\n2.Push\n3.Pop\n4.Peek\n5.Search\n6.Print\n7.Exit\n");
	do{
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(top==NULL){
					printf("Yes,This stack is Empty.");
				}
				else{
					printf("No,This stack has some elements.");
				}
				break;
			case 2:
			    newNode();
			    if(top==NULL){
			        newnode->next=NULL;
			        top=newnode;
			    }
			    else{
			        newnode->next=top;
			        top=newnode;
			    }
			    print();
				break;
			case 3:
			    if(top==NULL){
			        printf("Underflow.");
			    }
			    else{
			        tempnode=top;
			        top=tempnode->next;
			        free(tempnode);
			        print();
			    }
				break;
			case 4:
			    printf("%d",top->data);
			    break;
			case 5:
				printf("Enter the data to search:");
				scanf("%d",&s);
				tempnode=top;
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
			case 6:
				print();
				break;
			case 7:
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
	tempnode=top;
	while(tempnode!=NULL){
		printf("%d ",tempnode->data);
		tempnode=tempnode->next;
	}	
}
