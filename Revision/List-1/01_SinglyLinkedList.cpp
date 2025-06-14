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

void insertAtHead(Node*& head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, int data){
    Node* current = head;
    Node* newNode = new Node(data);
    while(current!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insertAtMid(Node*& head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
    }
    current->next = newNode->next;
    newNode->next = current;
}

int main(){
    
    return 0;
}