#include <iostream>

//! Pointers and array
//* 1. Here we are sending the address of the first element of the array
void pointers1(int* arr, int size){
    std::cout<<"\nArray inside function: "<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<*(arr+i)<<" ";
    }
}

//! Manipulating array with pointers
void pointers2(int* arr, int size){
    for(int i=0; i<size; i++){
        if(*(arr+i)%2==0){
            *(arr+i) = 1;
        }else{
            *(arr+i) = 0;
        }
    }

    std::cout<<"\nArray inside function(after manipulation): "<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<*(arr+i)<<" ";
    }
}

int main(){
    int arr[5] = {10, 23, 30, 43, 50};
    std::cout<<"Array inside main(before manipulation): "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<*(arr+i)<<" ";
    }
    pointers2(arr, 5);
    return 0;
}
