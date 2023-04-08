#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,choice,data,s,t,i,max;
void print();
void main()
{
    printf("Enter the maximum size of the queue:");
    scanf("%d",&max);
    int queue[max];
    printf("Array Implementation of Queue ADT \n1.isEmpty\n2.isFull\n3.Enqueue\n4.Dequeue\n5.Search\n6.Print\n7.Exit");
    do{
       printf("\nEnter your choice:");
       scanf("%d",&choice);
       switch(choice){
            case 1:
                if((front==-1 && rear==-1) || (front>rear)){
                    printf("This queue is empty.");
                }
                else{
                    printf("This queue has some elements.");
                }
                break;
            case 2:
                if(front==0 && rear==max-1){
                    printf("This queue is full.");
                }
                else{
                    printf("This queue has some space.");
                }
                break;
            case 3:
                if(rear==max-1){
                    printf("Overflow.");
                }
                else{
                    printf("Enter the data:");
                    scanf("%d",&data);
                    if(front==-1 && rear==-1){
                        front=rear=0;
                    }
                    else{
                        rear=rear+1;
                    }
                    queue[rear]=data;
                    for(i=front;i<=rear;i++){
                        printf("%d ",queue[i]);
                    }
                }
                break;
            case 4:
                if((front==-1 && rear==-1) || (front>rear)){
                    printf("Underflow.");
                }
                else{
                    front=front+1;
                    for(i=front;i<=rear;i++){
                        printf("%d ",queue[i]);
                    }
                }
                break;
            case 5:
                printf("Enter the data to search:");
                scanf("%d",&s);
                for(i=front;i<=rear;i++){
                    if(queue[i]==s){
                        printf("Data Found.");
                        t=1;
                        break;
                    }
                    t=0;
                }
                if(t==0){
                    printf("Data not Found");
                }
                break;
            case 6:
                for(i=front;i<=rear;i++){
                    printf("%d ",queue[i]);
                }
                break;
            case 7:
                exit(1);
            default:
                printf("Invalid Input....");
       }
       printf("\n---------------------------");
    }while(1);
}
