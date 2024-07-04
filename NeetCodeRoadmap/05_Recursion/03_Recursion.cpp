#include <iostream>
using namespace std;

void reverse(int n){
    int rem = 0;
    while(n!=0){
        int digit = n%10;
        rem = (rem*10)+digit;
        n = n/10;
    }
    cout<<"Reverse: "<<rem<<endl;
}

void reverseRecursion(int n){
    if(n<10){
        cout<<n;
        return;
    }
    cout<<n%10;
    reverseRecursion(n/10);
}

int countZeroes(int n){
    if(n==0){
        return 1;
    }

    if(n%10 == 0){
        return countZeroes(n/10)+1;
    }

    return countZeroes(n/10);
}

int main(){
    // reverse(123);
    // reverseRecursion(123);
    cout<<countZeroes(12903);
    return 0;
}