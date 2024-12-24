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

//! Insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//! Insert at mid
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

//! Insert at tail
void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

//! Length of list
int lengthOfList(Node* &head){
    Node* current = head;
    int count = 0;
    while(current!=NULL){
        count ++;
        current = current->next;
    }
    return count;
}

//! Mid position
void midPosition(Node* &head){
    Node* current = head;
    int length = lengthOfList(head);
    int midPosition = (length/2)+1;
    int count = 1;
    while(count<midPosition){
        current = current->next;
        count++;
    }
    cout<<"Value at mid position: "<<current->data<<endl;
}

//! Reverse linked list
void reverseLinkedList(Node* &head){
    Node* current = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        current = prev;
        current->next = forward;
    }

}

//! Display of linked list
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
    insertAtTail(head, 2000);
    display(head);
    cout<<"Length: "<<lengthOfList(head)<<endl;
    midPosition(head);
    return 0;
}