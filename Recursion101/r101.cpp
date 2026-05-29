#include <iostream>

void printNames(std::string word, int n){
    if(n==0) return;
    std::cout<<word<<std::endl;
    printNames(word, n-1);
}

void printNums(int start, int end){
    if(start>end) return;
    std::cout<<start<<std::endl;
    printNums(start+1, end);
}

void printNums1(int start){
    if(start<1) return;
    std::cout<<start<<std::endl;
    printNums1(start-1);
}

void printNums2(int start){
    if(start<1) return;
    printNums2(start-1);
    std::cout<<start<<std::endl;
}

void printNums3(int start, int end){
    if(start>end) return;
    printNums3(start+1, end);
    std::cout<<start<<std::endl;
}

void print1toN(int n){
    if(n==0) return;
    print1toN(n-1);
    std::cout<<n<<std::endl;
}

void printNto1(int n){
    if(n==0) return;
    std::cout<<n<<std::endl;
    printNto1(n-1);
}

int main(){
    
    return 0;
}