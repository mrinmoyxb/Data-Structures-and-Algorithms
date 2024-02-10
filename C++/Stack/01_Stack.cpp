//! Stack using array data structure -> 

#include <iostream>
using namespace std;

class Stack{
    int *stack;
    int size;
    int top;

    public:
    Stack(int size){
        this->size = size;
        stack = new int[size];
        top = -1;
    }

    void push(int data){
        if(size-top>1){
            top++;
            stack[top] = data;
        }
        else{
            cout<<"Stack Overflow!!!"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            cout<<"Popped element is: "<<stack[top]<<endl;
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    void display(){
        cout<<"Stack: "<<endl;
        for(int i=top; i>=0; i--){
            cout<<stack[i]<<endl;
        }
        cout<<endl;
    }
};

int main(){
    Stack s1 = Stack(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.display();
    s1.pop();
    s1.display();
    return 0;
}