#include <iostream>
using namespace std;

//* Reverse an array
void reverseArray(int a[], int s){
    if(s==0){
        return;
    }

    cout<<a[s-1]<<endl;
    reverseArray(a, s-1);
}

//* Display an array
void displayArray(int arr[], int start, int size){
    if(start==size){
        return;
    }
    cout<<arr[start]<<endl;
    displayArray(arr, start+1, size);
}

//* Print natural numbers
void naturalNum(int start, int num){
    if(start>num){
        return;
    }
    cout<<start<<endl;
    naturalNum(start+1, num);
}

//* Print natural numbers
void naturalNum1(int num){
    if(num==0){
        return;
    }
    naturalNum1(num-1);
    cout<<num<<endl;
}

//* Sum of numbers
int sumOfNum(int num){
    if(num==0){
        return 0;
    }
    return num + sumOfNum(num-1);
}

//* Check even and odd numbers
void checkDigit(int num){
    if(num==0){
        return;
    }
    checkDigit(num-1);
    if(num%2==0){
        cout<<num<<" is an even number"<<endl;
    }
}

//* Check prime
void checkPrime(int num){
    if(num<2){
        return;
    }
    checkPrime(num-1);
    bool isPrime = true;
    for(int i=2; i<num; i++){
        if(num%i==0){
            isPrime = false;
            break;
        }
    }
    string s = isPrime == false ? "Not a prime" : "Pime number";
    cout<<num<<" is "<<s<<endl;
}

//* Factorial number
int factorial(int num){
    if(num==0){
        return 1;
    }
    return num * factorial(num-1);
}

//* Multiplication table
void mulTable(int num, int count){
    if(count>10){
        return;
    }
    cout<<num<<" * "<<count<<" = "<<num*count<<endl;
    mulTable(num, count+1);
}

int main(){
    // int arr[5] = {1, 2, 3, 4, 5};
    // reverseArray(arr, 5);
    // cout<<endl;
    
    // displayArray(arr, 0, 5);
    // cout<<endl;

    // cout<<"Natural numbers: "<<endl;
    // naturalNum1(10);

    // cout<<endl;
  
    // cout<<sumOfNum(5)<<endl;
    // cout<<endl;

    // checkDigit(10);
    checkPrime(10);
    cout<<endl;

    cout<<"Factorial of 6: "<<factorial(6)<<endl;
    cout<<endl;

    mulTable(5, 1);

    return 0;
}