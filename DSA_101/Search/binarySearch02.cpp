#include <iostream>

int binarySearchRotated(int arr[], int size, int key){
    int start = 0;
    int end = size-1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[start]<=arr[mid]){
            if(arr[start]<=key && key<=arr[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        else{
            if(arr[mid]<=key && key<=arr[end]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
    }

    return -1;
}

int main(){
    int arr[8] = {3, 4, 5, 6, 7, 0, 1, 2};
    std::cout<<"Array: "<<std::endl;
    for(int i=0; i<8; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"Search: "<<binarySearchRotated(arr, 8, 0);
    return 0;
}