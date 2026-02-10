#include <iostream>

void p1(){
    int num = 10;
    int* ptr = &num;

    double num1 = 20;
    double* ptr1 = &num1;

    char c = 'A';
    char* ptr2 = &c;

    int* z = nullptr;
    z = &num;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"value of num using *ptr: "<<*ptr<<std::endl;
    std::cout<<"address of num using &num: "<<&num<<std::endl;
    std::cout<<"address of num using ptr: "<<ptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"num1: "<<num1<<std::endl;
    std::cout<<"value of num1 using *ptr1: "<<*ptr1<<std::endl;
    std::cout<<"address of num1 using &num1: "<<&num1<<std::endl;
    std::cout<<"address of num1 using ptr1: "<<ptr1<<std::endl;
    std::cout<<std::endl;

    std::cout<<"c: "<<c<<std::endl;
    std::cout<<"value of c using *ptr2: "<<*ptr2<<std::endl;
    std::cout<<"address of c using &c: "<<static_cast<const void*>(&c)<<std::endl;
    std::cout<<"address of c using ptr2: "<<static_cast<const void*>(ptr2)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"num: "<<std::endl;
    std::cout<<"value of num using *z: "<<*z<<std::endl;
    std::cout<<"address of num using &z: "<<&z<<std::endl;
    std::cout<<"address of num using z: "<<z<<std::endl;
}

void p2(){
    int num = 100;
    int* ptr = &num;
    int* cptr = ptr;

    std::cout<<"address of num using &num: "<<&num<<std::endl;
    std::cout<<"address of num using ptr: "<<ptr<<std::endl;
    std::cout<<"address of num using cptr: "<<cptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"value of num using num: "<<num<<std::endl;
    std::cout<<"value of num using *ptr: "<<*ptr<<std::endl;
    std::cout<<"value of num using *cptr: "<<*cptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"address of ptr using &ptr: "<<&ptr<<std::endl;
    std::cout<<"address of cptr using &cptr: "<<&cptr<<std::endl;
    std::cout<<std::endl;

    *cptr += 100;

    std::cout<<"value of num: "<<num<<std::endl;
    std::cout<<"value of num using *ptr: "<<*ptr<<std::endl;
    std::cout<<"value of num using *cptr: "<<*cptr<<std::endl;
    std::cout<<std::endl;

    ptr += 1;

    std::cout<<"*ptr: "<<*ptr<<", "<<"*cptr: "<<*cptr<<", "<<std::endl;
}

void p3(){
    int num = 100;
    int* ptr = &num;

    std::cout<<"num using *ptr: "<<*ptr<<std::endl;

    *ptr += 100;

    std::cout<<"num after add: "<<*ptr<<std::endl;

    *ptr*=100;

    std::cout<<"num after mul: "<<*ptr<<std::endl;
}

void p4(){
    int arr[5] = {10, 20, 30, 40, 50};

    int* ptr = arr;
    std::cout<<"address of the first element: "<<arr<<std::endl;
    std::cout<<"address of the first element: "<<&arr[0]<<std::endl;
    std::cout<<"address of the first element: "<<(ptr+0)<<std::endl;
    std::cout<<std::endl;

    int* ptr1 = arr;
    for(int i=0; i<5; i++){
        std::cout<<"address of index "<<i<<": "<<(ptr+i)<<std::endl;
        std::cout<<"value at index "<<i<<": "<<*(ptr1+i)<<std::endl;
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

    for(int i=0; i<5; i++){
        std::cout<<"address of index "<<i<<": "<<(arr+i)<<std::endl;
        std::cout<<"value at index "<<i<<": "<<*(arr+i)<<std::endl;
        std::cout<<std::endl;
    }

    ptr += 1;
    std::cout<<"incremented the address of first value: "<<ptr<<std::endl;
    std::cout<<"updated value: "<<*ptr<<std::endl;
}

void p5(){
    char c[6] = "abcde";
    char* ptr = c;
    std::cout<<"c: "<<c<<std::endl;
    std::cout<<"c[0]: "<<static_cast<void*>(&c[0])<<std::endl;
    std::cout<<"c[0]: "<<static_cast<void*>(ptr)<<std::endl;
}

void p6(int* ptr){
    std::cout<<"address stored by the pointer: "<<ptr<<std::endl;
    std::cout<<"address of the pointer: "<<&ptr<<std::endl;
    ptr+=1;
    std::cout<<"address stored by the pointer: "<<ptr<<std::endl;
}

void p7(int* arr, int s, int e){
    for(int i=s; i<e; i++){
        std::cout<<*(arr+i)<<std::endl;
    }
}

void p8(){
    int num = 100;
    int* ptr1 = &num;
    int** ptr2 = &ptr1;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr1: "<<*ptr1<<std::endl;
    std::cout<<"**ptr2: "<<**ptr2<<std::endl;
    std::cout<<std::endl;

    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr1: "<<ptr1<<std::endl;
    std::cout<<"*ptr2: "<<*ptr2<<std::endl;
    std::cout<<std::endl;

    std::cout<<"&ptr1: "<<&ptr1<<std::endl;
    std::cout<<"ptr3: "<<ptr2<<std::endl;

}

int main(){
    p8();

    return 0;
}