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

void display(Node* &head){
    cout<<"\nLinked List"<<endl;
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int numberOfNodes(Node* &head){
    int count = 0;
    Node* current = head;
    while(current!=NULL){
        count++;
        current = current->next;
    }

    return count;
}

Node* findMidNode(Node* &head){
    Node* current = head;
    int midNode = (numberOfNodes(head)/2)+1;
    int count = 1;
    while(count<midNode){
        current = current->next;
        count++;
    }
    return current;
}

int main(){

    Node* nodeOne = new Node(10);
    Node* head = nodeOne;
    insertAtHead(head, 100);
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtTail(head, 1000);
    insertAtMid(head, 69, 2);

    display(head);

    cout<<"\nLength of linked list: "<<numberOfNodes(head)<<endl;
    
    Node* midNode = findMidNode(head);
    cout<<"\nMid node: "<<midNode->data<<endl;

    return 0;
}