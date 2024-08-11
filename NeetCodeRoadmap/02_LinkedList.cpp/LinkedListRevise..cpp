#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* nextNodeAddress;

    Node(int data){
        this->data = data;
        this->nextNodeAddress = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->nextNodeAddress = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->nextNodeAddress!=NULL){
        temp = temp->nextNodeAddress;
    }
    temp->nextNodeAddress = newNode;
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        count++;
        temp = temp->nextNodeAddress;
    }
    newNode->nextNodeAddress = temp->nextNodeAddress;
    temp->nextNodeAddress = newNode;
}

void display(Node* &head){
    Node* temp = head;
    cout<<"\nLinked List: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->nextNodeAddress;
    }
}

void demo(Node* &head, int x){
    int count = 1;
    Node* current = head;
    vector<int> vec;
    while(current->data!=x){
        current = current->nextNodeAddress;
        count++;
    }
    Node* prev = current;
    current = current->nextNodeAddress;
    while(current!=NULL){
        if(current->data < x){
            vec.push_back(current->data);
            Node* temp = current;
            prev->nextNodeAddress = temp->nextNodeAddress;
            delete temp;
        }
        prev = current;
        current = current->nextNodeAddress;
    }

    // cout<<"\nDone"<<endl;
    // for(int i:vec){
    //     cout<<i<<" ";
    // }
    
}

int main(){
    Node* newNode = new Node(100);
    Node* head = newNode;

    insertAtHead(head, 200);
    insertAtHead(head, 400);
    insertAtTail(head, 500);
    insertAtHead(head, 200);
    insertAtTail(head, 300);
    insertAtTail(head, 900);
    insertAtTail(head, 10);
    display(head);
    

    demo(head, 400);
    display(head);

    return 0;
}