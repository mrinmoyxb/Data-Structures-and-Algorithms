#include <iostream>

//! Dynamic Memory Allocation
//* 1. We can access heap memory using "new" keyword
//* 2. int* num -> initialised in stack memory, size is of 8 bytes
//* 3. new int -> initialised in heap memory, size is of 4 bytes

//! Dynamic Memory Allocation 
void dynamicMemory1(){
    int* num = new int(10);
    char* c = new char('A');

    std::cout<<"*num: "<<*num<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"size of *num: "<<sizeof(*num)<<std::endl;
    std::cout<<"size of num: "<<sizeof(num)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"*c: "<<*c<<std::endl;
    std::cout<<"c: "<<static_cast<void*>(c)<<std::endl;
    std::cout<<"size of *c: "<<sizeof(*c)<<std::endl;
    std::cout<<"size of c: "<<sizeof(c)<<std::endl;

    delete num;
    delete c;
}

//! Array in heap memory
void dynamicMemory2(){
    int* arr = new int[5];

    for(int i=0; i<5; i++){
        std::cout<<"Enter an element: ";
        std::cin>>*(arr+i);
    }

    std::cout<<"\nTraverse an array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<*(arr+i)<<" ";
    }

    std::cout<<"\nsize of array: "<<sizeof(arr)<<std::endl;
    delete []arr;
}

int main(){
    dynamicMemory2();
    return 0;
}