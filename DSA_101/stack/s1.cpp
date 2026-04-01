#include <iostream>
#define MAX 100

int size = -1, top = -1;
int stack[MAX];

void push(int data){
    if(top<size-1){
        top+=1;
        stack[top] = data;
    }else{
        std::cout<<"Stack Overflow, can't push "<<data<<std::endl;
    }
}

void pop(){
    if(top==-1){
        std::cout<<"Stack is underflow"<<std::endl;
    }else{
        std::cout<<"The popped element: "<<stack[top]<<std::endl;
        top--;
    }
}

void display(){
    std::cout<<"\nStack: "<<std::endl;
    for(int i=top; i>=0; i--){
        std::cout<<stack[i]<<std::endl;
    }
}

bool isEmpty(){
    if(top==-1){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if(top==-1){
        return false;
    }else{
        return true;
    }
}

void peek(){
    std::cout<<"Peak element: "<<stack[top]<<std::endl;
}

int main(){
    size = 5;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    display();
    peek();

    pop();
    display();
    peek();

    push(6);
    display();
    peek();

    return 0;
}