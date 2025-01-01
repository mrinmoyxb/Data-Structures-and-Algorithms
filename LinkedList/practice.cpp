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

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int lengthOfList(Node* &head){
    int count = 0;
    Node* current = head;
    while(current!=NULL){
        count+=1;
        current = current->next;
    }
    return count;
}

void findMidElement(Node* &head){
    Node* current = head;
    int length = lengthOfList(head);
    int mid = (length/2)+1;
    int count = 1;
    while(count<mid){
        current = current->next;
        count+=1;
    }
    cout<<"Mid element: "<<current->data<<endl;
}

void display(Node* &head){
    Node* current = head;
    cout<<"\nLinked List: "<<endl;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* node = new Node(100);
    Node* head = node;
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtTail(head, 1000);
    insertAtMid(head, 900, 2);
    display(head);
    cout<<"\nLength of linked list: "<<lengthOfList(head)<<endl;
    findMidElement(head);
    return 0;
}