#include <iostream>
using namespace std;

void check(){
    int first = 10;
    int *p = &first;
    int **q = &p;
    cout<<"First: "<<first<<endl;
    int second = ++(**q);
    cout<<first<<endl;
    cout<<second<<endl;
    int *r = *q; //! here *q returns address and *r is value at that address
    cout<<*q<<endl;
    cout<<*r<<endl;
    ++(*r);
    cout<<first<<"    "<<second<<endl;
}

int main(){
    check();
    return 0;
}