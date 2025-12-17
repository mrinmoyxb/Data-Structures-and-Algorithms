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

int length(Node* head){
    Node* current = head;
    int count = 0;
    while(current!=NULL){
        count+=1;
        current = current->next;
    }
    return count;
}

Node* deleteMidNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    int mid = (length(head)/2)+1;
    int count = 1;
    Node* current = head;
    while(count<mid-1){
        current = current->next;
        count+=1;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    temp->next = NULL;
    delete temp;

    return head;
}

void insertAtTail(Node*& head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void display(Node* head){
    Node* current = head;
    std::cout<<"\nLinked List: "<<std::endl;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}


int main(){
    Node* head = new Node(100);
    insertAtTail(head, 200);
    insertAtTail(head, 300);
    insertAtTail(head, 400);
    insertAtTail(head, 500);

    display(head);

    Node* rev = deleteMidNode(head);
    display(rev);

    return 0;
}