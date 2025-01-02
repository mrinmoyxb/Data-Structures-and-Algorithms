#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    cout<<"Current: "<<current->data<<endl;
    if(position==1){
        newNode->next = current;
        current->prev = newNode;
        head = newNode;
    }
    else{
        int count = 1;
        while(count<position-1){
            current = current->next;
            count++;
        }
        newNode->next = current->next;
        current->next->prev = newNode;
        newNode->prev = current;
        current->next = newNode;
    }
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
    Node* node = new Node(100);
    insertAtHead(node, 200);
    insertAtHead(node, 400);
    insertAtTail(node, 4000);
    insertAtMid(node, 99, 1);
    display(node);
    return 0;
}