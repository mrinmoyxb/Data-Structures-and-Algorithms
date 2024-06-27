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

int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

//* Approach 1: ->
void midDelete1(Node* &head){
    Node* temp = head;
    Node* current = head;
    Node* prev = NULL;
    int length = getLength(head);
    if(length==1){
        delete current;
        display(temp);
    }
    else{
        int mid = (length/2)+1;
        int count = 1;
        while(count<mid){
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;

        display(temp);
    }
}

//* Approach 2: ->
void midDelete2(Node* &head){
    Node* temp = head;
    Node* current = head;
    int count = 1;

    int length = getLength(head);
    int mid = (length/2)+1;
    while(count<mid-1){
        current = current->next;
        count++;
    }
    Node* midNode = current->next;
    current->next = current->next->next;
    midNode->next = NULL;
    delete midNode;
    display(head);
}

int main(){
    Node* head = new Node(1);
    insertAtHead(head, 2);
    display(head);
    cout<<endl;
    //midDelete1(head);
    midDelete2(head);
    return 0;
}

