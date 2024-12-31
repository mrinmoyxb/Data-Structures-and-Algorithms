#include <iostream>
using namespace std;



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

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    cout<<binarySearch(arr, 5, 30)<<endl;
    return 0;
}