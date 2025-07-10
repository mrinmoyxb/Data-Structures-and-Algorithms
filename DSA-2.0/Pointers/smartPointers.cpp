#include <iostream>
#include <memory>

//! Smart Pointers - note
//* A smart pointer provided by the Standard Library (<memory>) that manages the lifetime 
//* of a dynamically allocated object using reference counting.

//! Shared Pointer - note
//* 1. Multiple shared_ptrs can point to the same object.
//* 2. The object is destroyed when the last shared_ptr goes out of scope or is reset.
//* 3. Internally keeps a reference count (use count).

//! Unique Pointer - note
//* 1. Single ownership

//! Shared Pointer - Multiple ownership
//* We can use use_count() method to check number of pointers sharing the pointer
std::shared_ptr<int> getSData(){
    std::shared_ptr<int> num = std::make_shared<int>(5);
    return num;
}

//! Unique Pointer - Single Ownership
//* We can move the ownership of unique_ptr to some other ptr
//* std::unique_ptr<int> a = getData();
//* std::unique_ptr<int> c = std::move(a);
std::unique_ptr<int> getUData(){
    std::unique_ptr<int> num = std::make_unique<int>(5);
    return num;
}

int main(){
    std::shared_ptr<int> result = std::make_shared<int>(10);
    std::shared_ptr<int> cresult = result;
    // std::cout<<result.use_count()<<std::endl;

    // std::unique_ptr<int> result = getUData();
    // std::unique_ptr<int> cresult = std::move(result);

    std::cout<<*result<<std::endl;
    std::cout<<*cresult<<std::endl;
}