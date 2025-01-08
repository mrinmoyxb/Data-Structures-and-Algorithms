#include <iostream>
#include <vector>

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

//! Display 
void display(Node* head){
    Node* current = head;
    std::cout<<"Linked List: "<<std::endl;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Linear search in linked list
void linearSearch(Node* &head, int key){
    Node* current = head;
    while(current!=NULL){
        if(current->data == key){
            std::cout<<key<<" found in the linked list"<<std::endl;
            break;
        }
        else{
            current = current->next;
        }
    }
    if(current==NULL){
        std::cout<<"Not found in the linked list"<<std::endl;
    }
}

int main(){
    Node* node = new Node(100);
    Node* head = node;
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtHead(head, 1000);
    display(head);

    int key;
    std::cout<<"\nEnter the key you want to search: ";
    std::cin>>key;

    linearSearch(head, key);
}