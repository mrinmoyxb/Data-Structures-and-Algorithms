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

//! Insert at tail
void insertAtTail(Node*& tail, int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail = newNode;
        tail->next = tail;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

//! Insert at head
void insertAtHead(Node*& tail, int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail = newNode;
        tail->next = tail;
    }
    Node* head = tail->next;
    newNode->next = head;
    tail->next = newNode;
}

//! Display
void display(Node* tail){
    Node* head = tail->next;
    Node* current = tail;
    std::cout<<"Circular linked list: "<<"\n";
    do{
        std::cout<<head->data<<" ";
        head = head->next;
    }while(current->next!=head);
}

//! Length of linked list
int lengthOfLinkedList(Node* tail){
    int count = 0;
    Node* head = tail->next;
    Node* current = tail;
    do{
        count+=1;
        head = head->next;
    }while(current->next!=head);

    return count;
}

bool isListCircular(Node* tail){
    bool result = true;
    Node* head = tail->next;
    Node* current = tail;
    do{
        head = head->next;
    }while(current->next!=head);
}

int main(){
    Node* tail = NULL;
    insertAtTail(tail, 200);
    insertAtTail(tail, 300);
    insertAtHead(tail, 1000);

    display(tail);

    int length = lengthOfLinkedList(tail);
    std::cout<<"\nLength of linked list: "<<length<<"\n";
    return 0;
}