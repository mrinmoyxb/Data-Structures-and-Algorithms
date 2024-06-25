#include <iostream>
using namespace std;

int main(){

    int num = 10;
    int *ptr = &num;

    cout<<"num: "<< num<<endl;
    cout<<"*ptr: "<< *ptr<<endl;
    cout<<"ptr: "<< ptr<<endl;
    cout<<"&num: "<< &num<<endl;

    cout<<endl;
    cout<<"Copy of pointer: "<<endl;
    int *copy = ptr;
    

    cout<<"*ptr: "<< *ptr<<endl;
    cout<<"*copy: "<< *copy<<endl;
    cout<<"ptr: "<< ptr<<endl;
    cout<<"copy: "<< copy<<endl;
    (*ptr)+=1;
    cout<<"(*ptr)+1: "<<*ptr<<endl;
    cout<<"(*copy)+1: "<<*copy<<endl;
    (*copy)+=1;
    cout<<"(*copy)+1: "<<*copy<<endl;
    cout<<"(*ptr): "<<*ptr<<endl;


    cout<<endl;
    cout<<"Modification of address: "<<endl;
    cout<<"&num(Address): "<<&num<<endl;
    cout<<"ptr(Address): "<<ptr<<endl;
    cout<<"copy(Address): "<<copy<<endl;
    cout<<"ptr(Value): "<<*ptr<<endl;
    cout<<"copy(Value): "<<*copy<<endl;

    cout<<endl;
    cout<<"Increasing the address of ptr: "<<endl;
    (ptr)+=1;
    cout<<"&num(Address): "<<&num<<endl;
    cout<<"ptr(Address): "<<ptr<<endl;
    cout<<"copy(Address): "<<copy<<endl;
    cout<<"ptr(Value): "<<*ptr<<endl;
    cout<<"copy(Value): "<<*copy<<endl;

    cout<<endl;
    cout<<"Increasing the address of copy: "<<endl;
    (copy)+=1;
    cout<<"&num(Address): "<<&num<<endl;
    cout<<"ptr(Address): "<<ptr<<endl;
    cout<<"copy(Address): "<<copy<<endl;
    cout<<"ptr(Value): "<<*ptr<<endl;
    cout<<"copy(Value): "<<*copy<<endl;
    
    return 0;
}

//! KEY CONCEPTS:

//* When I increment the value of value of variable using < *ptr > or < *copy >, the updated value is common to both < *ptr > and < *copy >
//* When I increment the value of address of variable using < ptr+1 > or < copy+1 >, the updated address is only accessible to the one who perfromed it