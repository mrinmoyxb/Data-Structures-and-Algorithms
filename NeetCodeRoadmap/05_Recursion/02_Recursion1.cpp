#include <iostream>
using namespace std;

void funcNto1(int n){
    if(n<1){
        return;
    }
    cout<<n<<endl;
    funcNto1(n-1);
}

void func1toN(int n1, int n2){
    if(n1>n2){
        return;
    }
    cout<<n1<<endl;
    func1toN(n1+1, n2);
}

int factorial(int n){
    if(n<1){
        return 1;
    }

    int f = n * factorial(n-1);
    return f;
}

int sumOfNto1(int n){
    if(n<1){
        return 0;
    }
    int s = n+sumOfNto1(n-1);
    return s;
}

void funcEven(int n){
    if(n<1){
        return;
    }

    if(n%2 == 0){
        cout<<n<<" is even"<<endl;
        funcEven(n-1);
    }
    else{
        funcEven(n-1);
    }
}

void funcOdd(int n){
    if(n<1){
        return;
    }
    if(n%2 != 0){
        cout<<n<<" is odd"<<endl;
        funcOdd(n-1);
    }
    else{
        funcOdd(n-1);
    }
}

void Multiply(int n1, int n2, int x){
    if(n1>n2){
        return;
    }

    cout<<x<<" x "<<n1<<" = "<<x*n1<<endl;

    Multiply(n1+1, n2, x);
}

int main(){
    //funcNto1(5);
    // func1toN(1, 5);
    // cout<<"Factorial of "<<3<<" : "<<factorial(3)<<endl;
    // cout<<"Sum : "<<sumOfNto1(5)<<endl;

    // funcEven(10);
    // funcOdd(10);

    Multiply(1, 10, 2);
    return 0;
}