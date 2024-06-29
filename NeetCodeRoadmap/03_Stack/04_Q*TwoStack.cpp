#include <iostream>
using namespace std;

class Stack{
    public:
    int size;
    int *arr;
    int top1;
    int top2;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if(top2-top1>1){
            top1++;
            arr[top1] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void push2(int data){
        if(top2-top1>1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    void pop1(){
        if(top1>-1){
            cout<<"Popped element is: "<<arr[top1]<<endl;
            top1--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    void pop2(){
        if(top2<size-1){
            cout<<"Popped element is: "<<arr[top2]<<endl;
            top2++;
        }
        else{
            cout<<"Stack Undeflow"<<endl;
        }
    }

    void display1(){
        cout<<"Stack 1: "<<endl;
        for(int i=top1; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }

    void display2(){
        cout<<"Stack 2: "<<endl;
        for(int i=top2; i<size; i++){
            cout<<arr[i]<<endl;
        }
    }


};

int main(){
    Stack s = Stack(5);
    s.push1(10);
    s.push1(11);
    s.push1(12);
    s.push2(21);
    s.push2(22);

    s.display1();

    cout<<endl;
    s.display2();
    return 0;
}