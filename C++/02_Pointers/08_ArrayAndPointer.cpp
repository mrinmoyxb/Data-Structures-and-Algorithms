#include <iostream>
using namespace std;

void integerArray(){

    int arr[5] = {10, 20, 30, 40, 50};
    
    cout<<"Array is: "<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    cout<<"CASE 1: index 0: "<<endl;
    cout<<"arr(Address): "<<arr<<endl;
    cout<<"&arr[0] (Address): "<< &arr[0]<<endl;
    cout<<"*arr (Value): "<< *arr<<endl;
    cout<<"arr[0] (Value): "<< arr[0]<<endl;

    cout<<endl;
    cout<<"CASE 2: index 1: "<<endl;
    cout<<"(arr + 1) (Address): "<< (arr+1)<<endl;
    cout<<"&arr[1] (Address): "<< &arr[1]<<endl;
    cout<<"*(arr+1) (Value): "<< *(arr+1) <<endl;
    cout<<"arr[1]: "<< arr[1] <<endl;

    cout<<endl;
    cout<<"CASE 3: Manipulation: "<<endl;
    cout<<"Before: value at index 3: "<< *(arr+3)<<endl;
    *(arr+2)+=10;
    cout<<"*(arr+2)+=10"<<endl;
    cout<<"After: value at index 3: "<< *(arr+3)<<endl;

    cout<<endl;
    cout<<"Array is: "<<endl;
    for(int i=0; i<5; i++){
        cout<<i[arr]<<" ";
    }
}

void characterArray(){
    char c[6] = {'A', 'B', 'C', 'D', 'E', '\0'};
    
    cout<<"Character array: "<<endl;
    cout<<c<<endl;
    cout<<"Iteration: "<<endl;
    for(int i=0; i<6; i++){
        cout<<c[i]<<" ";
    }

    cout<<"char array and pointer: "<<endl;
    char *ptr = &c[0];
    
    cout<<endl;
    cout<<"At index 0: "<<endl;
    cout<<"ptr (Address): "<< (void*)ptr<<endl;
    cout<<"&ptr[0] (Address): "<< (void*)&ptr[0]<<endl;
    cout<<"*ptr (Value): "<< *ptr<<endl;
    cout<<"c[0] (Value): "<< c[0]<<endl;

    cout<<endl;
    cout<<"At index 1: "<<endl;
    cout<<"(ptr+1): "<< ((void*)ptr+1)<<endl;
    cout<<"&c[1]: "<< (void*)&c[1]<<endl;

}

void charAddress(){
    cout<<endl;
    cout<<"Char Pointer"<<endl;
    char c1 = 'A';
    char *cp  = &c1;
    cout<<(void*)cp<<endl;
    cout<<*cp<<endl;

}

int main(){

    characterArray();
    charAddress();

    return 0;
}