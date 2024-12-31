#include <iostream>
using namespace std;

//! In the given code let's assume start, end and mid acts as three pointers
//! 1. Check the mid with the key 
//! 2. If the key is greater than mid then search in the right side
//! 3. If the key is smaller than the mid then search in the left side 
//! 4. Update mid

//* Key point: 
//* Use {start + (end-start)/2} so that the value of mid is in range.
//* Case (2^31-1 + 2^31-1)/2

//! Using while loop
int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return 1;
        }

        if(key>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }

        mid = start + (end-start)/2;
    }
    return -1;
}

//! Using recursion
int binarySearchUsingRecursion(int arr[], int start, int end, int key){
    if(start>end){
        return -1;
    }
    
    int mid = start + (end-start)/2;
    if(arr[mid]==key){
        return 1;
    }
    
    if(key>arr[mid]){
        return binarySearchUsingRecursion(arr, mid+1, end, key);
    }
    else{
        return binarySearchUsingRecursion(arr, mid-1, end, key);
    }
}
int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int key = 40;

    int result1 = binarySearch(arr, 5, key);
    if(result1==1){
        cout<<key<<" is available"<<endl;
    }
    else{
        cout<<key<<" is not available"<<endl;
    }

    cout<<endl;
    int result2 = binarySearchUsingRecursion(arr, 0, 4, key);
    if(result1==1){
        cout<<key<<" is available"<<endl;
    }
    else{
        cout<<key<<" is not available"<<endl;
    }

    return 0;
}