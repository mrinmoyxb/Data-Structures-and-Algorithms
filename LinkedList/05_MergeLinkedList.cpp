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

//! Display linked list
void display(Node* head){
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

//! Merge sorted linked list
void mergeSorted(Node* &head1, Node* &head2){
    Node* current1 = head1;
    Node* current2 = head2;

    Node* newList = NULL;
    Node* index = NULL;

    while(current1!=NULL && current2!=NULL){
        if(current1->data < current2->data){
            if(newList == NULL){
                newList = new Node(current1->data);
                index = newList;
                current1 = current1->next;
            }else{
                Node* newNode = new Node(current1->data);
                index->next = newNode;
                index = index->next;
                current1 = current1->next;
            }
        }else{
            if(newList == NULL){
                newList = new Node(current2->data);
                index = newList;
                current2 = current2->next;
            }else{
                Node* newNode = new Node(current2->data);
                index->next = newNode;
                index = index->next;
                current2 = current2->next;
            }
        }
    }

    while(current1!=NULL){
        Node* newNode = new Node(current1->data);
        index->next = newNode;
        index = index->next;
        current1 = current1->next;
    }

    while(current2!=NULL){
        Node* newNode = new Node(current2->data);
        index->next = newNode;
        index = index->next;
        current2 = current2->next;
    }
    
    cout<<"\nSorted merged linked list: "<<endl;
    display(newList);
}

int main(){
    Node* node1 = new Node(300);
    Node* head1 = node1;
    insertAtHead(head1, 200);
    insertAtHead(head1, 100);

    Node* node2 = new Node(290);
    Node* head2 = node2;
    insertAtHead(head2, 220);
    insertAtHead(head2, 110);

    cout<<"\nLinked list 1: "<<endl;
    display(head1);
    cout<<"\nLinked list 2: "<<endl;
    display(head2);

    mergeSorted(head1, head2);
    return 0;
}