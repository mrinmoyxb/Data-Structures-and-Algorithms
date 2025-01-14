#include <iostream>
#include <climits>

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

//! Find max element in linked list
int findMax(Node* head){
    Node* current = head;
    int max = 0;
    while(current!=NULL){
        if(current->data > max){
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

int max(int num1, int num2){
    return num1>num2 ? num1 : num2;
}

//! Find max element using recursion
int findMaxUsingRecursion(Node* head){
    if(head->next==NULL){
        return head->data;
    }

    return max(head->data, findMaxUsingRecursion(head->next));
}

int main(){
    Node* node = new Node(600);
    Node* head = node;
    insertAtHead(head, 533);
    insertAtHead(head, 400);
    insertAtHead(head, 999);
    insertAtHead(head, 233);
    insertAtHead(head, 100);
    displayWithoutRecursion(head);

    // std::cout<<std::endl;
    // std::cout<<"Max element: "<<findMax(head)<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Max: "<<findMaxUsingRecursion(head)<<std::endl;

    return 0;
}