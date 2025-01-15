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

void insertAtHead(Node* &tail, int element, int data){
    if(tail==NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }else{
        Node* current = tail;
        Node* newNode = new Node(data);
        while(current->data != element){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void display(Node* tail){
    Node* current = tail;
    while(current->next!=tail){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* tail = NULL;
    insertAtHead(tail, 100, 100);
    insertAtHead(tail, 100, 200);
    insertAtHead(tail, 200, 300);
    insertAtHead(tail, 300, 400);
    display(tail);
    return 0;
}