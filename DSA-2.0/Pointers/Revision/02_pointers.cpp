#include <iostream>

void pointers(){
    int num = 100;
    int* ptr = &num;
    int* cptr = ptr;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"&ptr: "<<&ptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"*cptr: "<<*cptr<<std::endl;
    std::cout<<"cptr: "<<cptr<<std::endl;
}

void pointers1(){
    int num = 100;
    int* ptr1 = &num;
    int** ptr2 = &ptr1;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;

    std::cout<<"\n*ptr1: "<<*ptr1<<std::endl;
    std::cout<<"ptr1: "<<ptr1<<std::endl;
    std::cout<<"&ptr1: "<<&ptr1<<std::endl;

    std::cout<<"\nptr2: "<<ptr2<<std::endl;
    std::cout<<"*ptr2: "<<*ptr2<<std::endl;
    std::cout<<"**ptr2: "<<**ptr2<<std::endl;
    std::cout<<"&ptr2: "<<&ptr2<<std::endl;
}

void pointers2(){
    int num = 100;
    int* ptr1 = &num;
    int** ptr2 = &ptr1;

    std::cout<<"value of num: "<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr1: "<<*ptr1<<std::endl;
    std::cout<<"**ptr2: "<<**ptr2<<std::endl;

    std::cout<<"\naddress of num: "<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr1: "<<ptr1<<std::endl;
    std::cout<<"*ptr2: "<<*ptr2<<std::endl;

    std::cout<<"\nvalue of ptr1: "<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr1: "<<ptr1<<std::endl;
    std::cout<<"*ptr2: "<<*ptr2<<std::endl;

    std::cout<<"\naddress of ptr1: "<<std::endl;
    std::cout<<"&ptr1: "<<&ptr1<<std::endl;
    std::cout<<"ptr2: "<<ptr2<<std::endl;

    std::cout<<"\nvalue of ptr2: "<<std::endl;
    std::cout<<"&ptr1: "<<&ptr1<<std::endl;
    std::cout<<"ptr2: "<<ptr2<<std::endl;

    std::cout<<"\naddress of ptr2: "<<std::endl;
    std::cout<<"&ptr2: "<<&ptr2<<std::endl;
}

int main(){
    pointers2();
    return 0;
}