#include <iostream>
using namespace std;

//! Using for loop
void checkSorted(int arr[], int size){

    bool isSorted = true;
    for(int i=0; i<size; i++){
        if(arr[i]>arr[i+1]){
            isSorted = false;
            break;
        }
    }
    string result = isSorted==true ? "Array is sorted" : "Array is not sorted";
    cout<<result<<endl;
}

//! Using recursion
bool checkSortedRecursion(int arr[], int size){
    if(size==0 || size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }
    else{
        return checkSortedRecursion(arr+1, size-1);
    }
}

//! Sum of elements in an array
int sumOfElements(int arr[], int size){
    if(size == 1){
        return *arr;
    }
    return *arr + sumOfElements(arr+1, size-1);
}

//! Linear search using for loop
void linearSearch(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            cout<<key<<" is found in the array"<<endl;
            break;
        }
    }
}

//! Linear search using recursion
bool linearSearchUsingRecursion(int arr[], int size, int key){
    if(size==0){
        return false;
    }

    if(*arr == key){
        return true;
    }
    else{
        return linearSearchUsingRecursion(arr+1, size-1, key);
    }
}

int main(){
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[4] = {100, 89, 60, 62};

    checkSorted(arr1, 5);
    checkSorted(arr2, 4);

    cout<<"\nIs array sorted: "<<checkSortedRecursion(arr1, 5)<<endl;
    cout<<"Is array sorted: "<<checkSortedRecursion(arr2, 4)<<endl;

    int arr[5] = {1, 2, 3, 4, 5};
    cout<<"\nSum of elements of array: "<<sumOfElements(arr, 5)<<endl;

    int key = 30;
    cout<<"\nLinear search: "<<endl;
    linearSearch(arr1, 5, 30);
    cout<<"Linear search using recursion: "<<linearSearchUsingRecursion(arr1, 5, key)<<endl;
    return 0;

    
}