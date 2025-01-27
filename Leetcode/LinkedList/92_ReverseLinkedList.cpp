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

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

//! Approach 1:
Node* reverse1(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;

    Node* start = head;
    Node* end = NULL;
    while(current!=NULL){
        end = current;
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    std::swap(start->data, end->data);
    return prev;
}

//! Approach 2:
Node* reverse2(Node* head, int left, int right){
    if(head->next==NULL){
        return head;
    }
    Node* current = head;
    Node* start = nullptr;
    Node* end = nullptr;
    int count = 1;
    while(current!=NULL){
        if(count==left){
            start = current;
            current = current->next;
            count+=1;
        }

        if(count==right){
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

void display(Node* head){
    if(head==NULL){
        return;
    }

    std::cout<<head->data<<" ";
    display(head->next);
}

int main(){
    Node* node = new Node(3);
    Node* head = node;
    insertAtTail(head, 5);
    // insertAtTail(head, 3);
    // insertAtTail(head, 4);
    // insertAtTail(head, 5);

    std::cout<<"\nLinked List: "<<"\n";
    display(head);

    std::cout<<"\nReverse Linked List: "<<"\n";
    Node* rev = reverse2(head, 1, 1);
    display(rev);

    return 0;
}

