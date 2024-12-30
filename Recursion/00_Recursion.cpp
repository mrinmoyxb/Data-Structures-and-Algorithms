#include <iostream>
using namespace std;

int factorial(int num){
    if(num==0){
        return 1;
    }
    return num * factorial(num-1);
}

void reachHome(int src, int dest){
    cout<<"Source: "<<src<<endl;
    if(src==dest){
        return;
    }
    reachHome(src+1, dest);
}

int fibonacci(int num){
    if(num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }

    int result = fibonacci(num-1) + fibonacci(num-2);
    return result;
}

int main(){
    cout<<"Factorial of 6: "<<factorial(6)<<endl;
    reachHome(1, 10);
    cout<<"Fibonacci: "<<fibonacci(8)<<endl;
    return 0;
}