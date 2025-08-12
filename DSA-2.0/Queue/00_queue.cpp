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

class Queue{
    public:
    Node* head = NULL;
    Node* tail = NULL;

    void enqueue(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue(){
        Node* temp = head;
        if(head->next==NULL){
            head = tail = NULL;
            delete temp;
        }else{
            head = head->next;
            delete temp;
        }
    }

    int front(){
        if(head==NULL){
            return -1;
        }else{
            return head->data;
        }
    }

    void display(){
        std::cout<<"\nQueue: "<<std::endl;
        Node* current = head;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    bool isNull(){
        if(head==NULL){
            return true;
        }else{
            return false;
        }
    }

    ~Queue(){
        Node* current = head;
        while(current!=NULL){
            Node* forward = current->next;
            Node* temp = current;
            delete temp;
            current = forward;
        }
    }
};

int main(){
    Queue s;
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.display();
    std::cout<<"\nFront: "<<s.front()<<std::endl;

    s.dequeue();
    s.display();
    std::cout<<"\nFront: "<<s.front()<<std::endl;
    std::cout<<"\nIs NULL: "<<s.isNull()<<std::endl;
    
    return 0;
}