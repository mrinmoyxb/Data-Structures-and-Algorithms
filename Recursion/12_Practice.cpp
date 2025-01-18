#include <iostream>

//! Factorial of a number
int factorial(int num){
    if(num==0){
        return 1;
    }

    return num * factorial(num-1);
}

//! Display array
void displayArray(int *arr, int size){
    if(size==0){
        return;
    }

    std::cout<<*arr<<" ";
    displayArray(arr+1, size-1);
}

//! Reverse array
void displayReverseArray(int *arr, int size){
    if(size==0){
        return;
    }
    displayReverseArray(arr+1, size-1);
    std::cout<<*arr<<" ";
}

//! Natural numbers
void printNaturalNum(int num){
    if(num<1){
        return;
    }
    printNaturalNum(num-1);
    std::cout<<num<<" ";
}

//! Reverse natural numbers
void printRevNaturalNum(int num){
    if(num<1){
        return;
    }
    std::cout<<num<<" ";
    printRevNaturalNum(num-1);
}

//! Sum of natural numbers
int sumOfNum(int num){
    if(num<1){
        return 0;
    }
    return num + sumOfNum(num-1);
}

//! Sum of elements in an array
int sumOfArray(int *arr, int size){
    if(size==0){
        return 0;
    }
    return *arr + sumOfArray(arr+1, size-1);
}

int max(int num1, int num2){
    return num1>num2 ? num1 : num2;
}

//! Max element in an array
int maxElement(int *arr, int size){
    if(size==1){
        return *arr;
    }

    return max(*arr, maxElement(arr+1, size-1));
}

//! Check even or odd
void checkEvenOdd(int num){
    if(num==0){
        return;
    }

    checkEvenOdd(num-1);

    if(num%2==0){
        std::cout<<num<<" is even"<<"\n";
    }else{
        std::cout<<num<<" is odd"<<"\n";
    }
}

//! Check prime
void checkPrime(int num){
    if(num<2){
        return;
    }

    bool isPrime = true;
    for(int i=2; i<num; i++){
        if(num%i==0){
            isPrime = false;
            break;
        }
    }

    if(isPrime){
        std::cout<<num<<" is prime"<<"\n";
    }else{
        std::cout<<num<<" is composite"<<"\n";
    }

    checkPrime(num-1);
}

//! Square of number
void squaredOfNum(int num){
    if(num==0){
        return;
    }
    squaredOfNum(num-1);
    std::cout<<"sqaure of "<<num<<" is: "<<num*num<<"\n";
}

//! Divisible by 9
void checkDivisible(int start, int end){
    if(start>end){
        return;
    }

    if(start%9==0){
        std::cout<<start<<" is divisible by 9"<<"\n";
    }

    checkDivisible(start+=1, end);
}

//! Linear search
bool linearSearch(int *arr, int size, int key){
    if(size==0){
        return false;
    }

    if(*arr==key){
        return true;
    }else{
        return linearSearch(arr+1, size-1, key);
    }
}

int main(){
    //std::cout<<"Factorial of 6: "<<factorial(6)<<"\n";
    int *arr = new int[5];
    std::cout<<"Array: "<<"\n";
    for(int i=0; i<5; i++){
        int element;
        std::cout<<"Enter an element: ";
        std::cin>>element;
        arr[i] = element;
    }

    //displayArray(arr, 5);
    // std::cout<<"\n";
    // displayReverseArray(arr, 5);
    // std::cout<<"\n";
    //std::cout<<"Sum: "<<sumOfArray(arr, 5);
    //std::cout<<"Max: "<<maxElement(arr, 5);

    // printNaturalNum(5);
    // std::cout<<"\n";
    // printRevNaturalNum(5);
    // std::cout<<"\n";

    // std::cout<<"Sum of natural numbers: "<<sumOfNum(5);
    //checkEvenOdd(10);
    //checkPrime(10);
    //squaredOfNum(10);
    //checkDivisible(100, 200);

    std::cout<<"Linear Search: "<<linearSearch(arr, 5, 900)<<"\n";
    return 0;
}