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

//! Insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//! Traverse a linked list
void display(Node* head){
    Node* current = head;
    std::cout<<"\nLinked List: "<<std::endl;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Traverse using recursion
void displayRecursion(Node* head){
    if(head==NULL){
        return;
    }

    std::cout<<head->data<<" ";
    displayRecursion(head->next);
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* first = head;
    while(first!=NULL && first->next!=NULL){
        first = first->next->next;
        slow = slow->next;
    }
    return slow;
}

//! Binary search
bool binarySearch(Node* head, int key){
    if(head==NULL){
        return false;
    }

    Node* mid = findMid(head);
    if(mid->data == key){
        return true;
    }

    if(key>mid->data){
        return binarySearch(mid->next, key);
    }else{
        Node* start = head;
        Node* temp = head;
        while(temp->next!=mid){
            temp = temp->next;
        }
        temp->next = NULL;
        return binarySearch(start, key);
    }

}

int main(){
    Node* node = new Node(500);
    Node* head = node;
    insertAtHead(head, 400);
    insertAtHead(head, 300);
    insertAtHead(head, 200);
    insertAtHead(head, 100);

    std::cout<<"\nLinked List: "<<std::endl;
    displayRecursion(head);

    std::cout<<"\nBinary Search: "<<binarySearch(head, 500)<<std::endl;
    return 0;
}