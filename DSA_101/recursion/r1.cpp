#include <iostream>

void printNums(int num){
    if(num==1){
        std::cout<<"1"<<std::endl;
        return;
    }

    std::cout<<num<<std::endl;
    printNums(num-1);
}

int factorial(int num){
    if(num==1){
        return 1;
    }

    return num * factorial(num-1);
}

int sumOfN(int num){
    if(num==1){
        return 1;
    }

    return num + sumOfN(num-1);
}

void revString(std::string str, int index){
    if(index >= str.length()){
        return;
    }
    revString(str, index+1);
    std::cout<<str[index];
}

int main(){
    std::cout<<"Series: "<<std::endl;
    printNums(5);
    std::cout<<std::endl;
    std::cout<<"Factorial: "<<factorial(6)<<std::endl;
    std::cout<<"Sum: "<<sumOfN(5);
    revString("hello", 0);
    return 0;
}