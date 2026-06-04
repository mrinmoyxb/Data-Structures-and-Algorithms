#include <iostream>
using namespace std;

int tribonacciNum(int num){
    if(num==0) return 0;
    if(num<=2) return 1;
    return tribonacciNum(num-1) + tribonacciNum(num-2) + tribonacciNum(num-3);
}

int main(){
    return 0;
}