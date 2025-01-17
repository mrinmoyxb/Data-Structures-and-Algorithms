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

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void display(Node* head){
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

void analysis(Node* &head){
    Node* current = head;
    while(current!=NULL){
        std::cout<<"current->data: "<<current->data<<"\n";
        std::cout<<"&current->data: "<<&current->data<<"\n";
        std::cout<<"current: "<<current<<"\n";
        std::cout<<"&current: "<<&current<<"\n";
        std::cout<<"current->next: "<<current->next<<"\n";
        std::cout<<"\n";

        current = current->next;
    }
}

int main(){
    Node* node = new Node(100);
    Node* head = node;
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtHead(head, 500);
    display(head);
    
    std::cout<<"\n";
    analysis(head);
     
    return 0;
}