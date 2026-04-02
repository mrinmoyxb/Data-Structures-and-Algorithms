#include <iostream>

void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int smallIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[smallIndex]){
                smallIndex = j;
            }
        }
        std::swap(arr[smallIndex], arr[i]);
    }

    std::cout<<"Array: "<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
}

void selectionSort1(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int minValue = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[minValue]){
                minValue = j;
            }
        }
        std::swap(arr[minValue], arr[i]);
    }
}

void insertionSort(int arr[], int size){
    
}

int main(){
    int arr[5] = {4, 1, 5, 2, 3};
    selectionSort(arr, 5);
    return 0;
}