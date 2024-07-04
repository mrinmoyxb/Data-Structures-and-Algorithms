#include <iostream>
using namespace std;

void selectionSort(int *arr, int size){

    int min_index;

    for(int i=0; i<size-1; i++){
        min_index = i;

        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }

        swap(arr[min_index], arr[i]);
    }
}

int main(){
    int arr[5] = {2, 10, 3, 8, 12};

    cout<<"\nArray: "<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    selectionSort(arr, 5);

    cout<<"\nSorted Array: "<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}