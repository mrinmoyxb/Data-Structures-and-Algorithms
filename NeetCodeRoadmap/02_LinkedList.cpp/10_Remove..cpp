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
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    if(current->next == NULL){
        current->next = newNode;
    }
    else{
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(Node* &head){
    cout<<"\nLinked List: "<<endl;
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current= current->next;
    }
}

Node* removeDuplicates(Node* &head){
    Node* current = head;
    Node* prev = NULL;

    while(current!=NULL && current->next!=NULL){
        if(current->data == current->next->data){
            prev = current;
            Node* temp = current->next;
            current->next = temp->next;
            temp->next = NULL;
            delete temp;
            
            if(prev->data == current->data){
                Node* temp = current->next;
                current->next = temp->next;
                temp->next = NULL;
                delete temp;
            }

            current = current->next;
        }
        else{
            current = current->next;
        }
    }

    return head;
}

int main(){
    Node* newNode = new Node(1);
    Node* head = newNode;
    insertAtTail(head,1);
    insertAtTail(head,1);
    display(head);

    Node* r = removeDuplicates(head);
    display(r);

    return 0;
}

