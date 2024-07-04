#include <iostream>
using namespace std;

void MergeArray(int arr1[], int n1, int arr2[], int n2){
    int i = 0, j = 0, k = 0;
    int size = n1+n2;
    int arr3[size] = {};

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }

    while(i<n2){
        arr3[k++] = arr1[i++];
    }

    while(j<n2){
        arr3[k++] = arr2[j++];
    }

    cout<<"\nSorted Array: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr3[i]<<" ";
    }
}


int main(){
    int arr1[5] = {2, 3, 8, 10, 12};
    int arr2[3] = {1, 14, 40};

    cout<<"\nArray1: "<<endl;
    for(int i=0; i<5; i++){
        cout<<arr1[i]<<" ";
    }

    cout<<"\nArray2: "<<endl;
    for(int i=0; i<3; i++){
        cout<<arr2[i]<<" ";
    }
    MergeArray(arr1, 5, arr2, 3);
    return 0;
}