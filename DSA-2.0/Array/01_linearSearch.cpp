#include <iostream>

//! linear search
bool linearSearch(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

//! reverse an array
void reverseArray(int* arr, int size){
    int start = 0;
    int end = size-1;
    while(start<=end){
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }

    std::cout<<"\nReverse array: "<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5] = {100, 120, 150, 200, 300};
    int key = 150;
    std::cout<<"Linear Search: "<<linearSearch(arr, 5, key)<<std::endl;
    reverseArray(arr, 5);
    return 0;
}