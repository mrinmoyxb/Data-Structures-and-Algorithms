#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void printNames(std::string word, int n){
    if(n==0) return;
    std::cout<<word<<std::endl;
    printNames(word, n-1);
}

void printNums(int start, int end){
    if(start>end) return;
    std::cout<<start<<std::endl;
    printNums(start+1, end);
}

void printNums1(int start){
    if(start<1) return;
    std::cout<<start<<std::endl;
    printNums1(start-1);
}

void printNums2(int start){
    if(start<1) return;
    printNums2(start-1);
    std::cout<<start<<std::endl;
}

void printNums3(int start, int end){
    if(start>end) return;
    printNums3(start+1, end);
    std::cout<<start<<std::endl;
}

void print1toN(int n){
    if(n==0) return;
    print1toN(n-1);
    std::cout<<n<<std::endl;
}

void printNto1(int n){
    if(n==0) return;
    std::cout<<n<<std::endl;
    printNto1(n-1);
}

int sumOfN(int n, int sum){
    if(n==0) return sum;
    sum+=n;
    return sumOfN(n-1, sum);
}

int sumOfN2(int n){
    if(n==0) return 0;
    return n + sumOfN2(n-1);
}

void reverseAnArr(int arr[], int start, int end){
    if(start>end) return;
    std::swap(arr[start], arr[end]);
    reverseAnArr(arr, start+1, end-1);
}

bool isPalindrome(std::string str, int start, int end){
    if(start>end) return true;
    if(str[start]!=str[end]) return false;
    return isPalindrome(str, start+1, end-1);
}

int fibonacci(int num){
    if(num==0) return 0;
    if(num==1) return 1;
    return fibonacci(num-1) + fibonacci(num-2);
}

void genSubsequences(vector<int>& arr, int index, vector<int>& ds, vector<vector<int>>& ans, int size){
    if(index>=size){
        ans.push_back(ds);
        return;
    }
    ds.push_back(arr[index]);
    genSubsequences(arr, index+1, ds, ans, size);
    ds.pop_back();
    genSubsequences(arr, index+1, ds, ans, size);
}

void subsequenceSum(vector<int>& arr, int k, int index, vector<int>& ds, vector<vector<int>>& ans, int size, int sum){
    if(index==size){
        if(k==sum){
            ans.push_back(ds);
            return;
        }
        return;
    }
    ds.push_back(arr[index]);
    sum+=arr[index];
    subsequenceSum(arr, k, index+1, ds, ans, size, sum);

    ds.pop_back();
    sum-=arr[index];
    subsequenceSum(arr, k, index+1, ds, ans, size, sum);
}

bool subsequenceSumSingle(vector<int>& arr, int k, int index, vector<int>& ds, vector<vector<int>>& ans, int size, int sum){
    if(index==size){
        if(k==sum){
            ans.push_back(ds);
            return true;
        }else return false;
    }
    ds.push_back(arr[index]);
    sum+=arr[index];
    if(subsequenceSumSingle(arr, k, index+1, ds, ans, size, sum)==true) return true;
    
    ds.pop_back();
    sum-=arr[index];
    if(subsequenceSumSingle(arr, k, index+1, ds, ans, size, sum)==true) return true;
    
    return false;
}

int subsequenceCount(vector<int>& arr, int k, int index, vector<int>& ds, vector<vector<int>>& ans, int size, int sum){
    if(index==size){
        if(k==sum){
            ans.push_back(ds);
            return 1;
        }
        return 0;
    }
    
    ds.push_back(arr[index]);
    sum+=arr[index];
    int left = subsequenceCount(arr, k, index+1, ds, ans, size, sum);
    ds.pop_back();
    sum-=arr[index];
    int right = subsequenceCount(arr, k, index+1, ds, ans, size, sum);
    return left+right;
}

int genNumSubseq(vector<int>& nums, int target, int index, vector<int>& ds, vector<vector<int>>& ans, int size, int sum){
        if(index==size){
            auto result = minmax_element(ds.begin(), ds.end());
            int min = *result.first;
            int max = *result.second;
            int sum = min+max;
            if(sum<=target){
                ans.push_back(ds);
                return 1;
            }
            return 0;
        }

        ds.push_back(nums[index]);
        int left = genNumSubseq(nums, target, index+1, ds, ans, size, sum);
        ds.pop_back();
        int right = genNumSubseq(nums, target, index+1, ds, ans, size, sum);
        return left + right;
    }

void findCombinations(vector<int>& nums, int target, int index, vector<int>& ds, vector<vector<int>>& ans, int size){
    if(index==size){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }

    if(nums[index]<=target){
        ds.push_back(nums[index]);
        findCombinations(nums, target-nums[index], index, ds, ans, size);
        ds.pop_back();
    }
    findCombinations(nums, target, index+1, ds, ans, size);
}

void findCombinations1(vector<int>& nums, int target, int index, vector<int>& ds, vector<vector<int>>& ans, int size){
    if(target==0){
        ans.push_back(ds);
        return;
    }

    for(int i=index; i<size; i++){
        if(i>index && nums[i]==nums[i-1]) continue;
        if(nums[i]>target) break;
        ds.push_back(nums[index]);
        findCombinations1(nums, target, index+1, ds, ans, size);
        ds.pop_back();
    }
}

void check(){
    vector<int> nums = {1,2,3,4,5};
    int size = nums.size();
    vector<int> ans(size, 100);
    stack<int> st;

    int num = nums[size - 1];
    cout<<"num: "<<num<<endl;
    for (int i = 0; i < size - 1; i++){
        if (nums[i] > num){
            ans[size - 1] = nums[i];
            st.push(size - 1);
            break;
        }else{
            ans[size-1]  = -1;
            st.push(size-1);
        }
    }

    for(auto v: ans){
        cout<<v<<endl;
    }

    for (int i = size - 2; i >= 0; i--){
        while (!st.empty() && nums[i] > nums[st.top()]){
            st.pop();
        }
        if (st.empty())ans[i] = -1;
        else ans[i] = nums[st.top()];
        st.push(i);
    }

    cout<<endl;
    for(auto v: ans){
        cout<<v<<endl;
    }
}

void genSeq(string s, int size, int index, vector<char>& ds, vector<vector<char>>& ans){
    if(index==size){
        ans.push_back(ds);
        return;
    }

    ds.push_back(s[index]);
    genSeq(s, size, index+1, ds, ans);
    ds.pop_back();
    genSeq(s, size, index+1, ds, ans);
}

void genSeq1(string s, int size, int index, vector<char>& ds, vector<vector<char>>& ans){
    if(index==size){
        ans.push_back(ds);
        return;
    }

    for(int i=index; i<size; i++){
        if(i>index && s[i]==s[i-1]) continue;
        ds.push_back(s[index]);
        genSeq1(s, size, index+1, ds, ans);
        ds.pop_back();
    }
}

int main(){
    string s = "aab";
    int size = 3;
    int index = 0;
    vector<char> ds;
    vector<vector<char>> ans;

    genSeq1(s, size, 0, ds, ans);

    for(auto a: ans){
        for(auto v: a){
            cout<<v<<" ";
        }
        cout<<endl;
    }

    return 0;
}