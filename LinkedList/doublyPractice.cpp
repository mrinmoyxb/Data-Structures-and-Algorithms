#include <iostream>

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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
    newNode->next->prev = newNode;
}

//! Display of linked list using recursion
void displayUsingRecursion(Node* head){
    if(head==NULL){
        return;
    }

    std::cout<<head->data<<" ";
    displayUsingRecursion(head->next);
}

//! Length of linked list
int lengthOfLinkedList(Node* head){
    if(head==NULL){
        return 0;
    }

    return 1+lengthOfLinkedList(head->next);
}

int main(){
    Node* node = new Node(500);
    Node* head = node;
    insertAtHead(head, 400);
    insertAtHead(head, 300);
    insertAtHead(head, 200);
    insertAtHead(head, 100);
    insertAtMid(head, 250, 3);

    std::cout<<"\nLinked List: "<<"\n";
    displayUsingRecursion(head);

    std::cout<<"\nLength: "<<lengthOfLinkedList(head);

    return 0;
}