#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
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
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
        count+=1;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void display(Node* head){
    std::cout<<"Linked List: "<<std::endl;
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* node1 = new Node(100);
    Node* head = node1;
    insertAtHead(head, 120);
    insertAtHead(head, 130);
    insertAtHead(head, 140);
    insertAtTail(head, 500);
    insertAtMid(head, 120000, 2);
    display(head);
    return 0;
}