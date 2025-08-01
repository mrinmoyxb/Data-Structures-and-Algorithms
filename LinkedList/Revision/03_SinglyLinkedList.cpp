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
            head->next = newNode;
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

    void insertAtPosition(int data, int position){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = tail = newNode;
        }else{
            Node* current = head;
            int count = 1;
            while(count<position-1){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    int findLength(){
        Node* current = head;
        int count = 0;
        while(current!=NULL){
            count+=1;
            current = current->next;
        }
        return count;
    }

    int midValue(){
        if(head==NULL){
            return -1;
        }else{
            Node* current = head;
            int length = findLength();
            int mid = (length/2)+1;
            int count = 0;
            while(count<mid){
                count+=1;
                current = current->next;
            }
            return current->data;
        }
    }

    Node* reverseLinkedList(){
        if(head==NULL || tail==NULL){
            return NULL;
        }else{
            Node* current = head;
            Node* forward = NULL;
            Node* prev = NULL;
            while(current!=NULL){
                forward = current->next;
                current->next = prev;
                prev = current;
                current = forward;
            }
            return prev;
        }
    }


    void display(){
        std::cout<<"Length of linked list: "<<std::endl;
        Node* current = head;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }


    ~SinglyLinkedList(){
        Node* current = head;
        Node* forward = nullptr;
        while(current!=NULL){
            forward = current->next;
            delete current;
            current = forward;
        }
        head = tail = nullptr;
        std::cout<<"\nDestructor called"<<std::endl;
    }
};

int main(){
    SinglyLinkedList s = SinglyLinkedList();
    s.insertAtHead(100);
    s.insertAtTail(200);
    s.insertAtTail(300);
    s.insertAtTail(400);
    s.insertAtTail(500);
    s.insertAtPosition(1000, 2);
    s.display();

    std::cout<<"\nLength of linked list: "<<s.findLength()<<std::endl;
    std::cout<<"Mid value: "<<s.midValue()<<std::endl;

    Node* rev = s.reverseLinkedList();
    std::cout<<"Reverse Linked List: "<<std::endl;
    Node* current = rev;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }

    SinglyLinkedList s = SinglyLinkedList();

    return 0;
}