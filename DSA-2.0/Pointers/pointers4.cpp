#include <iostream>

void pointers1(int* ptr){
    std::cout<<"\nInside Function: "<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;
    *ptr += 10;
}

void pointers2(int* cptr){
    std::cout<<"\nInside Function: "<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*cptr<<std::endl;
    std::cout<<"Accessing address using ptr: "<<cptr<<std::endl;
    *cptr += 10;
}

int main(){
    int num = 10;
    int* ptr = &num;
    std::cout<<"Before: "<<std::endl;
    std::cout<<"Accessing value using num: "<<num<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing value using &num: "<<&num<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;

    pointers2(ptr);
    std::cout<<"\nAfter: "<<std::endl;
    std::cout<<"Accessing value using num: "<<num<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing value using &num: "<<&num<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;

    return 0;
}