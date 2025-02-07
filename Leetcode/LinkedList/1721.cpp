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

//! Approach1: Use array to swap
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

int lengthOfLinkedList(Node* head){
    Node* current = head;
    int count = 0;
    while(current!=NULL){
        count+=1;
        current = current->next;
    }
    return count;
}

//! Approach2:
Node* swap1(Node* head, int k){
    Node* current = head;
    Node* start = NULL;
    Node* end = NULL;

    int count = 1;
    int length = lengthOfLinkedList(head);

    while(current!=NULL){
        if(count==k){
            start = current;
            current = current->next;
            count+=1;
        }

        if(count==(length-k)+1){
            end = current;
            current = current->next;
            count+=1;
        }
        current = current->next;
        count+=1;
    }

    std::swap(start->data, end->data);
    return head;
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
    Node* r = swap1(head, 5);
    displayUsingRec(r);
    return 0;
}