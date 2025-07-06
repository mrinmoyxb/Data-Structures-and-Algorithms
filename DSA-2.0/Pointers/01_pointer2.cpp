#include <iostream>

void pointer1(){
    int num = 5;
    int* ptr = &num;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"*(ptr+1) :"<<*(ptr+1)<<std::endl;
    std::cout<<"ptr+1: "<<ptr+1<<std::endl;
}

int main(){
    pointer1();
    return 0;
}