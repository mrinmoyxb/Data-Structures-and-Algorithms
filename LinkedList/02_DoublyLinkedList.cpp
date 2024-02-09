#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void displayLinkedList(Node* &head){
    cout<<"Linked list is: "<<endl;
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    displayLinkedList(head);
    return 0;
}