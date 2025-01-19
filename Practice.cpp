#include <iostream>
using namespace std;

//! Check whether an array is sorted
bool isArraySorted(int *arr, int size){
    if(size==1){
        return true;
    }

    if(*arr > *(arr+1)){
        return false;
    }
    else{
        return isArraySorted(arr+1, size-1);
    }
}

//! Max element in an array
int max(int a, int b){
    return a>b?a:b;
}

int maxElement(int *arr, int size){
    if(size==1){
        return *arr;
    }

    return max(*arr, maxElement(arr+1, size-1));
}

//! Min element in an array
int min(int a, int b){ 
    return a<b?a:b;
}

int minElement(int *arr, int size){
    if(size==1){
        return *arr;
    }

    return min(*arr, minElement(arr+1, size-1));
}

void check(int *&arr){
    cout<<"Address arr: "<<arr<<"\n";
    cout<<"Address of arr(&arr): "<<&arr<<"\n";
}

int main(){
    int *arr = new int[5];
   
    for(int i=0; i<5; i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }

    for(int i=0; i<5; i++){
        cout<<*(arr+i)<<endl;
    }

    cout<<"Main: "<<"\n";
    cout<<"Address arr: "<<arr<<"\n";
    cout<<"Address of arr(&arr): "<<&arr<<"\n";
    check(arr);

    // // cout<<"Is array sorted: "<<array1(arr, 5)<<endl;
    // cout<<"Max: "<<maxElement(arr, 5)<<endl;
    // cout<<"Min: "<<minElement(arr, 5)<<endl;

    return 0;
}