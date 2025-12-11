#include <iostream>

int firstOccurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int ans = -1;

    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            ans = mid;
            end = mid-1;
        }
        else if(key > arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int lastOccurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int ans = -1;
    
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            ans = mid;
            start = mid+1;
        }
        else if(key>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    return ans;
}

std::pair<int, int> firstAndLastOccurence(int arr[], int size, int key){
    int first = firstOccurence(arr, size, key);
    int last = lastOccurence(arr, size, key);

    std::pair<int, int> result = {first, last};
    return result;
}

int main(){
    int arr[9] = {1, 2, 2, 2, 3, 3, 3, 4, 5};
    int size = 9;
    int key = 2;

    std::pair<int, int> result = firstAndLastOccurence(arr, size, key);
    std::cout<<"initial: "<<result.first<<std::endl;
    std::cout<<"last: "<<result.second<<std::endl;

    return 0;
}