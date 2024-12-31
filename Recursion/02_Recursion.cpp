#include <iostream>
using namespace std;

//! Ascending order
void ascending(int num){
    if(num<1){
        return;
    }
    ascending(num-1);
    cout<<num<<endl;
}

//! Descending order
void descending(int num){
    if(num<1){
        return;
    }
    cout<<num<<endl;
    descending(num-1);
}

//! Sum of numbers
int sumOfNum(int num){
    if(num<1){
        return 0;
    }
    return num + sumOfNum(num-1);
}

//! Prime numbers
void checkPrime(int num){
    if(num<2){
        return;
    }
    checkPrime(num-1);
    bool isPrime = true;
    for(int i=2; i<num; i++){
        if(num%i==0){
            isPrime = false;
        }
        break;
    }
    if(isPrime==true){
        cout<<num<<" is a prime number"<<endl;
    }
}

//! Composite numbers
void checkComposite(int num){
    if(num<4){
        return;
    }
    checkComposite(num-1);
    bool isComposite = false;
    for(int i=2; i<num; i++){
        if(num%i==0){
            isComposite = true;
        }
        break;
    }
    if(isComposite==true){
        cout<<num<<" is a composite number"<<endl;
    }
}

//! Factorial
int factorial(int num){
    if(num==0){
        return 1;
    }
    return num * factorial(num-1);
}

//! Fibonacci series
int fibonacci(int num){
    if(num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }

    return fibonacci(num-1) + fibonacci(num-2);
}

//! Even number
void evenNum(int num){
    if(num<1){
        return;
    }
    evenNum(num-1);
    if(num%2==0){
        cout<<num<<" is an even number"<<endl;
    }
}

//! Squared of n numbers
void squared(int num){
    if(num<1){
        return;
    }
    squared(num-1);
    cout<<"Squared of "<<num<<" is: "<<num*num<<endl;
}

//! Divisible by 9 
void checkDivisible(int start, int end){
    if(start>end){
        return;
    }
    if(start%9==0){
        cout<<start<<" is divisible by 9"<<endl;
    }
    checkDivisible(start+=1, end);
}

int main(){
    cout<<"Ascending order: "<<endl;
    ascending(5);

    cout<<"\nDescending order: "<<endl;
    descending(5);

    cout<<"\nSum of numbers: "<<sumOfNum(5)<<endl;

    cout<<"\nPrime number or not: "<<endl;
    checkPrime(10);

    cout<<"\nComposite numbers: "<<endl;
    checkComposite(4);

    cout<<"\nFactorial number: "<<factorial(6)<<endl;

    cout<<"\nFibonacci series: "<<fibonacci(4)<<endl;

    cout<<"\nEven number: "<<endl;
    evenNum(10);

    cout<<"\nSquared of n numbers: "<<endl;
    squared(10);

    cout<<"\nCheck divisiblity by 9 between 100 to 200"<<endl;
    checkDivisible(100, 200);
    return 0;
}