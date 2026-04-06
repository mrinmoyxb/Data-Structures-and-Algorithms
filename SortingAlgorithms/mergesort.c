#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int mid, int end){
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = (int*)malloc(sizeof(int)*len1);
    int *second = (int*)malloc(sizeof(int)*len2);

    int k = start;

    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }
    
    for(int i=0; i<len2; i++){
        second[i] = arr[k++];
    }

    int index1 = 0, index2 = 0;
    int mainArrayIndex = start;

    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    free(first);
    free(second);
}

void mergeSort(int* arr, int start, int end){
    if(start>=end){
        return;
    }

    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}

int main(){
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr, 0, 6);

    printf("array: \n");
    for(int i=0; i<7; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}