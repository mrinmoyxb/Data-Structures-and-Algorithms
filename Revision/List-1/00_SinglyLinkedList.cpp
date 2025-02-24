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
    Node* LinkedList = nullptr;
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;

    SinglyLinkedList(int data){
        Node* newNode = new Node(data);
        LinkedList = newNode;
        head = LinkedList;
        tail = LinkedList;
        length+=1;
    }

    void insertAtHead(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        length+=1;
    }

    void insertAtTail(int data){
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
        length+=1;
    }

    void insertAtPositon(int data, int position){
        if(position==1){
            insertAtHead(data);
        }
        else{
            if(position>length){
                insertAtTail(data);
            }
            else{
                Node* newNode = new Node(data);
                Node* current = head;
                int count = 1;
                while(count<position-1){
                    current = current->next;
                    count+=1;
                }
                newNode->next = current->next;
                current->next = newNode;
                length+=1;
            }
        }
    }

    void display(){
        Node* current = head;
        std::cout<<"\nLinked List: "<<" ";
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

};

int main(){
    SinglyLinkedList s = SinglyLinkedList(100);
    s.insertAtHead(200);
    s.insertAtHead(300);
    s.insertAtTail(1000);
    s.insertAtTail(2000);
    s.insertAtPositon(99, 2);
    s.insertAtPositon(69, 1);
    s.insertAtPositon(100, 20);
    s.insertAtPositon(120, 8);
    s.display();
    return 0;
}