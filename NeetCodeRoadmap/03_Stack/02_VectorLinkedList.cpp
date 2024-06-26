#include <iostream>
#include <vector>
using namespace std;

class Stack{
    public:
    int size;
    int top = -1;
    vector<int> stack;

    Stack(int size){
        this->size = size;
        //stack.resize(size);
    }

    void push(int data){
        if(top<size-1){
            top++;
            stack.push_back(data);
        }
        else{
            cout<<"Stack Overflow, can't push"<<data<<endl;
        }
    }

    void pop(){
        if(top>-1){
            cout<<"Popped element: "<<stack[top]<<endl;
            stack.pop_back();
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

int main(){
    Stack s = Stack(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    return 0;
}