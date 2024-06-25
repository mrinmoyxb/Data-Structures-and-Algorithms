#include <iostream>
using namespace std;

//! Bad Practice
/* Since "n" is a local variable and "&ans" is a reference to n, */
/* we can't return the value (&ans) because &ans is referencing to a local variable */
/* who can't exist outside the function in reference*/

int &func(int num){
    int n = num;
    int &ans = n;
    return ans;
}

//! Bad Practice
/* Knowing size of array at runtime is a bad practice*/

//! Heap Memory -> Dynamic memory Allocation
void heapMemory(){
    char *ch = new char; 
    // we can't name any variable in heap, it only returns address of memory allocated hence we use pointer to store the address
    // the pointer *ch is allocated in stack

    int *i = new int;
    *i = 10;
    cout<<"i: "<<endl;
}

int main(){
    return 0;
}