#include <iostream>
using namespace std;

void mergeArray(int arr1[], int arr2[], int size1, int size2){
    int size3 = size1 + size2;
    int arr3[size3];
    int i=0, j=0, k=0;
    int iteration = 1;
    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }

    while(i<size1){
        arr3[k++] = arr1[i++];
    }

    while(j<size2){
        arr3[k++] = arr2[j++];
    }

    cout<<"Merged sorted array: "<<endl;
    for(int i=0; i<size3; i++){
        cout<<arr3[i]<<" ";
    }
}

void merge(int *arr, int start, int end){
    int mid = start + (end-start)/2;
    int len1 = mid-start+1;
    int len2 = end-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = start;
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[k++];
    }

    int index1=0, index2=0;
    k=start;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
        }
    }

    while(index1<len1){
        arr[k++] = first[index1++];
    }

    while(index2<len2){
        arr[k++] = second[index2++];
    }
}

void mergeSort(int *arr, int start, int end){
    if(start>=end){
        return;
    }
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, end);
}

int main(){

    int arr[5] = {10, 2, 3, 55, 50};
    int size = 5;

    mergeSort(arr, 0, size-1);

    cout<<"Sorted array: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}