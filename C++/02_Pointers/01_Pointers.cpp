#include <iostream>
using namespace std;

void arrayPointer(){
    int array1[5] = {10, 20, 30, 40, 50};

    cout<<"Array: "<<endl;
    for(int i=0; i<5; i++){
        cout<<array1[i]<<" ";
    }

    cout<<"\nAddress of array1[0]: "<< array1<<endl;
    cout<<"Address of array1[0]: "<< &array1[0]<<endl;
    cout<<"Value at array1[0]: "<< array1[0]<<endl;
    cout<<"Value at array1[0]: "<< *array1<<endl;

    cout<<"\nValue at array1[1]: "<< array1[1]<<endl;
    cout<<"Value at array1[1]: "<< *(array1 + 1)<<endl;
    cout<<"Address at array1[1]: "<<&array1[1]<<endl;
    cout<<"Address at array1[1]: "<<(array1 + 1)<<endl;

    cout<<"\nindex[arrayName]: "<<2[array1]<<endl;

    int *ptr = &array1[0];
    cout<<"\nAddress of array1: "<<array1<<endl;
    cout<<"Address of array1[0]: "<<&array1[0]<<endl;
    cout<<"Address of array1[0]: "<<ptr<<endl;

    cout<<"Value at array1[0]: "<<array1[0]<<endl;
    cout<<"Value at array1[0]: "<<*(array1)<<endl;;
    cout<<"Value at array1[0]: "<<*ptr<<endl;
    cout<<"Address of *ptr: "<<&ptr<<endl;
}


void arrayPointer2(){
    int arr[5] = {102, 103, 104, 105, 106};

    cout<<"Concept 1: "<<endl;
    int *ptr = arr;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"arr[0]: "<<arr[0]<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"arr: "<<arr<<endl;

    cout<<"\nConcept 2: "<<endl;
    cout<<"arr[1]: "<<arr[1]<<endl;
    cout<<"*(arr + 1): "<<*(arr + 1)<<endl;
    cout<<"*(ptr + 1): "<<*(ptr + 1)<<endl;
    cout<<"arr[1] + 10: "<< (*(arr + 1) + 10)<<endl;

    cout<<"\nConcept 3: "<<endl;
    cout<<"Address of arr[2]: "<<&arr[1]<<endl;
    cout<<"Address of arr[2]: "<<(arr + 1)<<endl;

}


int main(){
    arrayPointer2();
    return 0;
}

//! Key concept
//? index[array_name] = returns the value stored at that index 