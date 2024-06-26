#include <iostream>
using namespace std;

class Stack{
    public:
    int *stack;
    int size;
    int top;

    Stack(int size){
        this->size = size;
        stack = new int[this->size];
        top=-1;
    }

    void push(int data){
        if(top<size-1){
            top++;
            stack[top] = data;
        }
        else{
            cout<<"Stack Overflow, can't push element: "<<data<<endl;
        }
    }


    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            cout<<"Deleted element is: "<<stack[top]<<endl;
            top--;
        }
    }

    void display(){
        if(top>-1){
            cout<<"\nStack is: "<<endl;
            for(int i=top; i>=0; i--){
                cout<<stack[i]<<endl;
            }
        }
        else{
            cout<<"Stack is empty!!"<<endl;
        }
    }

    void noOfElements(){
        int count = 0;
        for(int i=top; i>=0; i--){
            count+=1;
        }
        cout<<"No of elements: "<<count<<endl;
    }

    void topElement(){
        cout<<"Top element: "<<stack[top]<<endl;
    }

    void deleteStack(){
        char option;
        cout<<"\nAre you sure to delete the stack(y/n): ";
        cin>>option;
        if(option=='y' || option=='Y'){
            top = -1;
            delete []stack;
            display();
        }
        else if(option=='n' || option=='N'){
            cout<<"Okay"<<endl;
            display();
        }
        else{
            cout<<"Insert a valid response!";
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
    s.push(60);
    s.display();
    s.noOfElements();
    s.topElement();

    s.pop();
    s.display();
    s.noOfElements();
    s.topElement();

    s.deleteStack();
    return 0;
}