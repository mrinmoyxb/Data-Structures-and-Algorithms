#include <iostream>
#include <memory>

class UDT{
    public:
    UDT(){
        std::cout<<"UDT Created"<<std::endl;
    }
    ~UDT(){
        std::cout<<"UDT Destroyed"<<std::endl;
    }
    void greet(){
        std::cout<<"Unique pointer"<<std::endl;
    }
};

//! Unique Pointers: unique_ptr
//? std::unique_ptr<int> num = std::make_unique<int>(10);
//* std::make_unique<MyClass>() = new MyClass(), so the MyClass instance lives on the heap
//* unique_ptr exists because it manages heap-allocated memory automatically so you don’t have to call delete yourself.

//! Moving Ownership:
//? std::unique_ptr<int> num1 = std::move(num);

int main(){
    std::unique_ptr<UDT> num1 = std::make_unique<UDT>();
    std::cout<<"Num: "<<num1<<std::endl;
    num1->greet();

    std::unique_ptr<UDT> num2 = std::move(num1);
    
    num1.release();

    num1.swap(num2);
    return 0;
}