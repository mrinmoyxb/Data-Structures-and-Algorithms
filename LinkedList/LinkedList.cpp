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
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void displayLinkedList(Node* &head){
    Node* temp = head;
    cout<<"Linked list is: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtHead(head, 100);
    insertAtHead(head, 20);
    insertAtTail(head, 900);
    insertAtHead(head, 100);
    insertAtMid(head, 1000, 2);
    displayLinkedList(head);
    return 0;
}