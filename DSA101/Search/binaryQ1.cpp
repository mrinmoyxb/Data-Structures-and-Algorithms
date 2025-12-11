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
        else if(key>arr[mid]){
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
        }else if(key>arr[mid]){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}

int numOfElements(int arr[], int size, int key){
    int first = firstOccurence(arr, size, key);
    int last = lastOccurence(arr, size, key);
    int result = (last-first)+1;
    return result;
}

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
        }
        else{
            start = mid+1;
        }
    }
}

int first(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int ans = INT_MIN;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}

int last(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int ans = INT_MIN;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            ans = mid;
            start = mid+1;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    return ans;
}

int main(){
    int arr[9] = {1, 2, 2, 2, 2, 3, 3, 4, 4};
    int size = 9;
    int result = numOfElements(arr, size, 2);

    std::cout<<"Number of elements: "<<result<<std::endl;

    return 0;
}