#include <iostream>

void maxWater(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                
            }
            std::cout<<arr[i]<<" x "<<arr[j]<<" = "<<arr[i]*arr[j]<<std::endl;
        }
    }
}

int main(){
    int arr[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    maxWater(arr, 9);
    return 0;
}