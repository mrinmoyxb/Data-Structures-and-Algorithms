#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
        count+=1;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void printEvenNumbers(Node* head){
    std::cout<<"\nEven Numbers: "<<std::endl;
    Node* current = head;
    while(current!=NULL){
        if(current->data%2==0){
            std::cout<<current->data<<" ";
            current = current->next;
        }else{
            current = current->next;
        }
    }
}

void printOddNumbers(Node* head){
    std::cout<<"\nOdd Numbers: "<<std::endl;
    Node* current = head;
    while(current!=NULL){
        if(current->data%2!=0){
            std::cout<<current->data<<" ";
            current = current->next;
        }else{
            current = current->next;
        }
    }
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

void findMidElement(Node* head){
    Node* current = head;
    int length = lengthOfLinkedList(head);
    int mid = (length/2)+1;
    int count = 1;
    while(count<mid){
        current = current->next;
        count+=1;
    }
    std::cout<<"Mid element: "<<current->data<<std::endl;
}

void display(Node* head){
    std::cout<<"Linked List: "<<std::endl;
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* node1 = new Node(100);
    Node* head = node1;
    insertAtHead(head, 120);
    insertAtHead(head, 223);
    insertAtHead(head, 140);
    insertAtTail(head, 569);
    insertAtMid(head, 120000, 2);
    insertAtHead(head, 290);
    display(head);
    // printEvenNumbers(head);
    // printOddNumbers(head);
    std::cout<<"\nLength of linked list: "<<lengthOfLinkedList(head)<<std::endl;
    findMidElement(head);
    return 0;
}