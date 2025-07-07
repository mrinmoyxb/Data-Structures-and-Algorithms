#include <iostream>

//! KEY CONCEPT:
//! Function arguments are passed by value, even with pointers. The address is a copy.
//* 1. In C++, function arguments are passed by value, even if we're passing a pointer, 
//* the pointer itself (i.e. the address) is passed by value.

//* 2. Here, ptr is a local copy of the address, because of which if we increment address by 1,
//* it's visible only inside the function not outside.

//* 3. *ptr inside function, Dereferences and modifies actual memory because even though function receives 
//* a copy of the address, it's still a valid address and we can access and modify it using *ptr.

void pointers1(int* ptr){
    ptr = ptr+1;
    *ptr+=10;
}

//! Modifying a value using *ptr inside the function
void pointers2(int* ptr){
    std::cout<<"\nInside Function: "<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;
    *ptr += 10;
}

void pointers3(int* cptr){
    std::cout<<"\nInside Function: "<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*cptr<<std::endl;
    std::cout<<"Accessing address using ptr: "<<cptr<<std::endl;
    *cptr += 10;
}

int main(){
    int num = 10;
    int* ptr = &num;
    std::cout<<"Before: "<<std::endl;
    std::cout<<"Accessing value using num: "<<num<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing value using &num: "<<&num<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;

    pointers2(ptr);
    std::cout<<"\nAfter: "<<std::endl;
    std::cout<<"Accessing value using num: "<<num<<std::endl;
    std::cout<<"Accessing value using *ptr: "<<*ptr<<std::endl;
    std::cout<<"Accessing value using &num: "<<&num<<std::endl;
    std::cout<<"Accessing address using ptr: "<<ptr<<std::endl;

    return 0;
}