#include<stdio.h>
#define Max 20
int arr[Max],n,key,i,mid;
int binarySearch(int arr[],int key) {
    int min,max;
    min=0;
    max=n-1;
    while(min<=max) {
        mid=(min+max)/2;
        if(key==arr[mid])
            return 1;
        else if(key<arr[mid])
            max=mid-1;
        else
            min=mid+1;
    }
    return 0;
}
void sort(int arr[]) {
    int temp,j;
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
           if(arr[i]>arr[j]) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            } 
        }
    }
    printf("The sorted array is ");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
void main() {
    printf("Binary Search Algorithm\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    sort(arr);
    printf("\nEnter the number to be searched: ");
    scanf("%d",&key);
    if(binarySearch(arr,key)) 
        printf("%d is found in the array at position %d.",key,mid+1);
    else
        printf("%d is not found in the array.",key);
}
