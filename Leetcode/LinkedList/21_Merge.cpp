//? Merge two sorted linked list
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

void display(Node* head){
    std::cout<<"\nLinked List: "<<"\n";
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Merge Sorted Array
Node* mergeSortedArray(Node* head1, Node* head2){
    Node* current1 = head1;
    Node* current2 = head2;
    Node* newList = NULL;
    Node* current = newList;
    while(current1!=NULL && current2!=NULL){
        if(newList==NULL){
            if(current1->data < current2->data){
                Node* newNode = new Node(current1->data);
                newList = newNode;;
                current = newList;
                current1 = current1->next;
            }else{
                Node* newNode = new Node(current2->data);
                newList = newNode;
                current = newList;
                current2 = current2->next;
            }
        }else{
            if(current1->data < current2->data){
                Node* newNode = new Node(current1->data);
                current->next = newNode;
                current = newNode;
                current1 = current1->next;
            }else{
                Node* newNode = new Node(current2->data);
                current->next = newNode;
                current = newNode;
                current2 = current2->next;
            }
        }
    }

    while(current1!=NULL){
        if(newList==NULL){
            Node* newNode = new Node(current1->data);
            newList = newNode;
            current = newNode;
            current1 = current1->next;
        }else{
            Node* newNode = new Node(current1->data);
            current->next = newNode;
            current = newNode;
            current1 = current1->next;
        }
    }

    while(current2!=NULL){
        if(newList==NULL){
            Node* newNode = new Node(current2->data);
            newList = newNode;
            current = newNode;
            current2 = current2->next;
        }else{
            Node* newNode = new Node(current2->data);
            current->next = newNode;
            current = newNode;
            current2 = current2->next;
        }
    }

    return newList;
}

int main(){
    Node* node1 = new Node(100);
    Node* head1 = node1;
    insertAtTail(head1, 200);
    insertAtTail(head1, 250);
    insertAtTail(head1, 300);
    insertAtTail(head1, 500);
    display(head1);

    Node* node2 = new Node(110);
    Node* head2 = node2;
    insertAtTail(head2, 220);
    insertAtTail(head2, 300);
    insertAtTail(head2, 420);
    insertAtTail(head2, 490);
    insertAtTail(head2, 600);
    display(head2);

    Node* final = mergeSortedArray(head1, head2);
    display(final);

    return 0;
}