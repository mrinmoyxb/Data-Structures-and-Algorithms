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
    int size;
    Node* stack;
    Node* head;
    Stack(int size){
        this->size = size;
        stack = NULL;
        head = NULL;
    }

    //! Insert at head
    void push(int data){
        if(stack==NULL){
            stack = new Node(data);
            head = stack;
            size-=1;
        }else{
            if(size!=0){
                Node* newNode = new Node(data);
                newNode->next = head;
                head = newNode;
                size-=1;
            }else{
                std::cout<<"Stack Overflow";
            }
        }
    }

    //! Delete top element
    void pop(){
        if(stack==NULL){
            std::cout<<"\nStack Underflow"<<"\n";
        }else{
            Node* deleteNode = head;
            std::cout<<"\nPopped element: "<<deleteNode->data<<"\n";
            head = head->next;
            deleteNode->next = NULL;
            delete deleteNode;
            deleteNode = nullptr;
            size+=1;
        }
    }

    //! Peak element
    int peak(){
        return head->data;
    }

    //! Display
    void display(){
        std::cout<<"\nStack: "<<"\n";
        Node* current = head;
        while(current!=NULL){
            std::cout<<current->data<<"\n";
            current = current->next;
        }
    }

    //! Length
    int length(){
        Node* current = head;
        int count = 0;
        while(current!=NULL){
            count+=1;
            current = current->next;
        }
        return count;
    }

    //! Reverse Linked List
    void reverseStack(){
        Node* current = head;
        Node* prev = NULL;
        Node* forward = NULL;
        while(current!=NULL){
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        
        Node* revNode = prev;
        std::cout<<"\nReverse Linked List: "<<"\n";
        while(revNode!=NULL){
            std::cout<<revNode->data<<" ";
            revNode = revNode->next;
        }
    }

};

int main(){
    Stack* s = new Stack(3);
    s->push(100);
    s->push(200);
    s->push(300);
    s->display();
    // std::cout<<"Length: "<<s->length()<<"\n";

    // std::cout<<"Top element: "<<s->peak();
    // s->pop();
    // s->push(500);
    // s->display();
    // std::cout<<"Top element: "<<s->peak();

    s->reverseStack();
    
    return 0;
}