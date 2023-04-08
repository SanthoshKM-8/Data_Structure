#include<stdio.h>
#include<stdlib.h>
int n,i,ele,choice;
struct tree{
    struct tree *left;
    int data;
    struct tree *right;    
}*newnode,*root,*temp;
struct tree * newNode(int ele){
    newnode=(struct tree*)malloc(sizeof(struct tree));
    newnode->data=ele;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct tree * insert(struct tree *t, int ele){
    if(t==NULL)
        return newNode(ele);
    else if(t->left==NULL)
        t->left=insert(t->left,ele);
    else if(t->right==NULL)
        t->right=insert(t->right,ele);
    else{
        if(t->left->left!=NULL && t->left->right!=NULL)
            insert(t->right,ele);
        else
            insert(t->left,ele);
    }
    return t;
}
void preOrder(struct tree *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct tree *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void postOrder(struct tree *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
void main(){
    printf("Implementation of Binary Tree\nEnter the number of elements: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter the data: ");
        scanf("%d",&ele);
        root=insert(root,ele);
    }
    printf("1.Preorder Traversal\n2.Inorder Traversal\n3.Postorder Traversal\n4.Exit");
    do {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Preorder: ");
                preOrder(root);
                break;
            case 2:
                printf("Inorder: ");
                inOrder(root);
                break;
            case 3:
                printf("Postorder: ");
                postOrder(root);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Input...");
        }
    } while(choice!=4);
}
