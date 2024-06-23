#include <iostream>
using namespace std;

void print(int *ptr){

    cout<<"Address(ptr): "<< ptr<<endl;
    cout<<"Value(*ptr): "<< *ptr<<endl;
}

void update(int *ptr){
    (*ptr) += 10;

    cout<<"\nValues inside update function: "<<endl;
    cout<<"Value: "<<*ptr<<endl;
    cout<<"Address: "<<ptr<<endl;
}

int main(){

    int num = 10;
    int *ptr = &num;
    //print(ptr);

    cout<<"Before: "<<endl;
    cout<<"Value of num (inside main): "<<num<<endl;
    cout<<"Value of num (inside main): "<<*ptr<<endl;

    update(ptr);

    cout<<"\nAfter: "<<endl;
    cout<<"Value of num (inside main): "<<num<<endl;
    cout<<"Value of num (inside main): "<<*ptr<<endl;

    return 0;
}