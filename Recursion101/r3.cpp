#include <iostream>
#include <vector>
#include <set>

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

void sub(int index, std::vector<char>& ds, std::vector<char>& arr, int n){
    if(index==n){
        for(auto c: ds){
            std::cout<<c<<" ";
        }
        std::cout<<std::endl;
        return;
    }

    ds.emplace_back(arr[index]);
    sub(index+1, ds, arr, n);
    ds.pop_back();
    sub(index+1, ds, arr, n);
}

void combinations(int index, std::vector<int>& ds, std::vector<int>& candidates, int target, int sum, std::vector<std::vector<int>>& ans){
    if(index==candidates.size()){
        if(sum==target){
            sort(ds.begin(), ds.end());
            ans.push_back(ds);
            return;
        }else return;
    }

    ds.emplace_back(candidates[index]);
    sum+=candidates[index];
    combinations(index+1, ds, candidates, target, sum, ans);

    ds.pop_back();
    sum-=candidates[index];
    combinations(index+1, ds, candidates, target, sum, ans);
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<int> ds;
    std::vector<std::vector<int>> ans;
    combinations(0, ds, candidates, target, 0, ans);
    return ans;
}

void powerSet(){
    std::vector<int> v = {1, 2, 3};
}

int main(){
    std::vector<char> ds = {};
    std::vector<int>arr = {10,1,2,7,6,1,5};
    // check(0, ds, arr, 3);
    //std::vector<char> arr = {'a', 'b', 'c', 'd', 'e', 'f'};

    // std::string num = "1234";
    // for(char c: num){
    //     std::cout<<c<<std::endl;
    // }
    // sub(0, ds, arr, 6);
    std::vector<std::vector<int>> v = combinationSum2(arr, 8);
    std::set<std::vector<int>> unique;

    for(auto &i: v){
        sort(i.begin(), i.end()); 
        unique.insert(i);
    }

    for(auto vi: v){
        for(auto x: vi){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    for(auto vi: unique){
        for(auto x: vi){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}