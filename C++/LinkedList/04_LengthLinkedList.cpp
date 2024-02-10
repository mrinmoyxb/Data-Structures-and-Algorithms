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

int countLinkedList(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void display(Node* &head){
    Node* temp = head;
    cout<<"Linked List: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(100);
    Node* head = node1;
    insertAtTail(head, 200);
    insertAtTail(head, 300);
    insertAtTail(head, 400);
    insertAtTail(head, 400);
    insertAtTail(head, 500);
    display(head);

    int length = countLinkedList(head);
    cout<<"Length of linked list: "<<length<<endl;
    return 0;
}