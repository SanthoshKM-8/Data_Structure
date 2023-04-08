#include<stdio.h>
#include<stdlib.h>
int size,choice,key,ind,i,del,count=0;
void linearProbing(int arr[], int index);
void init(int arr[],int size) {
    for(i=0;i<size;i++)
        arr[i]=-1;
}
int hash(int key, int size) {
    ind=key%size;
    return ind;
}
void insert(int arr[], int key, int ind) {
    if(arr[ind]==-1) {
        count++;
        arr[ind]=key;
        if(count==size)
            printf("Overflow...\n");
    }
    else {
        i=0;
        linearProbing(arr, ind);
    }
}
void linearProbing(int arr[], int ind) {
    i++;
    ind+=i;
    if(ind==size) 
        ind=0;
    insert(arr, key, ind);
}
void delete(int arr[], int del) {
    for(i=0;i<size;i++){
        if(del==arr[i]){
            count--;
            arr[i]=-1;
            return;
        }
    }
    printf("Element not found!\n");
}
void display(int arr[]) {
    printf("Hash Table elements are: ");
    for(i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void main() {
    printf("Implementation of Hashing and Collision Techniques\nEnter the table size: ");
    scanf("%d",&size);
    int arr[size];
    init(arr,size);
    printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the key: ");
                scanf("%d",&key);
                ind=hash(key,size);
                insert(arr,key,ind);
                break;
            case 2:
                printf("Enter the element to be deleted: ");
                scanf("%d",&del);
                delete(arr,del);
                break;
            case 3:
                display(arr);
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid Input...\n");
        }
    }while(choice!=4);
}
