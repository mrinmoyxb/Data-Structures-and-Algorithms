#include <stdio.h>

int linearSearch(int arr[],  int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return 1;
        }
    }

    return -1;
}

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            return 1;
        }

        if(key > arr[mid]){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    return -1;
}

int main(){
    int arr[5] = {12, 13, 34, 78, 90};
    printf("Linear Search: %d\n", linearSearch(arr, 5, 78));
    printf("Binary Search: %d", binarySearch(arr, 5, 78));
    return 0;
}