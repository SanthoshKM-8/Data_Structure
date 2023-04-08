#include<stdio.h>
#define Max 20
int arr[Max],n,key,i;
int linearSearch(int arr[],int key) {
    for(i=0;i<n;i++) {
        if(arr[i]==key)
            return 1;
    }
    return 0;
}
void main() {
    printf("Linear Search Algorithm\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to be searched: ");
    scanf("%d",&key);
    if(linearSearch(arr,key)) 
        printf("%d is found in the array at position %d.",key,i+1);
    else
        printf("%d is not found in the array.",key);
}
