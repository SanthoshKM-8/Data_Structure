#include<stdio.h>
#include<stdlib.h>
int arr[8],n,i,choice,pos,val;
int isEmpty();
int isFull();
void arr_insertion();
void arr_deletion();
void arr_search();
void arr_print();
void main()
{
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("1.Check whether the list is empty or not?\n2.Check whether the list is full or not?\n3.Insert an element at beginning of the list\n4.Insert an element at nth position of the list\n5.Insert an element at end of the list\n6.Delete an element at beginning of the list\n7.Delete an element at nth position of the list\n8.Delete an element at end of the list\n9.To Search an element in the list\n10.To Print the list\n11.Exit\n");
	do
	{
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(isEmpty()){
					printf("Yes,This list is Empty.");
				}
				else{
					printf("No,This list has some elements.");
				}
				break;
			case 2:
				if(isFull()){
					printf("Yes,This list is Full.");
				}
				else{
					printf("No,This list has some space.");
				}
				break;
			case 3:
				if(isFull()){
					printf("This list is full.\nYou can't insert an element.");
				}
				else{
					pos=1;
					arr_insertion();
				}
				break;
			case 4:
				if(isFull()){
					printf("This list is full.\nYou can't insert an element.");
				}
				else{
					printf("Enter the position:");
					scanf("%d",&pos);
					arr_insertion();
				}
				break;
			case 5:
				if(isFull()){
					printf("This list is full.\nYou can't insert an element.");
				}
				else{
					pos=n+1;
					arr_insertion();
				}
				break;
			case 6:
				if(isEmpty(n)){
					printf("There is no element in the list to delete.");
				}
				else{
					pos=1;
					arr_deletion();
				}
				break;
			case 7:
				if(isEmpty()){
					printf("There is no element in the list to delete.");
				}
				else{
					printf("Enter the position:");
					scanf("%d",&pos);
					arr_deletion();
				}
				break;
			case 8:
				if(isEmpty()){
					printf("There is no element in the list to delete.");
				}
				else{
					pos=n;
					arr_deletion();
				}
				break;
			case 9:
				if(isEmpty()){
					printf("There is no element in the list to search.");
				}
				else{
					arr_search();
				}
				break;
			case 10:
				arr_print();
				break;
			case 11:
				exit(1);
			default:
				printf("Invalid Input...");
		}
		printf("\n------------------------------------------------------\n");
	}while(1);
}
int isEmpty()
{
	if(n==0){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull()
{
	if(n==8){
		return 1;
	}
	else{
		return 0;
	}
}
void arr_insertion()
{
	printf("Enter the value:");
	scanf("%d",&val);
	for(i=n-1;i>=pos-1;i--){
		arr[i+1]=arr[i];
	}
	arr[pos-1]=val;
	n++;
	arr_print();
}
void arr_deletion()
{
	for(i=pos-1;i<n;i++){
		arr[i]=arr[i+1];
	}
	n--;
	arr_print();
}
void arr_search()
{
	int s,t=1;
	printf("Enter the element to search:");
	scanf("%d",&s);
	for(i=0;i<n;i++){
		if(arr[i]==s){
			printf("The element is found at position %d.",i+1);
			t=0;
			break;
		}
	}
	if(t==1){
		printf("The element is not found in this list.");
	}
}
void arr_print(){
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
