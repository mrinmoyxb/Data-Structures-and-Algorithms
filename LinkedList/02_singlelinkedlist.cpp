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

void insertAtPosition(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    int count = 1;
    Node* current  = head;
    while(count<position-1){
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void display(Node* head){
    Node* current =  head;
    cout<<"Linked List: "<<endl;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int lengthOfLinkedList(Node* head){
    Node* current = head;
    int count = 0;
    while(current!=NULL){
        count += 1;
        current = current->next;
    }
    return count;
}

void findMidElement(Node* head){
    int mid = (lengthOfLinkedList(head)/2)+1;
    Node* current = head;
    int count = 1;
    while(count<mid){
        current = current->next;
        count++;
    }
    cout<<"\nMid element: "<<current->data<<endl;
}

Node* reverseALinkedList(Node* head){
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



int main(){
    Node* node1 = new Node(100);
    Node* head = node1;
    insertAtHead(head, 200);
    insertAtHead(head, 120);
    insertAtTail(head, 900);
    insertAtTail(head, 1000);
    insertAtPosition(head, 1200, 2);
    display(head);
    findMidElement(head);

    cout<<"\nReverse Linked List: "<<endl;
    Node* rev = reverseALinkedList(head);
    display(rev);
    return 0;
}