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

void display(Node* head){
    std::cout<<"\nLinked List: "<<"\n";
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Delete element
Node* deleteElement(Node* head, int element){
    Node* current = head;
    Node* prev = NULL;

    if(head==NULL){
        return NULL;
    }

    while(current!=NULL){
        if(head->data==element){
            Node* delNode = current;
            head = head->next;
            current = head;
            delete delNode;
        }
        else{
            if(current->data == element){
                Node* delNode = current;
                prev->next = current->next;
                current = current->next;
                delete delNode;
            }else{
                prev = current;
                current = current->next;
            }

        }
    }
    return head;
}

int main(){
    Node* node1 = new Node(100);
    Node* head1 = node1;
    insertAtTail(head1, 100);
    insertAtTail(head1, 100);
    insertAtTail(head1, 200);
    insertAtTail(head1, 200);
    display(head1);

    Node* result = deleteElement(head1, 100);
    display(result);
    return 0;
}