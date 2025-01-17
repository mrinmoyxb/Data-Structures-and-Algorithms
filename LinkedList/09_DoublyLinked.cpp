#include <iostream>

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//! Insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

//! Insert at tail
void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
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

//! Display using recursion
void display(Node* head){
    if(head==NULL){
        return;
    }
    std::cout<<head->data<<" ";
    display(head->next);
}

//! Reverse traverse
void reverseTraverse(Node* head){
    Node* start = head;
    Node* end = head;
    while(end->next!=NULL){
        end = end->next;
    }
    
    std::cout<<"\nReverse Linked List"<<std::endl;
    while(end!=NULL){
        std::cout<<end->data<<" ";
        end = end->prev;
    }
}

int main(){
    Node* node = new Node(100);
    Node* head = node;
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtHead(head, 500);
    insertAtTail(head, 1000);
    insertAtMid(head, 999, 3);

    std::cout<<"\nLinked List: "<<std::endl;
    display(head);
    reverseTraverse(head);
    return 0;
}