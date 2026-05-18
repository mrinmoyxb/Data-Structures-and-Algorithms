#include <iostream>
#include <algorithm>
#include <string>

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

// Power function (a^b) ✅
int pow(int num, int p){
    if(p==0){
        return 1;
    }
    return num * pow(num, p-1);
}

// Fibonacci number ✅
int fib(int num){
    if(num==0 || num==1){
        return num;
    }
    return fib(num-1) + fib(num-2);
}

// Count digits in a number ✅
int countDigits(int num, int count){
    if(num==0) return count;
    return countDigits(num/10, count+1);
}

// Sum of digits ✅
int sumOfDigits(int num, int sum){
    if(num==0){
        return sum;
    }
    sum+=num%10;
    return sumOfDigits(num/10, sum);
}

// Product of digits ✅
int product(int num, int ans){
    if(num==0) return ans;
    ans *= num%10;
    return product(num/10, ans);
}

// Reverse a number ✅
int rev(int num, int rem){
    if(num==0) return rem;
    rem = (rem*10) + (num%10);
    return rev(num/10, rem);
}

// Check palindrome number ✅
bool palindrome(int arr[], int start, int end){
    if(start>end) return true;
    if(arr[start]==arr[end]) return true;
    return palindrome(arr, start+1, end-1);
}

// Binary search using recursion ✅
bool binarySearch(int arr[], int start, int end, int key){
    if(start>end) return false;
    int mid = start + (end-start)/2;
    if(arr[mid]==key) return true;
    if(key>arr[mid]) return binarySearch(arr, mid+1, end, key);
    if(key<arr[mid]) return binarySearch(arr, start, mid-1, key);
    return false;
}

// Decimal to binary without recursion
std::string d2b(int num){
    std::string bin = "";
    while(num!=0){
        if(num%2==0) bin+="0";
        if(num%2!=0) bin+="1";
        num/=2;
    }
    std::reverse(bin.begin(), bin.end());
    return bin;
}

// Decimal to binary ✅
std::string d2bR(int num, std::string str){
    if(num==0){
        std::reverse(str.begin(), str.end());
        return str;
    }
    if(num%2==0) str+="0";
    if(num%2!=0) str+="1";
    return d2bR(num/2, str);
}

// GCD using recursion
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

// LCM using GCD recursion
int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

int main(){
    int arr[5] = {1, 2, 13, 22, 100};
    std::cout<<lcm(48, 18);
    return 0;
}