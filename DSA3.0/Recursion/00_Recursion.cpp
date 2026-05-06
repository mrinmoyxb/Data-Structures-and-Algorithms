#include <iostream>

//! numbers from 1 to n
void recursion1(int count, int n){
    if(count==n){
        return;
    }
    std::cout<<count<<std::endl;
    count+=1;
    recursion1(count, n);
}

//! print name 5 times
void printNames(std::string s, int start, int end){
    if(start>end){
        return;
    }
    start+=1;
    std::cout<<s<<std::endl;
    printNames(s, start, end);
}

//! print from N to 1
void printNum(int end){
    if(end<1){
        return;
    }
    std::cout<<end<<std::endl;
    end-=1;
    printNum(end);
}

//! print from 1 to N: backtracking
void printNumBackTracking(int end){
    if(end<1){
        return;
    }
    printNumBackTracking(end-1);
    std::cout<<end<<std::endl;
}

//! print numbers from N to 1: backtracking
void printNumTo1(int start, int end){
    if(start>end){
        return;
    }
    printNumTo1(start+1, end);
    std::cout<<start<<std::endl;
}

//! sum to n
int sumToN(int i, int n, int total){
    if(i>n){
        return total;
    }

    total += i;
    return sumToN(i+1, n, total);
}

//! sum to n
int sumToN1(int num, int total){
    if(num<1){
        return total;
    }

    total += num;
    return sumToN1(num-1, total);
}

//! sum to n
int sum(int num){
    if(num<1){
        return 0;
    }

    return num + sum(num-1);
}

//! reverse an array
void revArr(int arr[], int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        std::swap(arr[start++], arr[end--]);
    }
    
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! reverse array using recursion
void revArrRec(int arr[], int start, int end){
    if(start>end){
        return;
    }
    std::swap(arr[start], arr[end]);
    revArrRec(arr, start+1, end-1);
}

//! palindrome
bool checkPalindrome(std::string s, int start, int end){
    if(start>=end){
        return true;
    }
    if(s[start]!=s[end]){
        return false;
    }
    return checkPalindrome(s, start+1, end-1);
}

int main(){
    //recursion1(1, 5);
    //printNames("ABC", 1, 5);
    //printNumTo1(1, 5);
    //std::cout<<sumToN1(5, 0);
    //std::cout<<sum(5);
    // int arr[5] = {1, 2 , 3, 4, 5};
    // revArrRec(arr, 0, 4);
    // for(int i=0; i<5; i++){
    //     std::cout<<arr[i]<<" ";
    // }
    //std::cout<<checkPalindrome("CIVIC", 0, 5);
    return 0;
}