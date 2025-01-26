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

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

Node* reverse1(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;

    Node* start = head;
    Node* end = NULL;
    while(current!=NULL){
        end = current;
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    std::swap(start->data, end->data);
    return prev;
}

void display(Node* head){
    if(head==NULL){
        return;
    }

    std::cout<<head->data<<" ";
    display(head->next);
}

int main(){
    Node* node = new Node(1);
    Node* head = node;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    std::cout<<"\nLinked List: "<<"\n";
    display(head);

    std::cout<<"\nReverse Linked List: "<<"\n";
    Node* rev = reverse1(head);
    display(rev);

    return 0;
}

