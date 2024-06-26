#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* nextNodeAddress;

    Node(int data){
        this->data = data;
        this->nextNodeAddress = NULL;
    }

    ~Node(){

    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->nextNodeAddress = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->nextNodeAddress!=NULL){
        temp = temp->nextNodeAddress;
    }
    temp->nextNodeAddress = newNode;
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        count++;
        temp = temp->nextNodeAddress;
    }
    newNode->nextNodeAddress = temp->nextNodeAddress;
    temp->nextNodeAddress = newNode;
}

void display(Node* &head){
    Node* temp = head;
    cout<<"\nLinked List: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->nextNodeAddress;
    }
}

int main(){
    Node* newNode = new Node(100);
    Node* head = newNode;

    insertAtHead(head, 200);
    insertAtHead(head, 400);
    insertAtHead(head, 500);
    insertAtHead(head, 600);
    insertAtTail(head, 1000);
    display(head);

    insertAtMid(head, 69, 2);
    display(head);

    return 0;
}