#include <iostream>

//! Reference Variable
//* 1. A reference is an alias for another variable. Once a reference is set to a variable, it cannot be changed to refer to another variable. 
//* 2. Refering to the same memory location but different names.
//* 3. Memory address of original variable == reference variable

void ref1(){
    int num = 5;
    int& numRef = num;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"numRef: "<<numRef<<std::endl;
    std::cout<<"Address of num: "<<&num<<std::endl;
    std::cout<<"Address of numRef: "<<&numRef<<std::endl;
}

//! Pass by reference
void ref2(int& ref){
    std::cout<<"\nInside function using reference: "<<std::endl;
    std::cout<<"ref: "<<ref<<std::endl;
    std::cout<<"&ref: "<<&ref<<std::endl;
    ref+=100;
}

int main(){
    // ref1();
    int num = 900;
    std::cout<<"\nBefore: "<<std::endl;
    std::cout<<"ref: "<<num<<std::endl;
    std::cout<<"&ref: "<<&num<<std::endl;

    ref2(num);

    std::cout<<"\nAfter: "<<std::endl;
    std::cout<<"ref: "<<num<<std::endl;
    std::cout<<"&ref: "<<&num<<std::endl;
    return 0;
}