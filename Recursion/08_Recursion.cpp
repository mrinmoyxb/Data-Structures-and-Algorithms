#include <iostream>

//! Print names
void printName(int num){
    if(num==0){
        return;
    }

    std::cout<<"ABC"<<std::endl;
    num-=1;
    printName(num);
}

//! Print numbers 1 to N
void printNum(int num){
    if(num==0){
        return;
    }
    printNum(num-1);
    std::cout<<num<<std::endl;
}

//! Print reverse N to 1
void printNumReverse(int num){
    if(num==0){
        return;
    }
    std::cout<<num<<std::endl;
    printNumReverse(num-1);
}

//! Sum of first n numbers
void sumOfNums(int *arr, int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum+=arr[i];
    }
    std::cout<<"Sum: "<<sum<<std::endl;
}

//! Sum of first n numbers: recursion
int sumOfNumsRecursion(int *arr, int size){
    if(size==0){
        return *arr;
    }

    return *arr + sumOfNumsRecursion(arr+1, size-1);
}

//! Display array
void displayArray(int *arr, int size){
    if(size==0){
        return;
    }
    std::cout<<*arr<<std::endl;
    displayArray(arr+1, size-1);
}

//! Reverse array using recursion
void displayArrayRecursion(int *arr, int size){
    if(size==0){
        return;
    }

    displayArrayRecursion(arr+1, size-1);
    std::cout<<*arr<<std::endl;
}

//! Sum of natural numbers
int sumOfNums(int num){
    if(num==0){
        return 0;
    }

    return num + sumOfNums(num-1);
}

//! Return even numbers
void checkEvenNum(int num){
    if(num<2){
        return;
    }

    if(num%2==0){
        std::cout<<num<<" is even"<<std::endl;
    }
    checkEvenNum(num-1);
}

//! Check num
void checkNum(int num){
    if(num<1){
        return;
    }

    checkNum(num-1);
    if(num%2==0){
        std::cout<<num<<" is even"<<std::endl;
    }else{
        std::cout<<num<<" is odd"<<std::endl;
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
        std::cout<<num<<" is prime"<<std::endl;
    }else{
        std::cout<<num<<" is composite"<<std::endl;
    }

    checkPrime(num-1);
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

//! binary search
bool binarySearch(int *arr, int start, int end, int key){
    if(start>end){
        return false;
    }

    int mid = start + (end-start)/2;

    if(arr[mid]==key){
        return true;
    }

    if(key>arr[mid]){
        return binarySearch(arr, mid+1, end, key);
    }else{
        return binarySearch(arr, start, mid-1, key);
    }
}

int main(){
    printName(5);
    std::cout<<std::endl;

    printNum(5);
    std::cout<<std::endl;

    printNumReverse(5);

    // int *arr = new int[5];
    // std::cout<<"Array:"<<std::endl;
    // for(int i=0; i<5; i++){
    //     int element;
    //     std::cout<<"Enter element: ";
    //     std::cin>>element;
    //     arr[i] = element;
    // }
    // sumOfNums(arr, 5);

    // std::cout<<std::endl;
    // std::cout<<"Sum: "<<sumOfNumsRecursion(arr, 5)<<std::endl;

    std::cout<<std::endl;

    int arr1[5] = {10, 20, 30, 40, 50};
    std::cout<<"Array traversed using recursion: "<<std::endl;
    displayArray(arr1, 5);

    std::cout<<std::endl;
    std::cout<<"Reverse array using recursion: "<<std::endl;
    displayArrayRecursion(arr1, 5);

    std::cout<<std::endl;
    std::cout<<"Sum of natural numbers: "<<sumOfNums(5)<<std::endl;

    std::cout<<std::endl;
    checkEvenNum(10);

    std::cout<<std::endl;
    checkNum(10);

    std::cout<<std::endl;
    checkPrime(10);

    std::cout<<std::endl;
    std::cout<<"Linear Search: "<<linearSearch(arr1, 5, 40)<<std::endl;
    
    int arr2[5] = {100, 200, 300, 400, 500};
    std::cout<<"Binary search: "<<binarySearch(arr2, 0, 4, 300)<<std::endl;
    return 0;
}