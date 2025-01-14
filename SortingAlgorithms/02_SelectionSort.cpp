#include <iostream>

void selectionSort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i+1; j<size-1; j++){
            if(arr[i]<arr[min]){
                min = i;
            }
        }

        std::swap(arr[min], arr[i]);
    }
}

int main(){
    int *arr = new int[5];
    return 0;
}