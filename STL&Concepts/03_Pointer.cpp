#include <iostream>
using std::cout;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Temp{
    public:
    int data;
    Temp(int data){
        this->data = data;
    }
};

//! Pointer is a variable that stores the address of another variable of same datatype
//! &variable = ptr = Returns the address of variable
//! num = *ptr = returns the value
//! *ptr = Dereference operator = value stored at address of ptr 
void concept1(){
    int num = 5;
    int* ptr = &num;

    cout<<"num: "<<num<<"\n";
    cout<<"*ptr: "<<*ptr<<"\n";
    cout<<"&num: "<<&num<<"\n";
    cout<<"ptr: "<<ptr<<"\n";
}

//! Memory allocation in heap
void concept2(){
    int* num = new int(10);
    cout<<"num: "<<num<<"\n";
    cout<<"*num: "<<*num<<"\n";
    delete num;
    cout<<"num: "<<num<<"\n";
    cout<<"*num: "<<*num<<"\n";
}

//! Custom datatype
//! "node->data" means "(*node).data"
void concept3(){
    Temp* t = new Temp(10);

    cout<<"t: "<<"\n";
    cout<<"t: "<<t<<"\n";
    cout<<"*t: "<<(*t).data<<"\n";
    cout<<"*t: "<<t->data<<"\n";
}

//! Custom datatype
void concept4(){
    Node* node1 = new Node(100);
    Node* node2 = new Node(200);

    cout<<"node1: "<<"\n";
    cout<<"Address of node1: "<<node1<<"\n";
    cout<<"Address of node1: "<<&(*node1).data<<"\n";
    cout<<"node1->data: "<<node1->data<<"\n";
    cout<<"(*node1).data: "<<(*node1).data<<"\n";
    cout<<"node1->next: "<<node1->next<<"\n";
    std::cout<<"\n";

    cout<<"node2: "<<"\n";
    cout<<"Address of node2: "<<node2<<"\n";
    cout<<"node2->data: "<<node2->data<<"\n";
    cout<<"(*node2).data: "<<(*node2).data<<"\n";
    cout<<"node2->next: "<<node2->next<<"\n";
    std::cout<<"\n";

    node1->next = node2;
    cout<<"node1->next: "<<node1->next<<"\n";
}

//! Initialising a pointer
void concept5(){
    int num = 10;
    int *ptr;
    ptr = &num;

    cout<<"num: "<<num<<"\n";
    cout<<"*ptr: "<<*ptr<<"\n";
    cout<<"&num: "<<&num<<"\n";
    cout<<"ptr: "<<ptr<<"\n";
}

//! Copying a pointer
void concept6(){
    int num = 10;
    int* ptr = &num;
    int* cptr = ptr;

    *cptr+=10;

    cout<<"Values: "<<"\n";
    cout<<"num: "<<num<<"\n";
    cout<<"*ptr: "<<*ptr<<"\n";
    cout<<"*cptr: "<<*cptr<<"\n";
    std::cout<<"\n";

    cout<<"Addresses: "<<"\n";
    cout<<"&num: "<<&num<<"\n";
    cout<<"ptr: "<<ptr<<"\n";
    cout<<"cptr: "<<cptr<<"\n";
}

//! Copy pointer can only modify the original value until it points to that address
void concept7(){
    int num1 = 100;
    int num2 = 999;

    int* ptr = &num1;
    int* cptr = ptr;

    cout<<"Before: "<<"\n";
    cout<<"Values: "<<"\n";
    cout<<"num: "<<num1<<"\n";
    cout<<"*ptr: "<<*ptr<<"\n";
    cout<<"*cptr: "<<*cptr<<"\n";
    std::cout<<"\n";

    cout<<"Addresses: "<<"\n";
    cout<<"&num: "<<&num1<<"\n";
    cout<<"ptr: "<<ptr<<"\n";
    cout<<"cptr: "<<cptr<<"\n";
    std::cout<<"\n";

    cout<<"After: "<<"\n";
    cptr = &num2;

    cout<<"Values: "<<"\n";
    cout<<"num: "<<num1<<"\n";
    cout<<"*ptr: "<<*ptr<<"\n";
    cout<<"*cptr: "<<*cptr<<"\n";
    std::cout<<"\n";

    cout<<"Addresses: "<<"\n";
    cout<<"&num: "<<&num1<<"\n";
    cout<<"ptr: "<<ptr<<"\n";
    cout<<"cptr: "<<cptr<<"\n";
    std::cout<<"\n";
}

//! Reference and pointers
//! Pass by value: here num is a copy pointer of number in main, hence copy pointer can point to different address
//! The address of "copy pointer(&num)" and "pointer in main(&number)" are different
void checkSum1(int* num){
    cout<<"Address of pointer num: "<<&num<<"\n";
    cout<<"address of num: "<<num<<"\n";
    int value = 999;
    num = &value;
}

//! Pass by reference
//! Address of &num and &number is same
void checkSum2(int* &num){
    cout<<"Address of pointer num: "<<&num<<"\n";
    cout<<"address of num: "<<num<<"\n";
    num = new int(100);
    cout<<"Address of pointer num: "<<&num<<"\n";
    cout<<"address of num: "<<num<<"\n";
}

int main(){
    int *number = new int(100);
    cout<<"Before: "<<*number<<"\n";
    cout<<"Before: "<<number<<"\n";
    cout<<"Address of pointer number: "<<&number<<"\n";

    std::cout<<"\n";
    checkSum2(number);

    std::cout<<"\n";
    cout<<"After: "<<*number<<"\n";
    cout<<"After: "<<number<<"\n";
    cout<<"Address of pointer number: "<<&number<<"\n";
    return 0;
}