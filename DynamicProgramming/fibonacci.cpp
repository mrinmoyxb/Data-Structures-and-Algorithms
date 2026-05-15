#include <iostream>
#include <vector>

int fibonacci(int num, std::vector<int> &dp){
    if(num==0 || num==1){
        return num;
    }

    if(dp[num]!=-1){
        return dp[num];
    }

    dp[num] = fibonacci(num-1, dp) + fibonacci(num-2, dp);
    return dp[num];
}

int fibonacciTable(int num, std::vector<int> &dp){
    int n;
    std::cin>>n;

    std::vector<int> dp(n+1);
    dp[1] = 1;
    dp[0] = 0;

    for(int i=2; i<=num; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    std::cout<<dp[n]<<std::endl;
}

int countStairs(){}

int main(){
    int n;
    std::cin>>n;
    std::vector<int> dp(n+1);
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    std::cout<<fibonacci(n, dp)<<std::endl;
    return 0;
}