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
    Node* head = NULL;
    Node* tail = NULL;

    void insertAtHead(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    int lengthOfLinkedList(){
        Node* current = head;
        int count = 0;
        while(current!=NULL){
            count+=1;
            current = current->next;
        }
        return count;
    }

    void insertAtPosition(int data, int position){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = tail = newNode;
            return;
        }

        if(position==1){
            newNode->next=head;
            head = newNode;
            return;
        }
        
        int length = lengthOfLinkedList();
        if(position>length){
            tail->next = newNode;
            tail = newNode;
        }else{
            int count = 1;
            Node* current = head;
            while(count<position-1){
                current = current->next;
                count+=1;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void display(){
        Node* current = head;
        std::cout<<"Linked List"<<std::endl;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    ~SinglyLinkedList(){
        Node* current = head;
        Node* forward = current->next;
        while(current!=NULL){
            forward = current->next;
            Node* temp = current;
            delete temp;
            current = forward;
        }
    }
};

int main(){
    SinglyLinkedList s;
    s.insertAtHead(100);
    s.insertAtTail(120);
    s.insertAtTail(69);
    s.insertAtPosition(1000, 1);
    s.insertAtTail(900);
    s.insertAtHead(1002);
    s.display();
    return 0;
}