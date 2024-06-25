#include <iostream>
using namespace std;

int main(){

    int *i = new int;
    *i = 5;
    cout<<"*i: "<<*i<<endl;
    cout<<"i: "<<i<<endl;

    //* creating an array in heap/ dynamic memory: 
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int *arr = new int[size];
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    cout<<"Arary iteration using dynamic memory: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    

    delete arr;

    return 0;
}