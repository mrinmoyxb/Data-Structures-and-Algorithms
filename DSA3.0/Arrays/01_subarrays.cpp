#include <iostream>

void subarrays(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i; j++){
            for(int k=i; k<=i+j; k++){
                std::cout<<arr[k]<<" ";
            }
            std::cout<<std::endl;
        }
    }
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    subarrays(arr, 5);
    return 0;
}