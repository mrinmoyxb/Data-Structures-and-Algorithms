#include <iostream>

void pointers1(){
    // method1
    int num = 100;
    int* ptr = &num;

    // method2
    int* ptr1 = 0;
    ptr1 = &num;

    // method3
    int* ptr2 = NULL;
    ptr2 = &num;

    std::cout<<"Initialise using method 1: "<<std::endl;
    std::cout<<"Accessing value using num: "<<num<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;
    std::cout<<"Accessing address using &num: "<<&num<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Initialise using method 2: "<<std::endl;
    std::cout<<"Accessing value using *ptr1: "<<*ptr1<<std::endl;
    std::cout<<"Accessing value using num: "<<num<<std::endl;
    std::cout<<"Accessing address using ptr1: "<<&num<<std::endl;
    std::cout<<"Accessing address using ptr1: "<<ptr1<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Initialise using method3: "<<std::endl;
    std::cout<<"Accessing value using *ptr2: "<<*ptr2<<std::endl;
    std::cout<<"Accessing value using num: "<<num<<std::endl;
    std::cout<<"Accessing address using ptr2: "<<ptr2<<std::endl;
    std::cout<<"Accessing address using &num: "<<&num<<std::endl;
}

void pointers2(){
    int num = 120;
    int* ptr = &num;

    // method1
    std::cout<<"Pointer arithmetic: "<<std::endl;
    std::cout<<"addition: "<<(*ptr)+10<<std::endl;
    std::cout<<"subtraction: "<<(*ptr)-10<<std::endl;
    std::cout<<"multiplication: "<<(*ptr)*10<<std::endl;
    std::cout<<"division: "<<(*ptr)/2<<std::endl;
    std::cout<<std::endl;

    // method2
    *ptr = *ptr+10;
    *ptr = *ptr*10;
    *ptr = *ptr-100;
    *ptr = *ptr/10;
    std::cout<<"method2: "<<*ptr<<std::endl;
}

void pointers3(){
    int num = 100;
    int* ptr = &num;

    double num1 = 2.345;
    double* ptr1 = &num1;

    char c = 'A';
    char* ptr2 = &c;

    std::cout<<"int datatype: "<<std::endl;
    std::cout<<"Accessing value using num: "<<num<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing address using num: "<<&num<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;
    std::cout<<"adding 1 to ptr: "<<(ptr+1)<<std::endl; // + 4
    std::cout<<"size of num: "<<sizeof(num)<<std::endl;
    std::cout<<"size of ptr: "<<sizeof(ptr)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"float datatype: "<<std::endl;
    std::cout<<"Accessing value using num: "<<num1<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*ptr1<<std::endl;
    std::cout<<"Accessing address using num: "<<&num1<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr1<<std::endl;
    std::cout<<"adding to ptr1: "<<(ptr1+1)<<std::endl; // + 8
    std::cout<<"size of num1: "<<sizeof(num1)<<std::endl;
    std::cout<<"size of ptr1: "<<sizeof(ptr1)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"char datatype: "<<std::endl;
    std::cout<<"Accessing value using c: "<<c<<std::endl;
    std::cout<<"Accessing value using *ptr2: "<<*ptr<<std::endl;
    std::cout<<"Accessing address using &c: "<<static_cast<void*>(&c)<<std::endl;
    std::cout<<"Accessing address using ptr2: "<<static_cast<void*>(ptr2)<<std::endl;
    std::cout<<"adding 1 to ptr2: "<<static_cast<void*>(ptr2+1)<<std::endl; // + 1
    std::cout<<"size of num2: "<<sizeof(c)<<std::endl;
    std::cout<<"size of ptr2: "<<sizeof(ptr1)<<std::endl;
}

void pointers4(){
    int num = 100;
    int* ptr = &num;
    int* cptr = ptr;

    std::cout<<"Accessing num using num: "<<num<<std::endl;
    std::cout<<"Accessing num using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing num using *cptr: "<<*cptr<<std::endl;
    std::cout<<"Accessing address using &num: "<<&num<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;
    std::cout<<"Accessing address using cptr: "<<cptr<<std::endl;
    if(num==(*ptr) && num==(*cptr)){
        std::cout<<"Equal values"<<std::endl;
    }else{
        std::cout<<"Not equal"<<std::endl;
    }

    if(&num==ptr){
        std::cout<<"Equal address of num and ptr"<<std::endl;
    }else{
        std::cout<<"Not equal"<<std::endl;
    }

    if(ptr==cptr){
        std::cout<<"Equal address of ptr and cptr"<<std::endl;
    }else{
        std::cout<<"Not equal"<<std::endl;
    }

    // manipulating value using cptr
    *ptr = *cptr*2;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"*cptr: "<<*cptr<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
}

int main(){
    pointers4();
    return 0;
}