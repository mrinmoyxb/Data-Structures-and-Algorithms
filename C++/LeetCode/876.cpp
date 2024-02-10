#include <iostream>
#include <cmath>
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
    Node* temp = head;
    cout<<"Linked list: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void findTheMid(Node* &head){
    Node* temp = head;
    int length = 0;
    double position;
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    
    if(length%2==0){
        position = (length/2)+1;
    }
    else{
        position = (length/2)+1;
    }
    cout<<"\nLength of linked list: "<<length<<endl;
    cout<<"Mid position: "<<position<<endl;
    
}

int main(){
    Node* node1 = new Node(5);
    Node* head = node1;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head);
    findTheMid(head);
    return 0;
}