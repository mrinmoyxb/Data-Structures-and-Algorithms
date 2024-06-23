#include <iostream>
using namespace std;

//* BASICS: 
void pointer1(){

    int num1 = 100;
    int *ptr1 = &num1;
    cout<<"num1 (value): "<< num1<<endl;
    cout<<"*ptr1 (value): "<< *ptr1<<endl;
    cout<<"&num1 (address): "<< &num1<<endl;
    cout<<"ptr1 (address): "<< ptr1<<endl;
}

//* WITH VALUE:
void pointer2(){
    
    int num2 = 100;
    int *ptr1 = &num2;
    cout<<"num2 (value): "<< num2<<endl;
    cout<<"*ptr1 (value): "<< *ptr1<<endl;
    cout<<"&num2 (address): "<< &num2<<endl;
    cout<<"ptr1 (address): "<< ptr1<<endl;

    cout<<"\nNumericals: "<<endl;
    cout<<"Before: "<<endl;
    cout<<"num2: "<<num2<<endl;
    cout<<"*ptr1: "<<ptr1<<endl;
    cout<<"(*ptr1) += 100"<<endl;

    (*ptr1) += 100;

    cout<<"After: "<<endl;
    cout<<"num2: "<<num2<<endl;
    cout<<"*ptr1: "<<*ptr1<<endl;
}


//! IMPORTANT CONCEPT: 
//* WITH ADDRESS:
void pointer3(){
    
    int num = 100;
    int *ptr = &num;
    cout<<"num (value): "<< num<<endl;
    cout<<"*ptr (value): "<< *ptr<<endl;
    cout<<"&num (address): "<< &num<<endl;
    cout<<"ptr (address): "<< ptr<<endl;

    (ptr) += 1;

    cout<<endl;
    cout<<"ptr+1"<<endl;
    cout<<"&num: "<<&num<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"*ptr: "<<*ptr<<endl;

}


//* COPY POINTERS:
void pointer4(){
    int num = 100;
    int *ptr = &num;
    int *copyPointer = ptr;

    cout<<"\nCopy Pointer(VALUES): "<<endl;
    cout<<"num: "<< num<<endl;
    cout<<"*ptr: "<< *ptr<<endl;
    cout<<"*copy pointer: "<< *copyPointer<<endl;

    cout<<"\nCopy Pointer(ADDRESS): "<<endl;
    cout<<"&num: "<< &num<<endl;
    cout<<"ptr: "<< ptr<<endl;
    cout<<"copyPointer: "<< copyPointer<<endl;

    cout<<"\nUpdating value using copy pointer: "<<endl;
    cout<<"(*copyPointer) += 100: "<<endl;
    (*copyPointer) += 100;
    cout<<"num: "<<num<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"*copyPointer: "<<*copyPointer<<endl;

    cout<<"\nUpdating the address using copy pointer: "<<endl;
    cout<<"copyPointer + 1"<<endl;
    copyPointer += 1;
    cout<<"&num: "<<&num<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"copyPointer: "<<copyPointer<<endl;
    cout<<"num: "<<num<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"*copyPointer: "<<*copyPointer<<endl;
}


int main(){

    pointer1();
    cout<<endl;
    pointer2();
    cout<<endl;
    pointer3();
    cout<<endl;
    pointer4();
    return 0;
}

//* What I learnt?

//? &: address of operator
//? dataType *ptr: syntax to create a pointer

//* < *ptr > = accessing the value
//* < ptr > = accessing the address of the variable
//* < (*ptr) += 1 >: incrementing the value of variable by 1
//* < (ptr + 1) >: incrementing the address of the variable by the size of the datatype of that specfic variable

// ! Important Concpet
//* when I increment the size using < ptr + 1 >; we shift the ptr to the next location hence the value the address points also changes.
//* The address of < ptr > and < &num > will be different after < ptr + 1 > 
//* The new address of < ptr > stores new value which is different from num

//! Important Concept
//* When I create a copy pointer: < int *copy = ptr > both *copy and *ptr refers to same value, hence i can perform manipualtions using *copy
//* When I increment the address the copy is storing by 1: < copy += 1 > it doesn't affect the address the ptr is storing,
//* The address stored as well as the value inside < copy > and < copy > pointing gets updated.


