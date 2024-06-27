#include <iostream>
using namespace std;

void merge(){
    int size1 = 5;
    int size2 = 3;
    int size3 = size1+size2;
    int arr1[size1] = {12, 13, 14, 20, 40};
    int arr2[size2] = {10, 15, 30};
    
    int arr[size3];

    int i = 0;
    int j = 0;
    while(i<size3 || j<size3){
        if(arr1[i]<arr2[j]){
            arr[i] = arr1[i];
            i++;
        }
        else{
            arr[i]
        }
    }
}

int main(){
    return 0;
}