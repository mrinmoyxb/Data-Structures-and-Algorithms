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
    
}


int main(){
    return 0;
}