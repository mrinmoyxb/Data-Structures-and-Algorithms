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

//! climb steps: TOp-Down DP
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

int main(){
    // std::cout<<"Power of 3^3: "<<power(3, 3)<<std::endl;
    // std::cout<<"Fibonacci of 5: "<<fibonacci(8)<<std::endl;
    std::cout<<climbSteps1(1, 2);
    return 0;
}