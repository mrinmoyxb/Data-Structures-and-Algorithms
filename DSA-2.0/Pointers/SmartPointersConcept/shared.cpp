#include <iostream>

class UDT{
    public:
    UDT(){
        std::cout<<"UDI Created"<<std::endl;
    }
    ~UDT(){
        std::cout<<"UDI Destroyed"<<std::endl;
    }
};

int main(){
    std::shared_ptr<UDT> ptr = std::make_shared<UDT>();
    std::shared_ptr<UDT> ptr1 = ptr;

    std::cout<<"Use Count: "<<ptr.use_count()<<std::endl;
    return 0;
}