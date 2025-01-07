#include <iostream>
#include <vector>

class Stack{
    public:
    int size;
    int top;
    int *arr;

    Stack(int size){
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }

    void push(int data){
        if(top<size-1){
            top++;
            arr[top] = data;
        }else{
            std::cout<<"Stack overflow"<<std::endl;
        }
    }

    void pop(){
        if(top==-1){
            std::cout<<"Stack underflow"<<std::endl;
        }else{
            std::cout<<"\nPopped element is: "<<arr[top]<<std::endl;
            top--;
        }
    }

    void peak(){
        if(top==-1){
            std::cout<<"Stack undeflow"<<std::endl;
        }else{
            std::cout<<"\nPeak element: "<<arr[top]<<" "<<top<<std::endl;
        }
    }

    void display(){
        std::cout<<"\nStack is: "<<std::endl;
        for(int i=top; i>=0; i--){
            std::cout<<arr[i]<<std::endl;
        }
    }

    void reverse(){
        std::vector<int> v;
       
        for(int i=0; i<=top; i++){
            v.push_back(arr[i]);
        }
        
        std::cout<<"\nReverse Stack: "<<std::endl;
        for(int i=0; i<v.size(); i++){
            std::cout<<v[i]<<std::endl;
        }

    }
};

int main(){
    Stack s = Stack(5);
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    s.push(500);

    s.display();
    s.reverse();
    s.pop();

    s.display();
    s.reverse();
    
    return 0;
}