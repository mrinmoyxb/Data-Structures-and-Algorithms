#include <iostream>

void twoSum(int *arr, int size, int target){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]+arr[j]==target){
                std::cout<<"i: "<<i<<" j: "<<j<<std::endl;
            }
        }
    }
}

int main(){
    int arr[5] = {1, 2, 4, 2, 5};
    
    return 0;
}