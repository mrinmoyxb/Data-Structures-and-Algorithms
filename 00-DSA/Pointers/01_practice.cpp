#include <iostream>
using namespace std;


void question1(){
    //! Here in this question we stored the address of f in ptr,
    //! and with *ptr = p, we are just changing the value of f from 10.5 to 2.5

    //! int *ptr = n; without storing address of any variable before is WRONG
    float f = 10.5;
    float p = 2.5;
    float* ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout << *ptr <<" "<<f<<" "<< p;
}

void question2(){
    int a = 7;
    int b = 17;
    int *c = &b;
    *c = 7;
    cout<<a<<" "<<b<< endl;
}

void question3(){
    //! Example of segmentation fault
    int *ptr = 0;
    int a = 10;
    *ptr = a;
    cout << *ptr << endl;
}

void question4(){
    //! When we increment a char with ch++ it increases alphabetically instead of increment of ASCII
    //! If we increment z, it returns {
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl;
}

void question5(){
    int a = 7;
    int *c = &a;
    c = c + 1;
    cout  << a << "  " << *c << endl;
}

void question6(){
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

}

int main(){
    // question1();
    // question2();
    // question3();
    // question4();
    question5();
    return 0;
}