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

void insertAtMid(Node* &head, int data, int position){
    Node* current = head;
    Node* newNode = new Node(data);
    int count = 1;
    while(count<position-1){
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

Node* reverseLinkedList(Node* &head){
    if(head==NULL){
        return head;
    }
    Node* current = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

void display(Node* head){
    Node* current = head;
    cout<<"Linked List: "<<endl;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* node1 = new Node(100);
    Node* head = node1;
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtTail(head, 1000);
    display(head);

    cout<<endl;
    insertAtMid(head, 1000, 3);
    display(head);

    cout<<endl;
    Node* rev = reverseLinkedList(head);
    display(rev);
    return 0;
}