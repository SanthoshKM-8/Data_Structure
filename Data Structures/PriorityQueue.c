#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int priority;
	struct node *next;
};
struct node *start,*newnode,*tempnode,*tmp;
int choice,data,priority,s,t;
void print();
void newNode();
void main(){
	printf("Implementation of Priority Queue\n1.isEmpty\n2.Enqueue\n3.Dequeue\n4.Search\n5.Print\n6.Exit\n");
	do{
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(start==NULL){
					printf("Yes,This queue is Empty.");
				}
				else{
					printf("No,This queue has some elements.");
				}
				break;
			case 2:
			    newNode();
			    if(start==NULL){
			        newnode->next=NULL;
			        start=newnode;
			    }
			    else if(newnode->priority<start->priority){
			        newnode->next=start;
			        start=newnode;
			    }
			    else if(newnode->priority>start->priority){
			        tempnode=start;
			        while(tempnode->priority<newnode->priority){
			            tmp=tempnode;
			            tempnode=tempnode->next;
			            if(tempnode==NULL){
			                break;
			            }
			        }
			        if(tmp->next==NULL){
			            newnode->next=NULL;
			            tmp->next=newnode;
			        }
			        else{
			            newnode->next=tmp->next;
			            tmp->next=newnode;
			        }
			    }
			    else{
			        newnode->next=start->next;
			        start->next=newnode;
			    }
			    print();
				break;
			case 3:
			    if(start==NULL){
			        printf("Underflow.");
			    }
			    else{
			        tempnode=start;
			        start=tempnode->next;
			        free(tempnode);
			        print();
			    }
				break;
			case 4:
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
	printf("Enter the priority:");
	scanf("%d",&priority);
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("No memory will be allocated");
	}
	else{
		newnode->data=data;
		newnode->priority=priority;
	}
}
void print(){
	tempnode=start;
	while(tempnode!=NULL){
		printf("%d[%d] ",tempnode->data,tempnode->priority);
		tempnode=tempnode->next;
	}	
}
