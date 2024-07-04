#include <iostream>
using namespace std;

void insertionSort(int arr[], int size){


    for(int j=1; j<size; j++){ // right side of array
        int i = j-1;           // left side element index
        int key = arr[j];      // element of right side for comaprision

        while(i>=0 && arr[i]>key){ // checking leftt side if >=0 and left side element > right side element
            arr[i+1] = arr[i]; // if yes, shift towards right side
            i = i-1; // index subtracted by 1
        }
        arr[i+1] = key; // placed the key at sorted position
    }

    cout<<"\nSorted Array: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int n = 5;
    int arr[n] = {10, 2, 4, 90, 3};

    cout<<"\nArray: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    insertionSort(arr, n);
    return 0;
}