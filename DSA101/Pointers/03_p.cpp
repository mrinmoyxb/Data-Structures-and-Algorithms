#include <iostream>

void doublePointer(){
    int num = 5;
    int* ptr = &num;
    int** ptr1 = &ptr;

    std::cout<<"Value: "<<std::endl;
    std::cout<<"num(num): "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"**ptr1: "<<**ptr1<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Address of num: "<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"*ptr1: "<<*ptr1<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Address of ptr: "<<std::endl;
    std::cout<<"&ptr: "<<&ptr<<std::endl;
    std::cout<<"ptr1: "<<ptr1<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"Address of ptr1: "<<std::endl;
    std::cout<<"&ptr1: "<<&ptr1<<std::endl;
}

int main(){
    doublePointer();
    return 0;
}