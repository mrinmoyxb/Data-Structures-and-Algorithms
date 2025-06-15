#include <iostream>

bool linearSearch(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[5] = {100, 120, 150, 200, 300};
    int key = 150;
    std::cout<<"Linear Search: "<<linearSearch(arr, 5, key)<<std::endl;
    return 0;
}