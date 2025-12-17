#include <iostream>
#include <vector>

void genSubArrays(){
    int arr[5] = {1, 2, 3, 4, 5};
    
    for(int i=0; i<5; i++){
        for(int j=i; j<5; j++){
            std::cout<<"[ ";
            for(int k=i; k<=j; k++){
                std::cout<<arr[k]<<" ";
            }
            std::cout<<"]\n";
        }
    }
}

int main(){
    genSubArrays();
    return 0;
}