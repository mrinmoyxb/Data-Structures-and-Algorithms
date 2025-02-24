#include <iostream>

void displayArray(int *arr, int size){
    if(size==0){
        return;
    }
    std::cout<<*arr<<" ";
    displayArray(arr+1, size-1);
}

void checkForEven(int* arr, int size){
    if(size==0){
        return;
    }

    if(*arr%2==0){
        std::cout<<*arr<<" is Even"<<"\n";
        checkForEven(arr+1, size-1);
    }else{
        checkForEven(arr+1, size-1);
    }
}

void printReverseArray(int* arr, int size){
    if(size==0){
        return;
    }
    std::cout<<arr[size-1]<<" ";
    printReverseArray(arr, size-1);
}

int sumOfNum(int* arr, int size){
    if(size==0){
        return 0;
    }
    return *arr + sumOfNum(arr+1, size-1);
}

void printNums(int num){
    if(num==0){
        return;
    }
    printNums(num-1);
    
}
int main(){
    int* arr = new int[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    //displayArray(arr, 5);
    //checkForEven(arr, 5);
    //printReverseArray(arr, 5);
    std::cout<<"Result: "<<sumOfNum(arr, 5);
    return 0;
}