#include <iostream>
using namespace std;

void pointers1(){
    //! Address of operator:
    int num = 5;
    cout<<"Num: "<<num<<endl;
    cout<<"Address of num(&num): "<<&num<<endl;

    //! Pointers: Variables that stores the address of another variable
    int* ptr = &num;
    cout<<"\nValue of num: "<<num<<endl;
    cout<<"Value of num(*ptr): "<<*ptr<<endl;
    cout<<"Address of num(ptr): "<<ptr<<endl;
    cout<<"Value of num(&num): "<<num<<endl;
}


void pointers2(){
    //! Pointers with different datatypes of C++
    int num1 = 10;
    float num2 = 100.2;
    double num3 = 100.12;
    char var = 'A';

    int *ptr1 = &num1;
    float *ptr2 = &num2;
    double *ptr3 = &num3;
    char *ptr4 = &var;

    cout<<"Num1: "<<num1<<endl;
    cout<<"*ptr1: "<<*ptr1<<endl;
    cout<<"&num1: "<<&num1<<endl;
    cout<<"ptr1: "<<ptr1<<endl;

    cout<<"\nNum2: "<<num2<<endl;
    cout<<"*ptr2: "<<*ptr2<<endl;
    cout<<"&num2: "<<&num2<<endl;
    cout<<"ptr2: "<<ptr2<<endl;

    cout<<"\nNum3: "<<num3<<endl;
    cout<<"*ptr3: "<<*ptr3<<endl;
    cout<<"&num3: "<<&num3<<endl;
    cout<<"ptr3: "<<ptr3<<endl;

    //! If i need to access the address of char i must use (void*) for both ptr and &var
    cout<<"\nChar: "<<var<<endl;
    cout<<"*ptr4: "<<*ptr4<<endl;
    cout<<"*ptr4: "<<(void*)ptr4<<endl;
    cout<<"&var: "<<(void*)&var<<endl;

    cout<<endl;
    cout<<"Size of pointers: "<<endl;
    cout<<"ptr1 int: "<<sizeof(ptr1)<<endl;
    cout<<"ptr4 char: "<<sizeof(ptr4)<<endl;
    
}

void pointer3(){

    //! Size of pointer is of always 8 bytes
    //! Size of function: sizeof()
    //! Always intialize a pointer or else just assign 0. Null pointer is dangerous

    int num = 100;
    int *ptr = &num;

    cout<<"Num is: "<<num<<endl;
    cout<<"*Ptr is: "<<*ptr<<endl;
    cout<<"Address &num: "<<&num<<endl;
    cout<<"Address ptr: "<<ptr<<endl;
    cout<<"size of int: "<<sizeof(num)<<endl;
    cout<<"size of *ptr: "<<sizeof(*ptr)<<endl;
    cout<<"size of ptr: "<<sizeof(ptr)<<endl;


    //! Another way of initializing variable
    int num1 = 100;
    int *ptr1 = 0;
    ptr1 = &num1;
    cout<<"\nNum is: "<<*ptr1<<endl;
    cout<<"Address is: "<<ptr1<<" and "<<&num1<<endl;
}

void pointers4(){
    //! We can modify values of a variable with pointers, Acts as a reference
    int n = 100;
    int *ptr = &n;

    cout<<"Before n"<<endl;
    cout<<n<<endl;
    cout<<*ptr<<endl;

    n+=1;
    cout<<"After n++: "<<endl;
    cout<<n<<endl;
    cout<<*ptr<<endl;

    *ptr+=1;
    cout<<n<<endl;
    cout<<*ptr<<endl;


    //! Here copy variable can't modify, as it is not a reference
    cout<<endl;
    int num = 100;
    int cnum = num;
    cout<<num<<endl;
    cout<<cnum<<endl;
    num+=1;
    cout<<num<<endl;
    cout<<cnum<<endl;
}

void pointers5(){
    //! Any changes occur in copying variable if it is copied using reference
    int num = 100;
    int cnum = num;
    int *ptr = &num;

    cout<<"Before: "<<endl;
    cout<<num<<endl;
    cout<<cnum<<endl;
    cout<<*ptr<<endl;

    *ptr+=1;
    cout<<"After: "<<endl;
    cout<<num<<endl;
    cout<<cnum<<endl;
    cout<<*ptr<<endl;
}

void pointers6(){
    //! Copying a pointer
    int num = 100;
    int *ptr = &num;
    int *cptr = ptr;

    cout<<num<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"*cptr: "<<*cptr<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"cptr: "<<cptr<<endl;

    cout<<"\nAfter: "<<endl;
    *cptr += 1;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"*cptr: "<<*cptr<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"cptr: "<<cptr<<endl;
}

void pointers7(){
    //! Pointers arithmetic
    int num = 100;
    int *ptr = &num;

    cout<<"Before: "<<endl;
    cout<<"num: "<<num<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"&num: "<<&num<<endl;
    cout<<"ptr: "<<ptr<<endl;

    //! Incrementing value:
    cout<<"After incrementing value: "<<endl;
    *ptr+=1;
    cout<<"\nnum: "<<num<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"&num: "<<&num<<endl;
    cout<<"ptr: "<<ptr<<endl;

    //! Incrementing address:
    cout<<"After incrementing address: "<<endl;
    ptr+=1;
    cout<<"\nnum: "<<num<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"&num: "<<&num<<endl;
    cout<<"ptr: "<<ptr<<endl;
}

int main(){
    pointers2();
}






















