#include <iostream>

void cptr(){
    int num = 100;
    int* ptr = &num;

    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<std::endl;

    int* cptr = ptr;

    std::cout<<"cptr: "<<cptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"*cptr: "<<*cptr<<std::endl;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<std::endl;

    *cptr+=100;

    std::cout<<"*cptr: "<<*cptr<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<std::endl;

    cptr+=1;

    std::cout<<"cptr: "<<cptr<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<std::endl;
}

void print(int* ptr){
    std::cout<<"address stored inside num (ptr): "<<ptr<<std::endl;
    std::cout<<"value of (*ptr): "<<(*ptr)<<std::endl;
    std::cout<<"address of the ptr: "<<&ptr<<std::endl;

    ptr = ptr+1;

    std::cout<<"address inside ptr increased by 4 bytes: "<<ptr<<std::endl;
}

int main(){
    int num = 10;
    int* ptr = &num;

    std::cout<<"num(num): "<<num<<std::endl;
    std::cout<<"num(*ptr): "<<*ptr<<std::endl;
    std::cout<<"address stored inside (ptr): "<<ptr<<std::endl;
    std::cout<<"address of num(&num): "<<&num<<std::endl;
    std::cout<<"address of the ptr(&ptr): "<<&ptr<<std::endl;
    std::cout<<std::endl;

    int* ptr = NULL;
    // print(ptr);

    // std::cout<<"address stored inside ptr: "<<ptr<<std::endl;
    cptr();
    return 0;
}