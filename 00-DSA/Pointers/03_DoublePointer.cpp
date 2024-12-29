#include <iostream>
using namespace std;

void doublePointer(){
    int num = 5;
    int *p1 = &num;
    int **p2 = &p1;

    cout<<"Value at num: "<<num<<endl;
    cout<<"Value at *p1: "<<*p1<<endl;
    cout<<"Value at **p2: "<<**p2<<endl;
    cout<<"Value at *p2: "<<*p2<<endl;

    cout<<"\nAddress of &num: "<<&num<<endl;
    cout<<"Address of p1: "<<p1<<endl;
    cout<<"Address of &p1: "<<&p1<<endl;
    cout<<"Address of p2: "<<p2<<endl;

    cout<<"\nValue of num: "<<endl;
    cout<<"Using num: "<<num<<endl;
    cout<<"Using *p1: "<<*p1<<endl;
    cout<<"Using **p2: "<<**p2<<endl;

    cout<<"\nAddress of num: "<<endl;
    cout<<"Using &num: "<<&num<<endl;
    cout<<"Using p1: "<<p1<<endl;
    cout<<"Using *p2: "<<*p2<<endl;

    cout<<"\nAccessing addresses of p2: "<<endl;
    cout<<"Using &p1: "<<&p1<<endl;
    cout<<"Using p2: "<<p2<<endl;
}

void doublePointer1(){
    //! Key points
    //! We can access the value of ptr1 using *ptr1
    //! We can access the value of num using *ptr1 and **ptr2
    //! ptr1 = *ptr2
    //! *ptr1 = **ptr2

    int num = 5;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;

    cout<<"ptr1: "<<ptr1<<"     "<<"*ptr2: "<<*ptr2<<endl;
    cout<<"*ptr1: "<<*ptr1<<"     "<<"**ptr2: "<<**ptr2<<endl;
}

int main(){
    doublePointer1();
    return 0;
}