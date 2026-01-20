#include <iostream>

void deleteArr(int arr[], int index, int size){
    for(int i=index; i<size-1; i++){
        arr[i] = arr[i+1];
    }

    std::cout<<"The array: "<<std::endl;
    for(int i=0; i<size-1; i++){
        std::cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5] = {12, 14, 16, 19, 20};
    deleteArr(arr, 2, 5);
    return 0;
}