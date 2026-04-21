#include <stdio.h>

void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int currentMinimum = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[currentMinimum]){
                currentMinimum = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[currentMinimum];
        arr[currentMinimum] = temp;
    }


    printf("\nSelection Sort:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

void merge(int arr[], int start, int end){
    int mid = start+(end-start)/2;
    int len1 = mid-start+1;
    int len2 = end-mid;

    int first[len1];
    int second[len2];

    int k = start;
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }
    k = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[k++];
    }

    int index1 = 0, index2 = 0;
    k = start;
    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[k++] = first[index1++];
        }else{
            arr[k++] = second[index2++];
        }
    }

    while(index1<len1){
        arr[k++] = first[index1++];
    }

    while(index2<len2){
        arr[k++] = second[index2++];
    }
}

void mergeSort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, end);
}

void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j=i-1;

        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    int arr[5] = {12, 3, 5, 9, 1};
    insertionSort(arr, 5);

    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}