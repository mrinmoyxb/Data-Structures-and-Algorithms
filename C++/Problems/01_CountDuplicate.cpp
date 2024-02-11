//! Count the number of times a given int occurs in a Linked List
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

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void countValue(Node* &head, int value){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        if(temp->data==value){
            count++;
        }
        temp = temp->next;
    }
    cout<<"\nTotal number of times "<<value<<" occured: "<<count<<endl;
}

void display(Node* &head){
    Node* temp = head;
    cout<<"Linked List: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* node1 = new Node(40);
    Node* head = node1;
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    display(head);
    
    countValue(head, 40);
    return 0;
}