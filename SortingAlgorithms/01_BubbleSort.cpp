#include <iostream>

//! Bubble sort
void bubbleSort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

//! Bubble sort using recursion
void bubbleSortUsingRecursion(int *arr, int size){
    if(size==0 || size==1){
        return;
    }

    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            std::swap(arr[i], arr[i+1]);
        }
    }

    bubbleSortUsingRecursion(arr, size-1);
}

void bubbleSortOptimised(int *arr, int size){
    for(int i=0; i<size-1; i++){
        bool isSwap = false;
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }

        if(!isSwap){
            return;
        }
    }
}


int main(){
    int *arr = new int[5];
    int *arr1 = new int[5];

    std::cout<<"Array: "<<std::endl;
    for(int i=0; i<5; i++){
        int element;
        std::cout<<"Enter element: ";
        std::cin>>element;
        arr[i] = element;
        arr1[i] = element;
    }

    //bubbleSortUsingRecursion(arr1, 5);
    bubbleSortOptimised(arr1, 5);

    std::cout<<"\nSorted array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr1[i]<<" ";
    }
    return 0;
}