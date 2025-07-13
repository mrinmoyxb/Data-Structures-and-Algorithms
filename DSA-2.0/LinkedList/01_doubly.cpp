#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void display(Node* head){
    std::cout<<"\nDoubly Linked List"<<std::endl;
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* node1 = new Node(100);
    Node* head = node1;
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtTail(head, 500);
    display(head);
    return 0;
}