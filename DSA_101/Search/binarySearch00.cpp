#include <iostream>
#include <vector>

int binarySearch(std::vector<int> v, int key){
    int start = 0;
    int end = v.size()-1;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(v[mid]==key){
            return mid;
        }
        else if(v[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int binarySearchRec(std::vector<int> arr, int key, int start, int end){
    int mid = start + (end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            return binarySearchRec(arr, key, start, mid-1);
        }
        else{
            return binarySearchRec(arr, key, mid+1, end);
        }
    }
    return -1;
}

int main(){
    std::vector<int> v = {10, 12, 34, 56, 57, 99, 100};
    std::cout<<"vector: "<<std::endl;
    for(int value: v){
        std::cout<<value<<" ";
    }
    std::cout<<"Value: "<<binarySearchRec(v, 99, 9, 6)<<std::endl;
    return 0;
}