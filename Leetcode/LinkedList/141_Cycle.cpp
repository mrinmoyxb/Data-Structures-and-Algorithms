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

void insertAtTail(Node*& tail, int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail = newNode;
        tail->next = tail;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void display(Node* tail){
    Node* head = tail->next;
    Node* current = tail;
    do{
        std::cout<<head->data<<" ";
        head = head->next;
    }while(current->next!=head);
}

int main(){
    Node* tail = new Node(100);
    tail->next = tail;
    insertAtTail(tail, 200);
    insertAtTail(tail, 300);

    std::cout<<"\nCycle linked list: "<<"\n";
    display(tail);
    return 0;
}