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

Node* reverseLinkeList(Node* &head){
    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;
    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

Node* reverseUsingRecursion(Node* &head){
    Node* current = head;
    Node* forward = current->next;
    current->next = 
}

void display(Node* head){
    Node* current = head;
    cout<<"\nLinked list: "<<endl;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* head = new Node(100);
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    display(head);
    Node* root = reverseLinkeList(head);
    display(root);
    return 0;
}