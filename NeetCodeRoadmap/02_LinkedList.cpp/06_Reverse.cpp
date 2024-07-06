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

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void display(Node* &head){
    cout<<"\nLinked List: "<<endl;
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

Node* reverse(Node* &head){
    Node* current = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    return prev;
}

Node* reverseUsingRecursion(Node* &head, int k){

    if( head == NULL){
        return NULL;
    }

    Node* temp = head;
    Node* x = head;
    int c = 0;
    while(temp!=NULL && c<k){
        c++;
        temp = temp->next;
    }

    if(c != k){
        return x;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;
    int count = 0;

    while(current!=NULL && count<k){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
        count++;
    }

    if(forward!=NULL){
        head->next = reverseUsingRecursion(forward, 2);
    }

    return prev;
}

void countNoOfGroups(Node* &head){
    Node* temp = head;
    int k = 3;
    int count = 0;
    int group = 0;
    int i = 1;

    while(temp!=NULL){
        count++;
        if(count==k*i){
            group++;
            i++;
        }
        temp = temp->next;
    }

    cout<<"\nCount: "<<count<<endl;
    cout<<"\nGroup: "<<group<<endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);

    display(head);

    countNoOfGroups(head);

    // // Node* rev = reverse(head);
    // // display(rev);
    
    cout<<endl;
    Node* r = reverseUsingRecursion(head, 3);
    display(r);
    return 0;
}