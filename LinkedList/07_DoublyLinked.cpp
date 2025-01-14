#include <iostream>
using std::cout;

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

//! Insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//! Insert at tail
void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current!=NULL){
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

//! Insert at mid
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
    newNode->prev = current;
}

//! Display 
void display(Node* head){
    std::cout<<"Linked List: "<<"\n";
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<"\n";
        current = current->next;
    }
}

//! Display using recursion
void displayUsingRecursion(Node* head){
    if(head==NULL){
        return;
    }

    std::cout<<head->data<<" ";
    displayUsingRecursion(head->next);
}

int main(){
    Node* node = new Node(100);
    Node* head = node;
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtHead(head, 500);
    insertAtMid(head, 1000, 3);

    displayUsingRecursion(head);

    
    return 0;
}