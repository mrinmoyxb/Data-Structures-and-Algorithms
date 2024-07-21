#include <iostream>
using namespace std;

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

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int lengthOfLinkedList(Node* &head){
    Node* current = head;
    int count = 0;
    while(current!=NULL){
        count++;
        current = current->next;
    }
    
}

void findMidNode(){
}

int main(){
    return 0;
}