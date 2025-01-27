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

//! Insert at head
void insertAtHead(Node* &tail, int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail = newNode;
        tail->next = tail;
    }else{
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

//! Insert at tail
void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail = newNode;
        tail->next = tail;
    }else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

//! Delete head node
void deleteHead(Node* &tail){
    if(tail==NULL){
        return;
    }else{
        Node* deleteNode = tail->next;
        tail->next = tail->next->next;
        deleteNode = nullptr;
        delete deleteNode;
    }
}

//! Display
void display(Node* &tail){
    Node* head = tail->next;
    Node* current = current;
    do{
        std::cout<<current->data<<" ";
        current = current->next;
    }while(current->next!=head);
}

//! Length of linked list
int lengthOfLinked(Node* tail){
    Node* head = tail->next;
    Node* current = head;
    int count = 0;
    do{
        current = current->next;
        count+=1;
    }while(current!=head);

    return count;
}

void headTail(Node* tail){
    Node* head = tail->next;
    std::cout<<"\nHead: "<<head->data<<"\n";
    std::cout<<"Tail: "<<tail->data<<"\n";
}

int main(){
    Node* tail = NULL;
    insertAtHead(tail, 300);
    insertAtHead(tail, 400);
    insertAtHead(tail, 1000);
    display(tail);
    headTail(tail);
    std::cout<<"\nLength: "<<lengthOfLinked(tail);
    return 0;
}