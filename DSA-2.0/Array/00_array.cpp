#include <iostream>

void array1(){
    int size;
    std::cout<<"Enter the size of array: "<<std::endl;
    std::cin>>size;
    int arr[size];
    std::cout<<"Enter values: ";
    for(int i=0; i<size; i++){
        std::cin>>arr[i];
    }
    std::cout<<"The values in array are: "<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
}

int main(){
    array1();
    return 0;
}