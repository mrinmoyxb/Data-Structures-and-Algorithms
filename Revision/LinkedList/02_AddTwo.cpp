#include <iostream>
#include <vector>
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

//* insert at tail
void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
    }
    else{
        Node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    
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

//* reverse a linked list
Node* reverseLinkedList(Node* &head){
    Node* current = head;
    Node* prev = NULL;
    Node* forward = head;
    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

//* Add Two Linked List
Node* addTwoLinkedList(Node* &head1, Node* &head2){
    Node* first = reverseLinkedList(head1);
    Node* second = reverseLinkedList(head2);
    int carry = 0;
    int sum = 0;
    Node* resultHead = NULL;

    while(first!=NULL && second!=NULL){
        sum = carry + first->data + second->data;
        int digit = sum%10;
        insertAtTail(resultHead, digit);
        carry = sum/10;
        first = first->next;
        second = second->next;
    }

    while(first!=NULL){
        sum = carry + first->data;
        int digit = sum%10;
        insertAtTail(resultHead, digit);
        carry = sum/10;
        first = first->next;
    }

    while(second!=NULL){
        sum = carry + second->data;
        int digit = sum%10;
        insertAtTail(resultHead, digit);
        carry = sum/10;
        second = second->next;
    }

    while(carry!=0){
        sum = carry;
        int digit = sum%10;
        insertAtTail(resultHead, digit);
        carry = sum/10;
    }

    resultHead = reverseLinkedList(resultHead);
    return resultHead;
}

int main(){
    Node* head1 = new Node(3);
    insertAtHead(head1, 2);
    insertAtHead(head1, 1);
    display(head1);

    Node* head2 = new Node(2);
    insertAtHead(head2, 1);
    display(head2);

    Node* r = addTwoLinkedList(head1, head2);
    display(r);

    return 0;
}