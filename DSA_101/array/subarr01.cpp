#include <iostream>
#include <vector>
#include <algorithm>

void subarr1(std::vector<int> arr){
    for(int start = 0; start<arr.size(); start++){
        for(int end=start; end<arr.size(); end++){
            for(int i=start; i<=end; i++){
                std::cout<<arr[i];
            }
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

void subarr2(std::vector<int> arr){
    int currentSum = 0;
    int maxSum = INT_MIN;
    for(int val: arr){
        currentSum += val;
        maxSum = std::max(currentSum, maxSum);
        if(currentSum<0){
            currentSum = 0;
        }
    }
    std::cout<<"max: "<<maxSum<<std::endl;
}

int main(){
    std::vector<int> v = {-1, 2, -3, 4, -1};
    subarr2(v);
    return 0;
}