#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node*& head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(Node*& head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int lengthOfList(Node* head){
    Node* current = head;
    int count = 0;
    while(current!=NULL){
        count+=1;
        current = current->next;
    }
    return count;
}

void midNode(Node*& head){
    Node* current = head;
    int length = lengthOfList(head);
    int count = 1;
    int mid;
    if(length%2==0){
        mid = length/2;
    }else{
        mid = (length/2)+1;
    }

    while(count<mid){
        current = current->next;
        count+=1;
    }

    std::cout<<"mid: "<<current->data<<std::endl;

}

void display(Node* head){
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* head = new Node(100);
    insertAtHead(head, 200);
    insertAtTail(head, 1000);
    display(head);

    return 0;
}