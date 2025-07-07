#include <iostream>

//! Techniques for accessing array:
void pointer1(){
    int arr[5] = {1, 2, 3, 4, 5};

    //* arr[i]
    std::cout<<"Array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }

    //* *(arr+i)
    std::cout<<"\nArray using pointers: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<*(arr+i)<<" ";
    }

    //* i[arr]
    std::cout<<"\nArray: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<i[arr]<<" ";
    }
}

//! *(arr+i) -> Values
//! arr+i -> Addresses 
void pointer2(){
    int arr[5] = {10, 20, 30, 40, 50};
    
    std::cout<<"arr: "<<arr<<std::endl;
    std::cout<<"&arr[0]: "<<&arr[0]<<std::endl;
    std::cout<<"*arr: "<<*arr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"arr+1: "<<(arr+1)<<std::endl;
    std::cout<<"&arr[1]: "<<&arr[1]<<std::endl;
    std::cout<<"arr[1]: "<<arr[1]<<std::endl;
    std::cout<<"*(arr+1): "<<*(arr+1)<<std::endl;
}

//! Manipulating array using pointers
//! arr[i] is similar to *(arr+i)
void pointer3(){
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i=0; i<5; i++){
        if(*(arr+i)%2==0){
            *(arr+i) = 1;
        }else{
            *(arr+i) = 0;
        }
    }

    std::cout<<"Array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<*(arr+i)<<" ";
    }
}

//! Pointers and array
void pointer4(){
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    std::cout<<"Accessing array using pointers: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<*(ptr+i)<<" ";
    }
}

int main(){
    pointer4();
    return 0;
}