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
    cout<<"\nMid Value in the linked list: "<<temp->data<<endl;
}

int main(){
    Node* head = new Node(100);
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtHead(head, 10000);
    display(head);
    cout<<endl;
    printMid(head);
    return 0;
}