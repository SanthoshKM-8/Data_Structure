#include<stdio.h>
#define Max 20
int arr[Max],n,i;
void bubbleSort(int arr[]) {
    int temp,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n-i-1;j++) {
           if(arr[j]>arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            } 
        }
    }
    printf("The sorted array is ");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
void main() {
    printf("Bubble Sort Algorithm\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr);
}
