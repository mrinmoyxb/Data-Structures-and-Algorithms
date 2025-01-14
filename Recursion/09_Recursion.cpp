#include <iostream>

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

//! Traverse linked list without recursion
void displayWithoutRecursion(Node* head){
    Node* current = head;
    std::cout<<"\nLinked List: "<<std::endl;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Traverse linked list with recursion
void displayWithRecursion(Node* head){
    if(head==NULL){
        return;
    }

    std::cout<<head->data<<" ";
    displayWithRecursion(head->next);
}

//! Linear search using recursion
bool linearSearch(Node* head, int key){
    if(head==NULL){
        return false;
    }

    if(head->data == key){
        return true;
    }else{
        return linearSearch(head->next, key);
    }
}

int main(){
    Node* node = new Node(100);
    Node* head = node;
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtHead(head, 500);
    displayWithoutRecursion(head);

    std::cout<<std::endl;
    std::cout<<"\nDisplay with recursion"<<std::endl;
    displayWithRecursion(head);

    std::cout<<std::endl;
    std::cout<<"\nLinear search: "<<linearSearch(head, 200)<<std::endl;
    return 0;
}