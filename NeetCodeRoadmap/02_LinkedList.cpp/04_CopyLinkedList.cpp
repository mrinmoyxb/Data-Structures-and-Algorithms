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
    Node* temp = head;
    Node* newNode = new Node(data);
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* &head){
    Node* temp = head;
    cout<<"\nLinked list: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void copy(Node* &head){
    Node* copyListHead = NULL;
    Node* prev = NULL;
    Node* current = head;

    if(copyListHead == NULL && current!=NULL){
        copyListHead = new Node(current->data);
        prev = copyListHead;
        current = current->next;
    }

    while(current!=NULL){
        Node* newNode = new Node(current->data);
        prev->next = newNode;
        prev = newNode;
        current = current->next;
    }

    display(copyListHead);
}

int main(){

    Node* node1 = new Node(10);
    Node* head1 = node1;

    insertAtHead(head1, 8);
    insertAtHead(head1, 5);
    insertAtHead(head1, 2);
    insertAtHead(head1, 1);
    display(head1);

    copy(head1);
    
    return 0;
}