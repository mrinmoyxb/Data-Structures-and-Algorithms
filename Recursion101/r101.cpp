#include <iostream>
#include <vector>
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

int main(){
    vector<int> arr = {1, 2, 1};
    vector<int> ds;
    vector<vector<int>> ans;
    int k = 2;
    //genSubsequences(arr, 0, ds, ans, 3);
    std::cout<<"COUNT: "<<subsequenceCount(arr, k, 0, ds, ans, 3, 0)<<endl;
    for(auto vec: ans){
        for(int num: vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}