#include <iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for(int j=1; j<size; j++){
        int i = j-1;
        int key = arr[j];
        while(i>=0 && arr[i]>key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;

    }
}

void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int min_index = i;

        for(int j=i+1; j<size; j++){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }

        swap(arr[min_index], arr[i]);
    }
}

void selectionSorts(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int min_index = i;

        for(int j=i+1; j<size-1; j++){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }

        swap(arr[min_index], arr[i]);
    }
}

void insertionSorts(int arr[], int size){
    for(int j=1; j<size; j++){
        int i = j-1;
        int key = arr[j];

        while(i>=0 && arr[i]>key){
            arr[i+1] = arr[i];
            i--;
        }

        arr[i+1] = key;
    }
}


int main(){
    return 0; 
}