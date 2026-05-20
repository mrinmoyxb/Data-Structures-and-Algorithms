#include <iostream>
#include <vector>

//! CONSEQUENT 

void subsequences(int index, std::vector<int>&ds, int arr[], int n){
    if(index==n){
        for(auto it: ds){
            std::cout<<it<<" ";
        }
        std::cout<<std::endl;
        return;
    }
    std::cout<<"Inserting: "<<arr[index]<<std::endl;
    ds.emplace_back(arr[index]);
    subsequences(index+1, ds, arr, n);
    std::cout<<"Popping: "<<arr[index]<<std::endl;
    ds.pop_back();
    subsequences(index+1, ds, arr, n);
}

void subsequences1(int index, std::vector<int>&ds, int arr[], int n){
    if(index==0){
        for(auto it: ds){
            std::cout<<it<<" ";
        }
        std::cout<<std::endl;
        return;
    }
    ds.emplace_back(arr[index]);
    subsequences1(index+1, ds, arr, n);
    ds.pop_back();
    subsequences1(index+1, ds, arr, n);
}

void subsequentSum(int index, std::vector<int>& v, int arr[], int key, int sum, int size){
    if(index==size){
        if(key==sum){
            for(auto it: v) std::cout<<it<<" ";
            std::cout<<std::endl;
        }
        return;
    }

    v.push_back(arr[index]);
    sum+=arr[index];
    subsequentSum(index+1, v, arr, key, sum, size);

    v.pop_back();
    sum-=arr[index];
    subsequentSum(index+1, v, arr, key, sum, size);
}

bool subsequentSumSinglePair(int index, std::vector<int>& v, int arr[], int key, int sum, int size){
    if(index==size){
        if(key==sum){
            for(auto it: v) std::cout<<it<<" ";
            std::cout<<std::endl;
            return true;
        }
        else return false;
    }
    v.emplace_back(v[index]);
    sum+=v[index];
    if(subsequentSumSinglePair(index+1, v, arr, key, sum, size)) return true;
    
    sum-=v[index];
    v.pop_back();
    if(subsequentSumSinglePair(index+1, v, arr, key, sum, size)) return true;

    return false;
}

int subsequentSumCount(int index, int arr[], int key, int sum, int size){
    if(index==size){
        if(key==sum){
            return 1;
        }
        else return 0;
    }
    sum+=arr[index];
    int left = subsequentSumCount(index+1, arr, key, sum, size);
    
    sum-=arr[index];
    int right = subsequentSumCount(index+1, arr, key, sum, size);

    return left+right;
}

// insert - call - remove - call
void check(int index, std::vector<int>& ds, int arr[], int n){
    if(index==n){
        for(auto i: ds){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
        return;
    }
    ds.emplace_back(arr[index]);
    check(index+1, ds, arr, n);
    ds.pop_back();
    check(index+1, ds, arr, n);
}

int main(){
    std::vector<int> ds = {};
    int arr[3] = {1, 2, 3};
    check(0, ds, arr, 3);
    return 0;
}