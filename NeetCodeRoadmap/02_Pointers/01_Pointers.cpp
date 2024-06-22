#include <iostream>
using namespace std;

int main(){

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


    return 0;
}

//! Key concept
//? index[array_name] = returns the value stored at that index 