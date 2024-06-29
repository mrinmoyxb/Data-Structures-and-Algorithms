#include <iostream>
using namespace std;

class Stack{
    public:
    int size;
    int *stack;
    int top;

    Stack(int size){
        this->size = size;
        stack = new int[size];
        top = -1;
    }

    void push(int data){
        if(top<size-1){
            top++;
            stack[top] = data;
        }
        else{
            cout<<"Stack Overflow, can't push "<<data<<endl;
        }
    }

    void pop(){
        if(top>-1){
            cout<<"The popped element is: "<<stack[top];
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    void display(){
        cout<<"Stack is: "<<endl;
        for(int i=top; i>=0; i--){
            cout<<stack[i]<<endl;
        }
    }


};

void test(){
    int top = -1;
    int size = 5;
    while(top<size-1){
        cout<<"yes "<<top<<" is less than "<<size<<endl;
        top++;
        cout<<"(A)top: "<<top<<endl;
    }
    
}

int main(){

    Stack s = Stack(5);
    s.push(10);
    s.push(20);


    return 0;
}