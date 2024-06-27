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

    ~Node(){}
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* &head){
    cout<<"\nLinked List is: "<<endl;
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int lengthOfTheList(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void printMid(Node* &head){
    Node* temp = head;
    int mid = (lengthOfTheList(head)/2)+1;
    int count = 1;
    while(count<mid){
        temp=temp->next;
        count++;
    }
    cout<<"\nData: "<<temp->data<<endl;
}


void test0(Node* &head){
    int count = 1;
    Node* temp = head;
    while(temp!=NULL){
        cout<<"\nBefore: "<<temp->data<<endl;
        cout<<"Before: "<<count<<endl;
        count++;
        temp = temp->next;
        cout<<"After: "<<temp->data<<endl;
        cout<<"After: "<<count<<endl;
    }
}

int main(){
    Node* head = new Node(100);
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtTail(head, 1000);
    display(head);
    
    cout<<endl;
    test0(head);
    return 0;
}