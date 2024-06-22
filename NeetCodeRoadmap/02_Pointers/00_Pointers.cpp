#include <iostream>
using namespace std;

int main(){

    cout<<"Case 1: "<<endl;
    int num1 = 100;
    int *ptr1 = &num1;
    cout<<"num1: "<<num1<<endl;
    cout<<"&num1: "<<&num1<<endl;
    cout<<"*ptr1: "<<*ptr1<<endl;
    cout<<"ptr1: "<<ptr1<<endl;
    cout<<"\nSize of pointer: "<<sizeof(ptr1)<<endl;

    cout<<endl;
    cout<<"Case 2: "<<endl;
    double num2 = 12.2;
    double *ptr2 = &num2;
    cout<<"num2: "<<num2<<endl;
    cout<<"&num2: "<<&num2<<endl;
    cout<<"*ptr2: "<<&ptr2<<endl;
    cout<<"ptr2: "<<ptr2<<endl;

    cout<<endl;
    cout<<"Case 3: "<<endl;
    int num3 = 100;
    int *ptr3 = &num3;
    cout<<"num3: "<<num3<<endl;
    num3++;
    cout<<"num3++: "<<num3<<endl;
    (*ptr3)++;
    cout<<"*ptr3++: "<<*ptr3<<endl;


    //! initialization way:
    cout<<endl;
    int num4 = 120;
    int *ptr4 = 0;
    ptr4 = &num4;
    cout<<"ptr4: "<<ptr4<<endl;
    cout<<"*ptr4: "<<*ptr4<<endl;

    //! copying a pointer: 
    cout<<endl;
    int num5 = 200;
    int *ptr5 = &num5;
    int *ptr6 = ptr5;
    cout<<"num5: "<<num5<<endl;
    cout<<"&num5: "<<&num5<<endl;
    cout<<"*ptr5: "<<*ptr5<<endl;
    cout<<"ptr5: "<<ptr5<<endl;
    cout<<"*ptr6: "<<*ptr6<<endl;
    cout<<"ptr6: "<<ptr6<<endl;

    (*ptr6)++;
    cout<<"*ptr6: "<<*ptr6<<endl;
    cout<<"num5: "<<num5<<endl;

    //! addition in pointer:
    cout<<endl;
    int n = 101;
    int *p = &n;

    cout<<"n: "<<n<<endl;
    cout<<"*p: "<<*p<<endl;
    cout<<"p: "<<p<<endl;
    
    *p = *p + 1;
    cout<<"Value: "<<endl;
    cout<<"*p: "<<*p<<endl;
    cout<<"n: "<<n<<endl;
    

    p = p+1;
    cout<<"Address: "<<endl;
    cout<<"p: "<<p<<endl;
    return 0;
}