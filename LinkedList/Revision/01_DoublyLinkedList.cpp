#include <iostream>

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* doublyLinkedList = nullptr;
    Node* head = nullptr;
    Node* tail = nullptr;
    
    DoublyLinkedList(int data){
        Node* newNode = new Node(data);
        doublyLinkedList = newNode;
        head = newNode;
        tail = newNode;
    }

    void insertAtHead(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        doublyLinkedList = head;
    }

    void insertAtTail(int data){
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }

    void display(){
        Node* current = head;
        std::cout<<"\nDoubly Linked List: ";
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    void print(){
        std::cout<<"\nhead: "<<head->data<<"\n";
        std::cout<<"tail: "<<tail->data<<"\n";
        std::cout<<"doubly linked list: "<<doublyLinkedList->data<<"\n";
    }
};

int main(){
    DoublyLinkedList d = DoublyLinkedList(100);
    d.insertAtTail(200);
    d.insertAtTail(300);
    d.display();
    d.print();
    return 0;
}