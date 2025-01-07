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
    Node* stackLinkedList = NULL;
    Node* current = NULL;
    int size;
    int top;

    Stack(int size){
        this->size = size;
        top = -1;
    }

    void push(int data){
        if(top<size-1){
            if(top==-1){
                stackLinkedList = new Node(data);
                current = stackLinkedList;
                top++;
            }else{
                Node* newNode = new Node(data);
                current->next = newNode;
                current = newNode;
                top++;
            }
        }else{
            std::cout<<"Stack overflow"<<std::endl;
        }
    }

    void display(){
        std::cout<<"\nLinked list: "<<std::endl;
        while(stackLinkedList!=NULL){
            std::cout<<stackLinkedList->data<<std::endl;
            stackLinkedList = stackLinkedList->next;
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
    return 0;
}