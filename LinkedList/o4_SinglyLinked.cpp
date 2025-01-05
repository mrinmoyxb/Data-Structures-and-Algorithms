#include <iostream>
#include <map>
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

//! Insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//! Display linked list
void display(Node* head){
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

//! Checking duplicates
void checkingDuplicates(Node* &head, map<int, int> &duplicates){
    map<int, int>::iterator i;
    Node* current = head;
    int max = 0;
    int value = 0;
    while(current!=NULL){
        duplicates[current->data] = duplicates[current->data] + 1;
        current = current->next;
    }

    
    for(i = duplicates.begin(); i!=duplicates.end(); i++){
        if(i->second > max){
            max = i->second;
            value = i->first;
        }
    }

    cout<<"\nElement with most duplicates: "<<value<<endl;

    
}

int main(){
    map<int, int> duplicates;
    map<int, int>::iterator i;

    Node* node = new Node(100);
    Node* head = node;
    insertAtHead(head, 300);
    insertAtHead(head, 300);
    insertAtHead(head, 300);
    insertAtHead(head, 100);

    cout<<"Linked list: "<<endl;
    display(head);

    checkingDuplicates(head, duplicates);

    cout<<"\nElements and their duplicates: "<<endl;
    for(i = duplicates.begin(); i!=duplicates.end(); i++){
        cout<<i->first<<" : "<<i->second<<endl;
    }
    

    return 0;
}