#include <iostream>

//! Binary Search:
int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            return 1;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return -1;
}

//! Index of first and last occurence of elements in an array
int firstOccurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int ans = -1;
    int mid = start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }

    return ans;
}

int lastOccurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int ans = -1;
    int mid = start+(end-start)/2;

    while(start<end){
        if(arr[mid]==key){
            ans = mid;
            start = mid+1;
        }else if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }

    return ans;
}

std::pair<int, int> firstAndLast(int arr[], int size, int key){
    int first = firstOccurence(arr, size, key);
    int last = lastOccurence(arr, size, key);
    std::pair<int, int> p = {first, last};
    return p;
}

int main(){
    int arr[8] = {1, 2, 3, 3, 3, 3, 3, 4};
    int key = 3;
    std::pair<int, int> p = firstAndLast(arr, 8, key);
    std::cout<<"First: "<<p.first<<std::endl;
    std::cout<<"Last: "<<p.second<<std::endl;
}