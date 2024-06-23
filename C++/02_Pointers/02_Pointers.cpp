#include <iostream>
using namespace std;

void printfunc(int *p){
    *p = *p + 1;
     p = p + 1;
}

int main(){
    int num = 10;
    int *ptr = &num;

    cout<<"Before: "<<*ptr<<endl;
    cout<<"Before: "<<ptr<<endl;
    printfunc(ptr);
    cout<<"After: "<<*ptr<<endl;
    cout<<"After: "<<ptr<<endl;
    return 0;
}

// Value: pass by reference && Address: pass by value