#include <iostream>

void pointers1(){
    int num = 10;
    int* ptr = &num;

    double num1 = 10.23;
    double* ptr1 = &num1;

    char c = 'A';
    char* ptr2 = &c;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<std::endl;

    std::cout<<"num1: "<<num1<<std::endl;
    std::cout<<"*ptr1: "<<*ptr1<<std::endl;
    std::cout<<"&num1: "<<&num1<<std::endl;
    std::cout<<"ptr1: "<<ptr1<<std::endl;
    std::cout<<std::endl;

    std::cout<<"c: "<<c<<std::endl;
    std::cout<<"*ptr2: "<<*ptr2<<std::endl;
    std::cout<<"&c: "<<static_cast<const void*>(&c)<<std::endl;
    std::cout<<"ptr2: "<<static_cast<const void*>(ptr2)<<std::endl;
}

void pointerArtihemtic(){
    int num = 100;
    int* ptr = &num;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<std::endl;

    (*ptr)+=5;

    std::cout<<"Pointer addition: "<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<std::endl;

    (*ptr)-=5;
    std::cout<<"Pointer subtraction: "<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<std::endl;

    (*ptr)*=5;
    std::cout<<"Pointer multiplication: "<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<std::endl;

    (*ptr)/=5;
    std::cout<<"Pointer division: "<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<std::endl;

    (*ptr)%=5;
    std::cout<<"Pointer modulus: "<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
}

void copyPointer(){
    int num = 100;
    int* ptr = &num;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<std::endl;

    int* cptr = ptr;

    std::cout<<"*cptr: "<<*cptr<<std::endl;
    std::cout<<"cptr: "<<cptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Pointer and copy pointer have different address"<<std::endl;
    std::cout<<"&ptr: "<<&ptr<<std::endl;
    std::cout<<"&cptr: "<<&cptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"They share the same value and stores the same address: "<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"*cptr: "<<*cptr<<std::endl;

    *cptr+=100;

    std::cout<<"*cptr: "<<*cptr<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<std::endl;

    cptr+=1;

    std::cout<<"cptr: "<<cptr<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<std::endl;
}

void pointerAddress(){
    int num = 100;
    int* ptr = &num;

    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<std::endl;

    *ptr+=1;
    ptr+=1;

    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    
}

int main(){
    pointerAddress();
    return 0;
}