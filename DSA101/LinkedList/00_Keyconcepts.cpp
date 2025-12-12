#include <iostream>

void dynamicMemory1(){
    int* ptr1 = new int;
    *ptr1 = 100;

    int* ptr2 = new int(120);
    
    std::cout<<"\nBefore deletion: "<<std::endl;
    std::cout<<"Memory allocation for a single value: "<<std::endl;
    std::cout<<"Value(*ptr1): "<<*ptr1<<std::endl;
    std::cout<<"Address allocated: "<<ptr1<<std::endl;
    std::cout<<"Value(*ptr2): "<<*ptr2<<std::endl;
    std::cout<<"Address allocated: "<<ptr2<<std::endl;

    delete ptr1;
    ptr1 = NULL;
    delete ptr2;
    ptr2 = NULL;

    std::cout<<"\nAfter deletion: "<<std::endl;
    std::cout<<"Value(*ptr1): "<<*ptr1<<std::endl;
    std::cout<<"Address allocated: "<<ptr1<<std::endl;
    std::cout<<"Value(*ptr2): "<<*ptr2<<std::endl;
    std::cout<<"Address allocated: "<<ptr2<<std::endl;
}

void dynamicMemory2(){
    int* ptr = new int[100];

    std::cout<<"\nArray:"<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<"\nEnter an element: ";
        std::cin>>*(ptr+i);
    }

    std::cout<<"\nArray: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<*(ptr+i)<<" ";
    }
}

void check1(int* ptr){
    std::cout<<"Address it's referring to: "<<ptr<<std::endl;
    std::cout<<"Value: "<<*ptr<<std::endl;
    std::cout<<"Address of the pointer: "<<&ptr<<std::endl;
}

void check2(int*& ptr){
    std::cout<<"Address it's referring to: "<<ptr<<std::endl;
    std::cout<<"Value: "<<*ptr<<std::endl;
    std::cout<<"Address of the pointer: "<<&ptr<<std::endl;
}

int main(){
    int num = 100;
    int* ptr = &num;

    std::cout<<"\nInside main: "<<std::endl;
    std::cout<<"Address it's referring to: "<<ptr<<std::endl;
    std::cout<<"Value: "<<*ptr<<std::endl;
    std::cout<<"Address of the pointer: "<<&ptr<<std::endl;
    std::cout<<std::endl;

    check1(ptr);
    std::cout<<std::endl;
    check2(ptr);
    return 0;
}