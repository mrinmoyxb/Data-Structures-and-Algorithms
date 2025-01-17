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

void insertAtHead(Node* &tail, int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail = newNode;
        tail->next = tail;
    }else{
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void insertAtLast(Node* &tail, int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail = newNode;
        tail->next = tail;
    }else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void display(Node* tail){
    Node* head = tail->next;
    Node* current = head;

    std::cout<<"\nCircular linked list: "<<"\n";
    do{
        std::cout<<current->data<<" ";
        current = current->next;
    }while(current!=head);
    std::cout<<"\n";
}

int main(){
    Node* tail = NULL;
    insertAtHead(tail, 200);
    insertAtHead(tail, 300);
    insertAtLast(tail, 400);
    insertAtLast(tail, 500);
    display(tail);
    return 0;
}