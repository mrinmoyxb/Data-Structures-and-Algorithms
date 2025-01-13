#include <iostream>

void displayNumbers(int num){
    if(num<1){
        return;
    }

    displayNumbers(num-1);
    std::cout<<num<<std::endl;
}

void displayReverse(int num){
    if(num<1){
        return;
    }
    std::cout<<num<<std::endl;
    displayReverse(num-1);
}

void displayArray(int *arr, int size){
    if(size==0){
        return; 
    }

    std::cout<<*arr<<std::endl;
    displayArray(arr+1, size-1);
}

void reverseArrayUsingLoop(int *arr, int size){
    std::cout<<"\nReverse array: "<<std::endl;
    int start = 0;
    int end = size-1;
    while(start<=end){
        std::swap(arr[start], arr[end]);
        start+=1;
        end-=1;
    }

    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
}

void reverseArrayUsingRecursion1(int* arr, int size, int i=0){
    if(size==0){
        return;
    }
    reverseArrayUsingRecursion1(arr+1, size-1);
    std::cout<<arr[0]<<std::endl;
}

void reverseArrayUsingRecursion2(int* &arr, int start, int end){
    if(start>end){
        return;
    }

    std::swap(arr[start], arr[end]);
    reverseArrayUsingRecursion2(arr, start+1, end-1);
}

void reverseArrayUsingRecursion3(int* arr, int size){
    if(size==0){
        return;
    }
    reverseArrayUsingRecursion3(arr+1, size-1);
    std::cout<<*arr<<std::endl;
}

int main(){
    displayNumbers(5);
    std::cout<<std::endl;
    displayReverse(5);
    std::cout<<std::endl;

    int *arr = new int[5];
    std::cout<<"\nEnter elements: "<<std::endl;
    for(int i=0; i<5; i++){
        int element;
        std::cout<<"Enter element: ";
        std::cin>>element;
        i[arr] = element;
    }
    displayArray(arr, 5);
    // reverseArrayUsingLoop(arr, 5);

    std::cout<<std::endl;
    std::cout<<"\nReverse array using recursion"<<std::endl;
    int size = 5;

    reverseArrayUsingRecursion1(arr, size);
    return 0;
}