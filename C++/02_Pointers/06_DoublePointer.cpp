#include <iostream>
using namespace std;

void doublePointer(){
    int num = 10;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;

    cout<<"num: "<<num<<endl;
    cout<<"*ptr1: "<<*ptr1<<endl;
    cout<<"**ptr2: "<<**ptr2<<endl;

    cout<<endl;

    cout<<"num: "<< num<<endl;
    cout<<"*ptr1: "<< *ptr1<<endl;
    cout<<"&num: "<< &num<<endl;
    cout<<"ptr1: "<< ptr1<<endl;
    cout<<"*ptr2: "<< *ptr2<<endl;

    cout<<endl;

    cout<<"&ptr1: "<< &ptr1<<endl;
    cout<<"ptr2: "<< ptr2<<endl;
}


void doublePointer2(){
    int num = 100;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;

    cout<<"Case 1: "<<endl;
    cout<<"num: "<<num<<endl;
    cout<<"*ptr1: "<<*ptr1<<endl;
    cout<<"**ptr2: "<<**ptr2<<endl;

    cout<<endl;

    cout<<"Case 2: "<<endl;
    cout<<"&num: "<< &num<<endl;
    cout<<"ptr1: "<< ptr1<<endl;
    cout<<"*ptr2: "<< *ptr2<<endl;

    cout<<endl;

    cout<<"Case 3: "<<endl;
    cout<<"ptr2: "<< ptr2<<endl;
    cout<<"&ptr1: "<< &ptr1<<endl;
}

int main(){
    doublePointer2();
    return 0;
}