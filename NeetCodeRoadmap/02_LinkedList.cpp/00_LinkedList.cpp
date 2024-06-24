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
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
    }
    newNode->next = temp->next->next;
    temp->next = newNode;
}

void display(Node* &head){
    cout<<"\nLinked List: "<<endl;
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* newNode = new Node(100);
    Node* head = newNode;
    insertAtHead(head, 200);
    insertAtHead(head, 500);
    insertAtHead(head, 700);
    insertAtHead(head, 800);
    insertAtTail(head, 10000);
    display(head);
    return 0;
}