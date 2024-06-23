#include <iostream>
using namespace std;

void referenceBasic1(){
    int num1 = 5;
    int &ref1 = num1; //* reference variable using &
    cout<<"Before updating: "<<endl;
    cout<<"num1: "<<num1<<endl;
    cout<<"ref1: "<<ref1<<endl;

    ref1++;
    
    cout<<"After updating(ref++): "<<endl;
    cout<<"num1: "<<num1<<endl;
    cout<<"ref1: "<<ref1<<endl;
}

void updateUsingReference(int &num){
    num++;
}

int main(){
    //referenceBasic1();

    int num = 10;
    cout<<"Before: "<<num<<endl;
    updateUsingReference(num);
    cout<<"After: "<<num<<endl;
    return 0;
}

//* KEY CONCEPTS:
//? Functions follow the concept of "pass by value"
//? We use "&reference" variable to follow "pass by reference",
//? we just provide a new identity/name to the old initialised variable