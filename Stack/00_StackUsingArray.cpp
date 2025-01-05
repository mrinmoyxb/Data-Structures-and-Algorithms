#include <iostream>

class Stack{
    public:
    int *stack;
    int size;
    int top;

    Stack(int size){
        this->size = size;
        stack = new int[size];
        this->top = -1;
    }

    void push(int data){
        if(top<size-1){
            top++;
            stack[top] = data;
        }else{
            std::cout<<"Stack Overflow"<<std::endl;
        }
    }

    void pop(int data){
        if(top>=0){
            std::cout<<"Popped element: "<<stack[top]<<std::endl;
            top--;
        }else{
            std::cout<<"Stack Underflow"<<std::endl;
        }
    }

    void peak(){
        std::cout<<"Peak element: "<<stack[top]<<std::endl;
    }

    void display(){
        std::cout<<"Stack: "<<std::endl;
        for(int i=top; i>=0; i--){
            std::cout<<stack[i]<<std::endl;
        }
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
    s1.peak();
    return 0;
}