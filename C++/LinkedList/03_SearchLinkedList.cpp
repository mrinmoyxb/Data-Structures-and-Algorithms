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

int searchLinkedList(Node* &head, int value){
    Node* temp = head;
    int count = 1;
    while(temp!=NULL){
        if(temp->data==value){
            return count;
            break;
        }
        temp=temp->next;
        count++;
    }
    return -1;
}

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
        temp=temp->next;
    }
}


int main(){
    Node* node1 = new Node(100);
    Node* head = node1;

    insertAtHead(head, 250);
    insertAtHead(head, 320);
    insertAtHead(head, 500);
    insertAtHead(head, 3400);
    insertAtHead(head, 20);
    display(head);

    int value;
    cout<<"\nEnter the value you want to search: ";
    cin>>value;
    int position = searchLinkedList(head, value);
    if(position==-1){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Found!!, at position: "<<position<<endl;
    }
}