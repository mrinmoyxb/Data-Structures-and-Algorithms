#include <iostream>

//! pointer 1 - basic pointer 
void pointer1(){
    int num = 5;
    int* ptr = &num;

    std::cout<<"num: "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"address of num(&num): "<<&num<<std::endl;
    std::cout<<"address of num(ptr): "<<ptr<<std::endl;
    std::cout<<"adding 1 to the value: "<<(*ptr+1)<<std::endl;
    std::cout<<"adding 1 to the address: (4bytes) "<<ptr+1<<std::endl;

    std::cout<<"Adding 2 to the value: "<<(*ptr+2)<<std::endl;
    std::cout<<"Adding 2 to the address: (8bytes) "<<ptr+2<<std::endl;

    std::cout<<"Multiplying 2 to the value: "<<(*ptr*2)<<std::endl;
    std::cout<<"Multiplying 2 to the value: "<<(num*2)<<std::endl;
}

//! pointer 2 - size of pointers
void pointer2(){
    int num = 5;
    int* ptr = &num;

    double num1 = 123.24;
    double* ptr1 = &num1;

    std::cout<<"Num is(num): "<<num<<std::endl;
    std::cout<<"Accessing using dereference operator(*ptr): "<<*ptr<<std::endl;
    std::cout<<"Address operator(&num): "<<&num<<std::endl;
    std::cout<<"Accessing using pointer(ptr): "<<ptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Num is(num): "<<num1<<std::endl;
    std::cout<<"Accessing using dereference operator(*ptr1): "<<*ptr1<<std::endl;
    std::cout<<"Address operator(&num1): "<<&num1<<std::endl;
    std::cout<<"Accessing using pointer(ptr1): "<<ptr1<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Size of pointer(ptr): "<<sizeof(ptr)<<std::endl;
    std::cout<<"Size of pointer(ptr1): "<<sizeof(ptr1)<<std::endl;
}

//! pointer 3 - arithmetic operations
void pointer3(){
    int num = 100;
    int* ptr = &num;

    std::cout<<"Num is num(num): "<<num<<std::endl;
    std::cout<<"Accessing using dereference operator(*ptr): "<<*ptr<<std::endl;
    std::cout<<"Address of(&num): "<<&num<<std::endl;
    std::cout<<"Address using pointer(ptr): "<<ptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Num(before): "<<num<<std::endl;
    (*ptr)+=1;
    std::cout<<"Num(after): "<<num<<std::endl;
}

//! Copy pointer
void pointer4(){
    int num = 100;
    int* ptr = &num;
    int* cptr = ptr;

    std::cout<<"Before: "<<std::endl;
    std::cout<<"Num(num): "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"*cptr: "<<*cptr<<std::endl;
    *cptr+=1;
    std::cout<<"After: "<<std::endl;
    std::cout<<"Num(num): "<<num<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"*cptr: "<<*cptr<<std::endl;
    std::cout<<std::endl;

    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"cptr: "<<cptr<<std::endl;
}

//! pointer to a pointer
void pointer5(){
    int num = 100;
    int* ptr1 = &num;
    int** ptr2 = &ptr1;

    std::cout<<"&num: "<<&num<<std::endl;
    std::cout<<"ptr1: "<<ptr1<<std::endl;
    std::cout<<"&ptr1: "<<&ptr1<<std::endl;
    std::cout<<"ptr2: "<<ptr2<<std::endl;
    std::cout<<std::endl;

    std::cout<<"*(&num): "<<*(&num)<<std::endl;
}

//! pointer: with respect to array
void pointer6(){
    int arr[3] = {10, 20, 30};

    std::cout<<"arr: "<<arr<<std::endl;
    std::cout<<"&arr[0]: "<<&arr[0]<<std::endl;
    std::cout<<"arr+1: "<<arr+1<<std::endl;
    std::cout<<"&arr[1]: "<<&arr[1]<<std::endl;
    std::cout<<"arr+2: "<<(arr+2)<<std::endl;
    std::cout<<"&arr[2]: "<<&arr[2]<<std::endl;
}

//! array
void pointer7(){
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout<<"arr: "<<arr<<std::endl;
    std::cout<<"&arr[0]: "<<&arr[0]<<std::endl;
    std::cout<<"*arr: "<<*arr<<std::endl;
    std::cout<<"arr[0]: "<<arr[0]<<std::endl;
    std::cout<<"*arr+1: "<<*arr+1<<std::endl;
    std::cout<<std::endl;
    std::cout<<"size of arr: "<<sizeof(arr)<<std::endl;
    std::cout<<"size of arr[0]: "<<sizeof(arr[0])<<std::endl;
    int* ptr = &arr[1];
    std::cout<<"arr[1]: "<<arr[1]<<std::endl;
    *ptr = 1000;
    std::cout<<"arr[1]: "<<arr[1]<<std::endl;
    
    std::cout<<"Printing the array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<*(arr+i)<<" ";
    }
}

//! array
void pointer8(){
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    std::cout<<"arr: "<<arr<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"arr[0]: "<<arr[0]<<std::endl;

    std::cout<<std::endl;
    std::cout<<"arr+1: "<<arr+1<<std::endl;
    std::cout<<"ptr+1: "<<ptr+1<<std::endl;
    std::cout<<"*(ptr+1): "<<*(ptr+1)<<std::endl;
    std::cout<<"arr[1]: "<<arr[1]<<std::endl;

    arr[2] = 3000;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<std::endl;
    *(ptr+3) = 9000;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! array in function
void checkArray(int *arr, int size){
    std::cout<<"INSIDE FUNCTION: "<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<*(arr+i)<<" ";
        if(i%2==0){
            *(arr+i) = 99999;
        }else{
            continue;
        }
    }
    
}

int main(){
    // pointer8();
    int arr[5] = {10, 20, 30, 40, 50};
    std::cout<<"\nARRAY Before Function: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
    checkArray(arr, 5);
    std::cout<<"\nARRAY After Function: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}