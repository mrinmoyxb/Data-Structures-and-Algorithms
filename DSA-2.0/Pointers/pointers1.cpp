#include <iostream>

//! Pointers:
//* 1. Pointer is a variable that stores the address of another variable of the same datatype.
//* 2. & = "address of" operator
//* 3. * = dereference operator

void pointer1(){
    std::cout<<"Basic of pointer: "<<std::endl;
    int num = 100;
    int* ptr = &num;

    int* ptr1 = 0;
    ptr1 = &num;

    std::cout<<"Address of num using &num: "<<&num<<std::endl;
    std::cout<<"Address of num using ptr: "<<ptr<<std::endl;
    std::cout<<"Value using num: "<<num<<std::endl;
    std::cout<<"Value using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Initialise using method 2: "<<ptr1<<std::endl;
    std::cout<<"Initialise using method 2: "<<*ptr1<<std::endl;
    (*ptr)+=10;
    std::cout<<"num: "<<num<<std::endl;
}

//! Pointers Arithmetic:
//* 1. We can access a value directly using "variable name" or using dereference operator as "*ptr".
//* 2. We can manipulate values using *ptr. 

void pointer2(){
    std::cout<<"Pointer arithmetic: "<<std::endl;
    int num = 120;
    int* ptr = &num;
    std::cout<<"Address of num using &num: "<<&num<<std::endl;
    std::cout<<"Address of num using ptr: "<<ptr<<std::endl;
    std::cout<<"Value using num: "<<num<<std::endl;
    std::cout<<"Value using *ptr: "<<*ptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Increment num by 1 using pointer: "<<(*ptr)+1<<std::endl;
    std::cout<<"Decrement num by 1 using pointer: "<<(*ptr)-1<<std::endl;
    std::cout<<"Multiply num by 10 using pointer: "<<(*ptr)*10<<std::endl;
    std::cout<<"Remainder when num divided by 7 using pointer: "<<(*ptr)%7<<std::endl;
}

//! Size of pointers:
//* 1. Size of pointer is of 8 bytes
//* 2. We can increment or decrement address using "ptr". If current address is 4, then "ptr+1" leads to 8 for int datatype
//* as size of int is 4.

void pointer3(){
    int num = 10;
    int* ptr = &num;
    std::cout<<"Size of value and address: "<<std::endl;
    std::cout<<"size of num: "<<sizeof(num)<<std::endl;
    std::cout<<"size of ptr: "<<sizeof(ptr)<<std::endl;
    std::cout<<"Address using ptr: "<<ptr<<std::endl;
    std::cout<<"Increment address by 1: "<<ptr+1<<std::endl;
    std::cout<<"Increment address by 2: "<<ptr+2<<std::endl;
}

//! Char datatype:
//* 1. We can access a char variable's hexadecimal address using "static_cast<void*>(ptr)"
void pointer4(){
    char c = 'A';
    char* ptr = &c;
    std::cout<<"Accessing value using c: "<<c<<std::endl;
    std::cout<<"Accessing value using pointer: "<<*ptr<<std::endl;
    std::cout<<"Accessing char address using &c: "<<&c<<std::endl;
    std::cout<<"Accessing char address using ptr: "<<ptr<<std::endl;
    std::cout<<"Accessing hexadecimal address: "<<static_cast<void*>(ptr)<<std::endl;
}

//! Copy pointers:
void pointer5(){
    int num = 100;
    int* ptr = &num;
    int* cptr = ptr;

    std::cout<<"Accessing num using num: "<<num<<std::endl;
    std::cout<<"Acessing num using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing num using copy pointer *cptr: "<<*cptr<<std::endl;
    std::cout<<"Accessing address using &num: "<<&num<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;
    std::cout<<"Accessing address using copy pointer cptr: "<<cptr<<std::endl;
    (*cptr)+=100;
    std::cout<<"Value of num after adding 100 using *cptr: "<<num<<std::endl;
}

int main(){
    pointer4();
    return 0;
}