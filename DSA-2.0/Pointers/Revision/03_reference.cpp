#include <iostream>

//! Overloading new: 
//* void* operator new(size_t size)
//* void* operator new(size_t size)

class MyClass {
public:
    void* operator new(size_t size) {
        std::cout << "Custom new for MyClass\n";
        return ::operator new(size); 
    }
};

void ref1(){
    int num = 100;
    int& refNum = num;
    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"refNum: "<<refNum<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"&refNum: "<<&refNum<<std::endl;

    refNum+=10;
    std::cout<<"\nnum: "<<num<<std::endl;
    std::cout<<"refNum: "<<refNum<<std::endl;

    int* ptr = &refNum;
    *ptr+=10;
    std::cout<<"\nnum: "<<num<<std::endl;
    std::cout<<"refNum: "<<refNum<<std::endl;

    ptr+=1;
    std::cout<<"\nptr: "<<ptr<<std::endl;
    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"&refNum: "<<&refNum<<std::endl;
}

void updateRef(int& ref_num){
    ref_num+=1;
    std::cout<<"&num: "<<&ref_num<<std::endl;
}

void dynamicAll(){
    int* pnum = new int(10);
    std::cout<<"\nsize of pnum: "<<sizeof(pnum)<<std::endl;
    std::cout<<"size of int: "<<sizeof(int)<<std::endl;
    delete pnum;
}

void dynamicArr(){

}

int main(){

    // int num = 100;
    // std::cout<<"num(before): "<<num<<std::endl;
    // std::cout<<"&num: "<<&num<<std::endl;
    // updateRef(num);
    // std::cout<<"num(after): "<<num<<std::endl;
    // std::cout<<"&num: "<<&num<<std::endl;

    // dynamicAll();

    MyClass* obj = new MyClass;

    return 0;
}