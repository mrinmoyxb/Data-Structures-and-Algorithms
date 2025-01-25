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

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        return;
    }
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void displayUsingRec(Node* head){
    if(head==NULL){
        return;
    }
    std::cout<<head->data<<" ";
    displayUsingRec(head->next);
}

//! My approach: Use array to swap
Node* swap(Node* head, int k){
    std::vector<int> vec;
    Node* current = head;
    while(current!=NULL){
        vec.push_back(current->data);
        current = current->next;
    }
    int start = k-1;
    int end = vec.size()-k;
    std::swap(vec[start], vec[end]);

    Node* result = NULL;
    for(auto& item: vec){
        Node* newNode = new Node(item);
        if(result==NULL){
            result = newNode;
            current = result;
        }else{
            current->next = newNode;
            current = current->next;
        }
    }
    return result;
}


int main(){
    Node* node = new Node(7);
    Node* head = node;
    insertAtTail(head, 9);
    insertAtTail(head, 6);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 3);
    insertAtTail(head, 0);
    insertAtTail(head, 9);
    insertAtTail(head, 5);
    displayUsingRec(head);

    std::cout<<"\n";
    Node* r = swap(head, 5);
    displayUsingRec(r);
    return 0;
}