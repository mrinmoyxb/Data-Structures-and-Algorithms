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

class SinglyLinkedList{
    public:
    Node* linkedList = nullptr;
    Node* head = nullptr;
    Node* tail = nullptr;

    SinglyLinkedList(int data){
        Node* newNode = new Node(data);
        linkedList = newNode;
        head = linkedList;
        tail = linkedList;
    }

    void insertAtHead(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data){
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtMid(int data, int position){
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

    Node* reverseLinkedList(){
        Node* prev = NULL;
        Node* current = head;
        Node* forward = NULL;
        while(current!=NULL){
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        head = prev;
        return prev;
    }

    void display(){
        std::cout<<"\nLinked List: "<<"\n";
        Node* current = head;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    void displayWithNode(Node* head){
        std::cout<<"\nLinked List: "<<"\n";
        Node* current = head;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }
};

int main(){
    SinglyLinkedList s = SinglyLinkedList(100);
    s.insertAtHead(200);
    s.insertAtTail(300);
    s.insertAtTail(400);
    s.insertAtTail(500);
    s.display();

    s.insertAtMid(1000, 2);
    s.display();

    Node* rev = s.reverseLinkedList();
    s.displayWithNode(rev);

    s.display();
    return 0;
}