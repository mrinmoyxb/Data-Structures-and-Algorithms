#include <iostream>

int factorial(int num){
    std::cout<<"Calling factorial of "<<num<<std::endl;
    if(num==1){
        std::cout<<"Base case reached: factorial "<<num<<std::endl;
        return 1;
    }

    int result = num*factorial(num-1);
    std::cout<<"Returning: "<<num<<" * factorial "<<num-1<<" : "<<result<<std::endl;
    return result;
}

int fibonacci(int num){
    if(num<=1){
        return num;
    }else{
        return fibonacci(num-1)+fibonacci(num-2);
    }
}

int sumOfDigitsRange(int num){
    if(num==1){
        return 1;
    }
    return num + sumOfDigitsRange(num-1);
}

int sumOfDigits(int num){
    if(num==0){
        return 0;
    }

    int r = num%10;
    return r+sumOfDigits(num/10);
}

int powerFunction(int num, int p){
    if(p==1){
        return num;
    }
    return num * powerFunction(num, p-1);
}

int main(){
    // std::cout<<factorial(3);
    // std::cout<<std::endl;
    // std::cout<<fibonacci(8)<<std::endl;
    // std::cout<<sumOfDigitsRange(5);
    // std::cout<<sumOfDigits(123045);
    std::cout<<powerFunction(2, 3);
    return 0;
}