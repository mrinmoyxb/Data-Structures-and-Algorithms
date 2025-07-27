#include <iostream>

// basic array and pointers
void pointers1(){
    int arr[5] = {11, 20, 31, 40, 55};
    
    std::cout<<"Traversing array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\naddress of the first element(arr): "<<arr<<std::endl;
    std::cout<<"address of the first element(&arr[0]): "<<&arr[0]<<std::endl;
    std::cout<<"value at the first position(arr[0]): "<<arr[0]<<std::endl;
    std::cout<<"value at the first position(*arr): "<<*arr<<std::endl;


    std::cout<<"\n\nAccessing values using pointers: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<"*(arr+"<<i<<"): "<<*(arr+i)<<std::endl;
    }

    std::cout<<"\nAccessing address using pointers: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<"(arr+"<<i<<"): "<<(arr+i)<<" "<<std::endl;
    }
    
    std::cout<<"\nList of addresses with positive values: "<<std::endl;
    for(int i=0; i<5; i++){
        if(*(arr+i)%2==0){
            std::cout<<"Address of positive value: "<<(arr+i)<<std::endl;
        }else{
            continue;
        }
    }
}

// array manipulation
void pointers2(){
    int arr[5] = {12, 30, 45, 99, 100};

    int* ptr = &arr[1];
    std::cout<<"Traversing array using pointers from index 1:"<<std::endl;
    for(int i=0; i<5-1; i++){
        std::cout<<*(ptr+i)<<" ";
    }

    std::cout<<"\nFinding even and odd elements in the array: "<<std::endl;
    ptr = arr;
    for(int i=0; i<5; i++){
        if(*(ptr+i)%2==0){
            std::cout<<"*(ptr+"<<i<<"): "<<*(ptr+i)<<" is even"<<std::endl;
            *(ptr+i) = *(ptr+i) * 20;
        }else{
            std::cout<<"*(ptr+"<<i<<"): "<<*(ptr+i)<<" is odd"<<std::endl;
        }
    }
    for(int i=0; i<5; i++){
        std::cout<<*(arr+i)<<" ";
    }
}

// array 
void pointers3(){
    std::cout<<"\nTraversing array using index[name of array]: "<<std::endl;
    int arr[5] = {10, 12, 50, 100, 120};
    for(int i=0; i<5; i++){
        std::cout<<i[arr]<<" ";
    }

    for(int i=0; i<5; i++){
        std::cout<<"\nvalue at index "<<i<<" using *(arr+i): "<<*(arr+i)<<std::endl;
        std::cout<<"value at index "<<i<<" using i[arr]: "<<i[arr]<<std::endl;
        std::cout<<"address at index "<<i<<" using (arr+i): "<<(arr+i)<<std::endl;
        std::cout<<"address at index "<<i<<" using &i[arr]: "<<&i[arr]<<std::endl;
        std::cout<<std::endl;
    }
}

// size of arrays
// array is fixed size which means we can't modify "arr = arr+1"
// but we can increase pointer as "ptr = ptr+1"

// In case of int array, array name prints address of the first element, whereas in case of char, it prints the entire array
void pointers4(){
    int arr[5] = {10, 22, 30, 42, 50};
    int* ptr = arr;
    std::cout<<"size of arr: "<<sizeof(arr)<<std::endl;
    std::cout<<"size of ptr: "<<sizeof(ptr)<<std::endl;
}

void pointers5(){
    char c[5] = "abcd";
    char* ptr = &c[0];

    std::cout<<"c: "<<c<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<std::endl;

    for(int i=0; i<5-1; i++){
        std::cout<<static_cast<void*>(ptr+i)<<std::endl;
        std::cout<<*(ptr+i)<<std::endl;
    }
    
}

// This is a copy of the pointer both pointing to the same address
void pointersAndFunc(int* ptr){
    std::cout<<"\nInside function: "<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
    std::cout<<"&ptr: "<<&ptr<<std::endl;

    *ptr+=100;
    std::cout<<"\nUpdated value inside the function"<<std::endl;
    std::cout<<"*ptr: "<<*ptr<<" ---- "<<"ptr: "<<ptr<<std::endl;

    ptr+=1;
    std::cout<<"\nUpdated the address inside the function"<<std::endl;
    std::cout<<"ptr: "<<ptr<<std::endl;
}

// array
void pointersAndArray(int* arr, int size){
    std::cout<<"function: "<<std::endl;
    std::cout<<"size of array: "<<sizeof(arr)<<std::endl;
    std::cout<<"address of array: "<<arr<<std::endl;
    std::cout<<"address of arr[0]: "<<&arr[0]<<std::endl;

    int sum = 0;
    for(int i=0; i<size; i++){
        sum+=i[arr];
    }
    std::cout<<"sum: "<<sum<<std::endl;
}

int main(){

    // int num = 10;
    // int* ptr = &num;

    // std::cout<<"\nInside main: "<<std::endl;
    // std::cout<<"num: "<<num<<std::endl;
    // std::cout<<"*ptr: "<<*ptr<<std::endl;
    // std::cout<<"&num: "<<&num<<std::endl;
    // std::cout<<"ptr: "<<ptr<<std::endl;
    // std::cout<<"&ptr: "<<&ptr<<std::endl;

    // pointersAndFunc(ptr);
    // std::cout<<"\nValue inside main after update: "<<std::endl;
    // std::cout<<"num: "<<num<<std::endl;
    // std::cout<<"*ptr: "<<*ptr<<std::endl;

    // std::cout<<"\nAddress inside main after update: "<<std::endl;
    // std::cout<<"&num: "<<&num<<std::endl;
    // std::cout<<"ptr: "<<ptr<<std::endl;

    int arr[5] = {1, 2, 3, 4, 5};
    std::cout<<"main: "<<std::endl;
    std::cout<<"size of array: "<<sizeof(arr)<<std::endl;
    std::cout<<"address of array: "<<arr<<std::endl;
    std::cout<<"address of arr[0]: "<<&arr[0]<<std::endl;
    
    pointersAndArray(arr, 5);
    
    return 0;
}