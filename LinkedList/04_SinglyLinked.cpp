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

    cout<<"\n\nElements and their duplicates: "<<endl;
    for(i = duplicates.begin(); i!=duplicates.end(); i++){
        cout<<i->first<<" : "<<i->second<<endl;
    }

    for(i = duplicates.begin(); i!=duplicates.end(); i++){
        if(i->second > max){
            max = i->second;
            value = i->first;
        }
    }

    cout<<"\nElement with most duplicates: "<<value<<endl;
}

//! Findig and removing duplicates
void removingDuplicates(Node* &head){
    map<int, int> duplicates;
    map<int, int>::iterator i;

    Node* current = head;
    while(current!=NULL){
        duplicates[current->data] = duplicates[current->data] + 1;
        current = current->next;
    }

    cout<<"\nDuplicate elements in the linked list: "<<endl;
    for(i = duplicates.begin(); i!=duplicates.end(); i++){
        cout<<i->first<<" : "<<i->second<<endl;
    }

    int max = 0;
    int element = 0;

    for(i = duplicates.begin(); i!=duplicates.end(); i++){
        if(i->second > max){
            max = i->second;
            element = i->first;
        }
    }

    cout<<"Element with most duplicates: "<<element<<endl;

    if(head->data==element){
        Node* del = head;
        head = head->next;
        delete del;
    }
    Node* prev = NULL;
    current = head;
    while(current!=NULL){
        if(current->data == element){
            Node* del = current;
            prev->next = prev->next->next;
            current = prev->next;
            delete del;
        }else{
            prev = current;
            current = current->next;
        }
    }
}

//! Removing a value from list
void check(Node* &head, int element){
    if(head->data==element){
        Node* del = head;
        head = head->next;
        delete del;
    }
    Node* prev = NULL;
    Node* current = head;
    while(current!=NULL){
        if(current->data == element){
            Node* del = current;
            prev->next = prev->next->next;
            current = prev->next;
            delete del;
        }else{
            prev = current;
            current = current->next;
        }
    }
}

int main(){
    map<int, int> duplicates;
    map<int, int>::iterator i;

    Node* node = new Node(300);
    Node* head = node;
    insertAtHead(head, 300);
    insertAtHead(head, 300);
    insertAtHead(head, 900);
    insertAtHead(head, 300);

    cout<<"Linked list: "<<endl;
    display(head);
    
    // checkingDuplicates(head, duplicates);

    // check(head, 300);
    // cout<<"\nLinked list: "<<endl;
    // display(head);
    
    removingDuplicates(head);
    cout<<"\nLinked list: "<<endl;
    display(head);

    return 0;
}