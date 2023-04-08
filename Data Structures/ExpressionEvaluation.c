#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

char infix[MAX],postfix[MAX];
int stack[MAX];
int top=-1;
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int symbol){
    if(top>MAX){
        printf("Stack Overflow");
        exit(1);
    }
    stack[++top]=symbol;
}
int pop(){
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    return (stack[top--]);
}
int priority(char symbol){
    switch(symbol){
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default :
            return 0;
    }
}
void infix_to_postfix(){
    int i,p=0;
    char next,symbol;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(symbol!=' '){
            switch(symbol){
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while((next=pop())!='('){
                        postfix[p++]=next;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    while(isEmpty()==0 && priority(stack[top])>=priority(symbol)){
                        postfix[p++]=pop();
                    }
                    push(symbol);
                    break;
                default: 
                    postfix[p++]=symbol;
            }
        }
    }
    while(isEmpty()==0){
        postfix[p++]=pop();
    }
    postfix[p]='\0';
}
int postfix_evaluation(){
    int a,b,temp,result;
    int i;
    for(i=0;i<strlen(postfix);i++){
        if(postfix[i]<='9' && postfix[i]>='0'){
            push(postfix[i]-'0');
        }
        else{
            a=pop();
            b=pop();
            switch(postfix[i]){
                case '+':
                    temp=b+a; 
                    break;
                case '-':
                    temp=b-a;
                    break;
                case '*':
                    temp=b*a;
                    break;
                case '/':
                    temp=b/a;
                    break;
            }
            push(temp);
        }
    }
    result=pop();
    return result;
}
void main(){
    int value;
    printf("Enter the Infix Expression : ");
    gets(infix);
    infix_to_postfix();
    printf("Postfix Expression : %s\n",postfix);
    printf("Result : %d",postfix_evaluation());
}
