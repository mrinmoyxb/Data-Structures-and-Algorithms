#include <iostream>
using namespace std;

//! Linear search
void linearSearch(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            cout<<key<<" is available"<<endl;
            break;
        }
    }
}

//! Binary search
int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int mid = start+(end-start)/2;

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

//! Linear search using recursion
bool linearSearchUsingRecursion(int arr[], int size, int key){
    if(size==0){
        return false;
    }

    if(*arr==key){
        return true;
    }
    else{
        return linearSearchUsingRecursion(arr+1, size-1, key);
    }
}

//! Binary search using recursion
int binarySearchUsingRecursion(int arr[], int start, int end, int size, int key){

    if(start>end){
        return -1;
    }

    int mid = start + (end-start)/2;
    if(arr[mid]==key){
        return 1;
    }
    
    if(key>arr[mid]){
        return binarySearchUsingRecursion(arr, mid+1, end, size, key);
    }
    else{
        return binarySearchUsingRecursion(arr, start, mid-1, size, key);
    }
}

int main(){
    int *arr = new int[5];
    int *arr1 = new int[5];

    cout<<"Enter elements: "<<endl;
    for(int i=0; i<5; i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }

    int key = 90;
    linearSearch(arr, 5, key);
    cout<<linearSearchUsingRecursion(arr, 5, key)<<endl;

    cout<<"\nEnter elements for binary search: "<<endl;
    for(int i=0; i<5; i++){
        cout<<"Enter element: ";
        cin>>arr1[i];
    }
    cout<<"Binary search: "<<binarySearch(arr1, 5, key);
    cout<<"\nBinary search using recursion: "<<binarySearchUsingRecursion(arr1, 0, 4, 5, key);

    delete []arr;
    delete []arr1;

    return 0;
}