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

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count < position - 1){
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

void display(Node* &head){
    Node* current = head;
    cout<<"Linked list: "<<endl;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){

    Node* node = new Node(100);
    Node* head = node;
    insertAtHead(head, 1000);
    insertAtHead(head, 2000);
    insertAtTail(head, 900);
    display(head);
    return 0;
}