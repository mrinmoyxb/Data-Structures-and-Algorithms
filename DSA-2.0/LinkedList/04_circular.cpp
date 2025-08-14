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

class CircularLinkedList{
    public:
    Node* head = NULL;
    Node* tail = NULL;

    void insertAtHead(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = tail = newNode;
            tail->next = head;

        }else{
            newNode->next = head;
            tail->next = head; 
            head = newNode;
        }
    }

    void insertAtTail(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display(){
        std::cout<<"\nLinked List"<<std::endl;
        Node* current = head->next;
        do{
            std::cout<<current->data<<" ";
        }while(current!=head);
    }
};

int main(){
    CircularLinkedList c;
    c.insertAtHead(100);
    c.insertAtHead(200);
    c.insertAtHead(300);
    c.insertAtTail(120);
    c.display();
    return 0;
}