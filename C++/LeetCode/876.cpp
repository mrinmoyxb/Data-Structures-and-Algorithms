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

void findTheMidValue(Node* &head){
    Node* temp = head;
    Node* currentNode = head;
    int length = 0;
    int position;
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }

    //* finding the mid value: 
    if(length%2==0){
        position = int((length/2)+1);
    }
    else{
        position = int((length/2)+1);
    }
    cout<<"\nLength of linked list: "<<length<<endl;
    cout<<"Mid position: "<<position<<endl;

    //* Displaying the mid value: 
    int count = 1;
    while(count<=position-1){
        currentNode = currentNode->next;
        count++;
    }
    cout<<"Mid value: "<<currentNode->data<<" "<<endl;
}

int main(){
    Node* node1 = new Node(15);
    Node* head = node1;
    insertAtHead(head, 24);
    insertAtHead(head, 43);
    insertAtHead(head, 52);
    insertAtHead(head, 16);
    insertAtHead(head, 20);
    display(head);
    findTheMidValue(head);
    return 0;
}