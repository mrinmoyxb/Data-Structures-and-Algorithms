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
    public:
    Node* head = NULL;
    int count = 0;
    int size = 0;
    Stack(int size){
        this->size = size;
    }
    
    void push(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            count+=1;
        }else{
            if(count<size){
                newNode->next = head;
                head = newNode;
                count+=1;
            }else{
                std::cout<<"\nStack Overflow"<<std::endl;
            }
        }
    }

    void pop(){
        if(head==NULL){
            std::cout<<"stack underflow"<<std::endl;
        }else{
            Node* temp = head;
            head = temp->next;
            delete temp;
            count-=1;
        }
    }

    int sizeOfStack(){
        return count;
    }

    void peek(){
        std::cout<<head->data<<" ";
    }
    
    bool isEmpty(){
        if(count==0){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if(count==size){
            return true;
        }else{
            return false;
        }
    }

    void display(){
        std::cout<<"\nStack"<<std::endl;
        Node* current = head;
        while(current!=NULL){
            std::cout<<current->data<<std::endl;
            current = current->next;
        }
    }
};

int main(){
    Stack s = Stack(5);
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    // s.push(500);
    // s.push(600);

    s.display();
    std::cout<<"Is stack empty: "<<s.isEmpty()<<std::endl;
    std::cout<<"Is stack full: "<<s.isFull()<<std::endl;
    s.peek();
    
    return 0;
}