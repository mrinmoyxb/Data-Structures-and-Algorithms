#include <stdio.h>

void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int currentMin = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[currentMin]){
                currentMin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[currentMin];
        arr[currentMin] = temp;
    }

    printf("\nSorted array: \n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[6] = {7, 4, 10, 8, 3, 1};
    selectionSort(arr, 6);
    return 0;
}