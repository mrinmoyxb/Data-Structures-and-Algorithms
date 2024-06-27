#include <iostream>
using namespace std;

int sumOfN(int n){
    if(n<1){
        return 0;
    }
    return n+sumOfN(n-1);
}

void print(){
    int array[5] = {12, 3, 45, 9, 2};
    cout<<"Before: "<<endl;
    for(int i=0; i<5; i++){
        cout<<array[i]<<" ";
    }

    int start = 0;
    int end = 5-1;
    while(start<=end){
        swap(array[start], array[end]);
        start++;
        end--;
    }

    cout<<"After: "<<endl;
    for(int i=0; i<5; i++){
        cout<<array[i]<<" ";
    }

}

//! Intresting questions -> 1
void tempRec(int n){
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    if(n==0){
        return;
    }
    int m = n%10;
    n = n/10;
    tempRec(n);
    cout<<arr[m]<<endl;
}

//! 2
bool printSortArray(int *arr, int size){
    if(size==0 || size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remaining = printSortArray(arr+1, size-1);
        return remaining;
    }
}

//! 3 Approach 1
int sumOfValue(int *arr, int size){
    if(size==0 | size==1){
        return arr[0];
    }

    int s = arr[0]+arr[1];
    s += sumOfValue(arr+2, size-2);

    return s;
}

//! 4 Approach 2
int sumOfValue1(int *arr, int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int s = arr[0] + sumOfValue1(arr+1, size-1);
    return s;
}

int main(){
    //cout<<sumOfN(5)<<endl;
    //print();
    tempRec(439);
    cout<<4%10<<endl;
    

    int arr[5] = {1, 2, 3, 4, 5};
    int result = sumOfValue1(arr, 5);
    cout<<"Result: "<<result<<endl;
    return 0;
}