#include <iostream>
#include <vector>
using namespace std;

void genSequences(vector<int>& nums, int size, int index, vector<int>& ds, vector<vector<int>>& ans){
    if(index==size){
        if(ds.empty()) return;
        ans.push_back(ds);
        return;
    }

    ds.push_back(nums[index]);
    genSequences(nums, size, index+1, ds, ans);
    ds.pop_back();
    genSequences(nums, size, index+1, ds, ans);
}

void genSequences2(vector<int>& nums, int k, int size, int index, vector<int>& ds, vector<vector<int>>& ans, int sum){
    if(index==size){
        if(k==sum) ans.push_back(ds);
        return;
    }
    ds.push_back(nums[index]);
    sum+=nums[index];
    genSequences2(nums, k, size, index+1, ds, ans, sum);

    sum-=nums[index];
    ds.pop_back();
    genSequences2(nums, k, size, index+1, ds, ans, sum);
}

bool genSubSequences3(vector<int>& nums, int k, int size, int index, vector<int>& ds, vector<vector<int>>& ans, int sum){
    if(index==size){
        if(k==sum){
            ans.push_back(ds);
            return true;
        }else{
            return false;
        }
    }

    ds.push_back(nums[index]);
    sum+=nums[index];
    if(genSubSequences3(nums, k, size, index+1, ds, ans, sum)==true) return true;
    
    sum-=nums[index];
    ds.pop_back();
    if(genSubSequences3(nums, k, size, index+1, ds, ans, sum)==true) return true;
    return false;
}

int countSubSequence(vector<int>& nums, int k, int size, int index, vector<int>& ds, vector<vector<int>>& ans, int sum){
    if(index==size){
        if(sum==k){
            return 1;
        }else return 0;
    }

    ds.push_back(nums[index]);
    sum+=nums[index];
    int left = countSubSequence(nums, k, size, index+1, ds, ans, sum);
    
    sum-=nums[index];
    ds.pop_back();
    int right = countSubSequence(nums, k, size, index+1, ds, ans, sum);
    return left+right;
}


int main(){
    vector<int> nums = {1,2,1};
    int size = 3;
    int k = 2;
    vector<int> ds;
    vector<vector<int>> ans;
    cout<<countSubSequence(nums, k, size, 0, ds, ans, 0)<<endl;

    for(auto v: ans){
        for(auto value: v){
            cout<<value<<" ";
        }
        cout<<endl;
    }

    return 0;
}