#include <iostream>

//! inline functions are a feature that allows the compiler to
//! replace the function call with the actual code of the function during compilation. 
//! This can improve performance by eliminating the overhead of a function call,
//! particularly for small, frequently called functions.
inline int sum(int num1, int num2){
    return num1 + num2;
}

//! Dynamic allocation and deallocation
void dynamicMemory(){
    int* num = new int(10);
    float* num1 = new float(12.2f);

    std::cout<<"Address of num: "<<num<<"\n";
    std::cout<<"Value of num: "<<*num<<"\n";
    std::cout<<"\n";

    std::cout<<"Address of num1: "<<num1<<"\n";
    std::cout<<"Value of num2: "<<*num1<<"\n";

    delete num;
    delete num1;
    num = nullptr;
    num1 = nullptr;
}

int main(){
    // int n1 = 10, n2 = 20;
    // int result = sum(n1, n2);
    // std::cout<<"Result: "<<result;

    dynamicMemory();
    return 0;
}