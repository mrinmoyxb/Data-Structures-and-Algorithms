#include <iostream>

//* Stack: Lifetime of a variable ends when a function returns 
//* Heap: Lifetime of a variable exists until we manually delete that variable

//! Function 1:
//? new int(10) allocates memory on the heap, which remains valid until you explicitly free it using delete
//? So returning num (a heap-allocated pointer) is safe, and no warning is typically issued
int* getData(){
    int* num = new int(10);
    return num;
}

//! Function 2:
//* num is a local variable stored on the stack. Once the function returns, that stack frame is destroyed, and num no longer exists.
//* ptr is pointing to invalid memory (dangling pointer), which leads to undefined behavior if dereferenced.
int* getData(){
    int num = 10;
    int* ptr = &num;
    return ptr;
}

//! Resource Acquisition Is Initialization
class Wrapper{
    private:
        int* mem;

    public:
        Wrapper(int* a): mem(a){
            std::cout<<"Constructor Called"<<std::endl;
        }
        ~Wrapper(){
            delete mem;
        }
};

int main(){
    Wrapper obj(new int(10));
}