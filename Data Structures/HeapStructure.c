#include <stdio.h>
#include <stdlib.h>
int size=0,data,choice,del,i,array[10];

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void maxHeap(int array[], int size, int i) {
    if(size==1) {
        printf("Only one node in the Heap.\n");
    }
    else {
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l < size && array[l] > array[largest])
            largest=l;
        if(r < size && array[r] > array[largest])
            largest=r;
        if(largest != i) {
            swap(&array[i], &array[largest]);
            maxHeap(array, size, largest);
        }
    }
}

void insert(int array[], int newNum) {
    if(size==0) {
        array[0]=newNum;
        size+=1;
    }
    else {
        array[size]=newNum;
        size+=1;
        for(i=size;i>=0;i--) {
            maxHeap(array, size, i);
        }
    }
}

void delete(int array[], int num) {
	if(size==1)
		 maxHeap(array, size, i);
  	for(i=0;i<size;i++) {
    	if(num==array[i])
    	    break;
    }
  	swap(&array[i], &array[size-1]);
  	size-=1;
  	for(i=size/2-1;i>=0;i--) {
  	    maxHeap(array, size, i);
    }
}

void display(int array[], int size) {
	if(size==0) {
		printf("Underflow");
	}
	else {
	    for(i=0;i<size;i++)
    	    printf("%d ",array[i]);
    }
}
void main() {
    printf("Implementation of Heap Structure (Max Heap)\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
    	        printf("Enter the data: ");
    	        scanf("%d",&data);
    	        insert(array,data);
    	        break;
	        case 2:
    	        del=array[0];
    	        delete(array,del);
    	        printf("Root Node is deleted.\n");
    	        break;
	        case 3:
    	        display(array,size);
    	        printf("\n");
    	        break;
            case 4:
                exit(0);
            default:
                printf("Invalid Input...\n");
        }
    } while(choice!=4);
}
