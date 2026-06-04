#include <iostream>
using namespace std;

void genCombinations(int n, int k, int index, vector<int>& ds, vector<vector<int>>& ans){
    if(k==0){
        ans.push_back(ds);
        return;
    }
    if(index>n) return;
    ds.push_back(index);
    genCombinations(n, k-1, index+1, ds, ans);
    ds.pop_back();
    genCombinations(n, k, index+1, ds, ans);
}

void genCombSum(vector<int>& combinations, int target, int index, vector<int>& ds, vector<vector<int>>& ans){
    if(index==combinations.size()){
        if(target==0) ans.push_back(ds);
        return;
    }
    if(combinations[index]<=target){
        ds.push_back(combinations[index]);
        genCombSum(combinations, target-combinations[index], index, ds, ans);
        ds.pop_back();
    }
    genCombSum(combinations, target, index+1, ds, ans);
}

void genCombSumII(vector<int>& combinations, int target, int index, vector<int>& ds, vector<vector<int>>& ans){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i = index; i<combinations.size(); i++){
        if(i>index && combinations[i]==combinations[i-1]) continue;
        if(combinations[i]>target) break;
        ds.push_back(combinations[i]);
        genCombSumII(combinations, target-combinations[i], i+1, ds, ans);
        ds.pop_back();
    }
}

void genSeq(vector<int>& arr, int size, int index, vector<int>& ds, vector<vector<int>>& ans){
    if(index>size){
        ans.push_back(ds);
        return;
    }
    for(int i=index; i<size; i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        genSeq(arr, size, i+1, ds, ans);
        ds.pop_back();
    }
}


int main(){
    vector<int> arr = {4, 6, 7, 7};
    vector<int> ds;
    vector<vector<int>> ans;
    genSeq(arr, 4, 0, ds, ans);

    for(auto vec: ans){
        for(auto value: vec){
            cout<<value<<" ";
        }
        cout<<endl;
    }
    return 0;
}