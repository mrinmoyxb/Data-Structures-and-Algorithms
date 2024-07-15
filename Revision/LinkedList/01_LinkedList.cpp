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

//* insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//* display
void display(Node* &head){
    cout<<"\nLinkedList: "<<endl;
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

//* merge two linked list
Node* merge(Node* &head1, Node* &head2){
    Node* sorted = NULL;
    Node* temp = NULL;
    Node* current1 = head1;
    Node* current2 = head2;

    if(sorted==NULL && current1!=NULL && current2!=NULL){
        if(current1->data < current2->data){
            sorted = new Node(current1->data);
            current1 = current1->next;
            temp = sorted;
        }
        else{
            sorted = new Node(current2->data);
            current2 = current2->next;
            temp = sorted;
        }
    }

    while(current1!=NULL && current2!=NULL){
        if(current1->data <= current2->data){
            Node* newNode = new Node(current1->data);
            temp->next = newNode;
            temp = newNode;
            current1 = current1->next;
        }
        else{
            Node* newNode = new Node(current2->data);
            temp->next = newNode;
            temp = newNode;
            current2 = current2->next;
        }
    }

    while(current1!=NULL){
        Node* newNode = new Node(current1->data);
        temp->next = newNode;
        temp = newNode;
        current1 = current1->next;
    }

    while(current2!=NULL){
        Node* newNode = new Node(current2->data);
        temp->next = newNode;
        temp = newNode;
        current2 = current2->next;
    }

    return sorted;
}

int main(){
    Node* node1 = new Node(40);
    Node* head1 = node1;
    insertAtHead(head1, 30);
    insertAtHead(head1, 15);
    insertAtHead(head1, 5);
    display(head1);

    Node* node2 = new Node(25);
    Node* head2 = node2;
    insertAtHead(head2, 20);
    insertAtHead(head2, 4);
    insertAtHead(head2, 1);
    display(head2);
  
    Node* mergeSortedArray = merge(head1, head2);
    display(mergeSortedArray);
    
    return 0;
}