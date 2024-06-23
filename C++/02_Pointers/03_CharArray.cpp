#include <iostream>
using namespace std;

int main(){
    cout<<"Method 1: "<<endl;
    char arr1[6] = {'A', 'B', 'C', 'D', 'E', '\0'};
    for(int i=0; i<6; i++){
        cout<<arr1[i]<<" ";
    }

    cout<<"\narr1: "<<endl;
    cout<<arr1<<endl;

    cout<<"\nCharacter and Pointer: "<<endl;
    char x = 'A';
    char *ptr = &x;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"x: "<<x<<endl;
    cout<<"&x: "<<&x<<endl;

    cout<<"\nMethod 2: "<<endl;
    char arr2[] = "Hello World";
    cout<<arr2<<endl;

    cout<<"\nCharacter array and pointer at index 0: "<<endl;
    char *c1 = &arr1[0];
    cout<<"c: "<<c1<<endl; /* returns the entire array instead of address*/
    cout<<"*c: "<<*c1<<endl; /*returns the element at arr[0] or at provided index*/

    cout<<"\nCharacter array and pointer at index 1: "<<endl;
    char *c2 = &arr1[1];
    cout<<"c: "<<c2<<endl; /* returns the entire array starting from given index, instead of address*/
    cout<<"*c: "<<*c2<<endl; /*returns the element at arr[1] or at provided index*/

    return 0;
}