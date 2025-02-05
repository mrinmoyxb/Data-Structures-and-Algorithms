#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    private:
    Node* stack;
    Node* top;
    int size;
    int count=-1;

    public:
    Stack(int size, int data){
        this->size = size;
        this->count+=1;
        stack = new Node(data);
        top = stack; 
    }

    void push(int data){
        if(count<size-1){
            count+=1;
            Node* newNode = new Node(data);
            newNode->next = top;
            top = newNode;
        }else{
            std::cout<<"\nStack Overflow"<<"\n";
        }
    }

    void pop(){
        if(count==-1){
            std::cout<<"\nStack Underflow"<<"\n";
        }else{
            Node* delNode = top;
            std::cout<<"Popped element is: "<<delNode->data<<"\n";
            top = top->next;
            delete delNode;
            count-=1;
        }
    }

    void peak(){
        std::cout<<"\nPeak element is: "<<top->data;
    }

    void display(){
        std::cout<<"\nStack: "<<"\n";
        for(Node* current = top; current!=NULL; current=current->next){
            std::cout<<current->data<<"\n";
        }
    }

    bool isEmpty(){
        if(count==-1){
            return true;
        }else{
            return false;
        }
    }

};

int main(){
    Stack s = Stack(5, 100);
    s.push(200);

    s.display();
    s.pop();
    s.pop();
    s.pop();

    std::cout<<"Is stack empty: "<<s.isEmpty();
    return 0;
}