#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedArray(vector<int> nums, vector<int> left, vector<int> right){
    //int mid = start+(end-start)/2;

    int len1 = left.size();
    int len2 = right.size();

    vector<int> first(len1);
    vector<int> second(len2);

    int mainArrayIndex = 0;

    for(int i=0; i<len1; i++){
        first.push_back(nums[mainArrayIndex++]);
    }

    for(int j=0; j<len2; j++){
        second.push_back(nums[mainArrayIndex++]);
    }

    int index1=0;
    int index2=0;
    mainArrayIndex = 0;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            nums[mainArrayIndex++] = first[index1++];
        }
        else{
            nums[mainArrayIndex++] = second[index2++];
        }
    }


    while(index1<len1){
        nums[mainArrayIndex++] = first[index1++];
    }

    while(index2<len2){
        nums[mainArrayIndex++] = second[index2++];
    }

    return nums;
}

vector<int> merge(vector<int> nums, int start, int end){
    if(start>=end){
        return {};
    }

    int mid = start+(end-start)/2;

    vector<int> left = merge(nums, start, mid);
    vector<int> right = merge(nums, mid+1, end);
    return sortedArray(nums, left, right);
}

vector<int> mergeSort(vector<int> &nums){
    int start = 0;
    int end = nums.size()-1;
    return merge(nums, start, end);
}

int main(){
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(20);
    arr.push_back(1);

    cout<<"\nArray:: "<<endl;
    for(int element:arr){
        cout<<element<<endl;
    }

    arr = mergeSort(arr);

    cout<<"\nArray:: "<<endl;
    for(int element:arr){
        cout<<element<<endl;
    }

    return 0;
}