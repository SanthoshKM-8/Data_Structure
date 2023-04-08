#include<stdio.h>
#include<stdlib.h>
int top=-1,choice,data,s,t,i,max;
void main()
{
    printf("Array Implementation of Stack ADT\nEnter the maximum size of the stack:");
    scanf("%d",&max);
    int stack[max];
    printf("1.isEmpty\n2.isFull\n3.Push\n4.Pop\n5.Peek\n6.Search\n7.Print\n8.Exit");
    do{
       printf("\nEnter your choice:");
       scanf("%d",&choice);
       switch(choice){
            case 1:
                if(top==-1){
                    printf("This stack is empty.");
                }
                else{
                    printf("This stack has some elements.");
                }
                break;
            case 2:
                if(top==max-1){
                    printf("This stack is full.");
                }
                else{
                    printf("This stack has some space.");
                }
                break;
            case 3:
                if(top==max-1){
                    printf("Overflow.");
                }
                else{
                    printf("Enter the data:");
                    scanf("%d",&data);
                    top=top+1;
                    stack[top]=data;
                    for(i=top;i>=0;i--){
        				printf("%d ",stack[i]);
    				}
                }
                break;
            case 4:
                if(top==-1){
                    printf("Underflow.");
                }
                else{
                    top=top-1;
                    for(i=top;i>=0;i--){
        				printf("%d ",stack[i]);
    				}
                }
                break;
            case 5:
                printf("%d",stack[top]);
                break;
            case 6:
                printf("Enter the data to search:");
                scanf("%d",&s);
                for(i=0;i<=top;i++){
                    if(stack[i]==s){
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
            case 7:
                for(i=top;i>=0;i--){
        			printf("%d ",stack[i]);
   				}
                break;
            case 8:
                exit(1);
            default:
                printf("Invalid Input....");
       }
       printf("\n---------------------------");
    }while(1);
}
