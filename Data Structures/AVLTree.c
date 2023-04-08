#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    int data;
    struct tree *right;
    int height;
}*newnode,*root;
int height(struct tree *t) {
    int leftH,rightH;
    if(t==NULL)
        return 0;
    else
        leftH=height(t->left);
        rightH=height(t->right);
        if(leftH > rightH)
            return leftH+1;
        else
            return rightH+1;
}
int getBalanceFactor(struct tree *t) {
    if(t==NULL)
        return 0;
    return height(t->left)-height(t->right);
}
struct tree * newNode(int data) {
    newnode=malloc(sizeof(struct tree));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return  newnode;
}
struct tree * singleRotateWithLeft(struct tree *y) {
    struct tree *x=y->left;
    y->left=x->right;
    x->right=y;
    y->height=height(y);
    x->height=height(x);
    return x;
}
struct tree * singleRotateWithRight(struct tree *x) {
    struct tree *y=x->right;
    x->right=y->left;
    y->left=x;
    y->height=height(y);
    x->height=height(x);
    return y;
}
struct tree * doubleRotateWithLeft(struct tree *y) {
    y->left=singleRotateWithRight(y->left);
    return singleRotateWithLeft(y);
}
struct tree * doubleRotateWithRight(struct tree *y) {
    y->right=singleRotateWithLeft(y->right);
    return singleRotateWithRight(y);
}
struct tree * insert(struct tree *t, int data) {
    if(t==NULL)
        return (newNode(data));
    else if(data < t->data)
        t->left=insert(t->left,data);
    else if(data > t->data)
        t->right=insert(t->right, data);
    else
        return t;
    t->height=height(t);
    int bal=getBalanceFactor(t);
    if(bal == 2) {
        if(data < t->left->data)
            return singleRotateWithLeft(t);
        else
            return doubleRotateWithLeft(t);
    }
    if(bal == -2) {
        if(data > t->right->data)
            return singleRotateWithRight(t);
        else
            return doubleRotateWithRight(t);
    }
    return t;
}
void display(struct tree *t) {
    if(t!=NULL) {
        display(t->left);
        printf("%d ",t->data);
        display(t->right);
    }
}
void main() {
    int choice,ele;
    printf("Implementation of AVL Tree\n1.Insertion\n2.Display\n3.Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&ele);
                root=insert(root,ele);
                break;
            case 2:
                display(root);
                printf("\n");
                break;
            case 3: 
                exit(0);
            default:
                printf("Invalid Input...");
       }
    }while(choice!=3);
}

