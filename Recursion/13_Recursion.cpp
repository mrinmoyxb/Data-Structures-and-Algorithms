#include <iostream>

//! Display array
void displayArr(int* arr, int size){
    if(size==0){
        return;
    }
    std::cout<<*arr<<" ";
    displayArr(arr+1, size-1);
}

//! Square of each element
void squared(int* arr, int size){
    if(size==0){
        return;
    }
    std::cout<<(*arr * *arr)<<" ";
    squared(arr+1, size-1);
}

//! Even and odd elements in an array
void findEven(int* arr, int size){
    if(size==0){
        return;
    }
    if(*arr%2==0){
        std::cout<<*arr<<" is even"<<"\n";
        findEven(arr+1, size-1);
    }else{
        findEven(arr+1, size-1);
    }
}

//! Sum of elements in an array
int sum(int* arr, int size){
    if(size==0){
        return 0;
    }
    return *arr + sum(arr+1, size-1);
}

//! Check prime
bool checkPrime(int num){
    if(num<2){
        return false;
    }

    for(int i=2; i<num; i++){
        if(num%i==0){
            return false;
        }
    }
    return checkPrime(num-1);
}

int main(){
    int arr[5] = {10, 20, 30, 40, 50};

    std::cout<<"Array: "<<"\n";
    displayArr(arr, 5);

    std::cout<<"\nSqaured elements in array: "<<"\n";
    squared(arr, 5);

    std::cout<<"\nEven values: "<<"\n";
    findEven(arr, 5);

    std::cout<<"\nSum of elements: "<<sum(arr, 5);

    return 0;
}
