#include <iostream>

//! Character array:
void pointer1(){
    char c[5] = "abcd";
    std::cout<<c<<std::endl;
}

//! Accessing array using pointers:
void pointer2(){
    char c[5] = "abcd";
    char* ptr = &c[0];
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;

    std::cout<<"\nTraversing character array using pointers: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<*(ptr+i)<<" "<<std::endl;
    }
}

//! Hexadecimal address: static_cast<void*>(ptr1)
void pointer3(){
    char c[5] = "abcd";
    char* ptr = &c[0];

    char x = 'A';
    char* ptr1 = &x;

    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"*ptr1: "<<*ptr1<<std::endl;
    std::cout<<"Addres of char <void*>(ptr1): "<<static_cast<void*>(ptr1)<<std::endl;
}

int main(){
    pointer3();
    return 0;
}