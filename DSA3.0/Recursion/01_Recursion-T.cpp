#include <iostream>
#include <vector>

//! power of n
int power(int num, int n){
    if(n==0){
        return 1;
    }
    return num * power(num, n-1);
}

//! fibonacci: nth term
int fibonacci(int num){
    if(num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }

    return fibonacci(num-1) + fibonacci(num-2);
}

//! climb steps: Forward approach
int climbSteps1(int count, int n){
    if(count==n){
        return 1;
    }

    if(count>0){
        return 0;
    }

    return climbSteps1(count+1, n) + climbSteps1(count+2, n);
}

//! climb steps: Top-Down DP
class Solution{
    public:
    std::vector<int> dp;

    int steps(int n){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }

        return dp[n] = steps(n-1) + steps(n-2);
    }

    int climbStairs(int n){
        dp.resize(n+1, -1);
        return steps(n);
    }
};

//! Count Digits
class CountDigits{
    public:
    std::string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    void countDigi(int num){
        if(num==0){
            return;
        }
        int n = num%10;
        std::cout<<nums[n]<<" ";
        countDigi(num/10);
    }

};

//! Check if array is sorted
bool isSorted(int arr[], int size){
    if(size==0 || size==1){
        return true;
    }


    if(arr[0] > arr[1]){
        return false;
    }else{
        return isSorted(arr+1, size-1);
    }
}

//! Check an array
void check(){
    int arr[5] = {12, 23, 45, 56, 90};
    int* ptr = arr+1;

    for(int i=0; i<4; i++){
        std::cout<<"i: "<<i<<std::endl;
        std::cout<<*(ptr+i)<<std::endl;
    }
}

//! sum of array
int sumOfArr(int arr[], int total, int size){
    if(size==0){
        return total;
    }

    total+=arr[0];
    return sumOfArr(arr+1, total, size-1);
}

//! linear search
int linearSearch(int arr[], int key, int size){
    if(size==0){
        return -1;
    }

    if(arr[0]==key){
        return 1;
    }else{
        return linearSearch(arr+1, key, size-1);
    }
}

//! binary search - without recursion
int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            return 1;
        }

        if(key > arr[mid]){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}

//! binary search - with recursion
int binarySearchRec(int arr[], int start, int end, int key){
    if(start>end){
        return -1;
    }

    int mid = start+(end-start)/2;
    if(arr[mid]==key){
        return 1;
    }
    if(key>arr[mid]){
        return binarySearchRec(arr, mid+1, end, key);
    }else{
        return binarySearchRec(arr, start, mid-1, key);
    }
}

int main(){
    // std::cout<<"Power of 3^3: "<<power(3, 3)<<std::endl;
    // std::cout<<"Fibonacci of 5: "<<fibonacci(8)<<std::endl;
    // std::cout<<climbSteps1(1, 2);
    // CountDigits c = CountDigits();
    // c.countDigi(123);
    // check();
    int arr[5] = {11, 22, 33, 44, 54};
    // std::cout<<"Total: "<<sumOfArr(arr, 0, 5)<<std::endl;
    // std::cout<<"linear search: "<<linearSearch(arr, 42, 5);
    std::cout<<"binary search: "<<binarySearchRec(arr, 0, 4, 44);
    return 0;
}