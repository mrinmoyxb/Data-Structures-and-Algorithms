#include <iostream>

void printNto1(int n){
    if(n<1){
        return;
    }
    std::cout<<n<<std::endl;
    printNto1(n-1);
}

void printNums(int num){
    if(num<1){
        return;
    }
    printNums(num-1);
    std::cout<<num<<std::endl;
}

int main(){
    
    printNums(5);
    return 0;
}