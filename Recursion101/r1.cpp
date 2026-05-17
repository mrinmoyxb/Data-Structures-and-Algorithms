#include <iostream>

// Print numbers from 1 to N ✅
void print1toN(int start, int num){
    if(start>num){
        return;
    }
    std::cout<<start<<std::endl;
    print1toN(start+1, num);
}

// Print numbers from N to 1 ✅
void printNto1(int num){
    if(num<1){
        return;
    }
    std::cout<<num<<std::endl;
    printNto1(num-1);
}

// Sum of first N natural numbers ✅
int firstN(int num){
    if(num==0){
        return 0;
    }
    return num + firstN(num-1);
}

// Factorial of N ✅
int fact(int num){
    if(num==1) return 1;
    return num * fact(num-1);
}

// Power function (a^b)
int pow(int num, int p){
    if(p==0){
        return 1;
    }
    return num * pow(num, p-1);
}

int main(){
    std::cout<<pow(3, 2);
    return 0;
}