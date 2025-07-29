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

class SinglyLinkedList{
    Node* head = NULL;
    Node* tail = NULL;

    void insertAtHead(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head=tail=NULL;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int data, int position){
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

    void display(){
        
    }

    ~SinglyLinkedList(){
        Node* current = head;
        Node* forward = NULL;
        while(current!=NULL){
            forward = current->next;
            Node* temp = current;
            delete temp;
            current = forward;
        }
        std::cout<<"deleted linked list"<<std::endl;
    }
};