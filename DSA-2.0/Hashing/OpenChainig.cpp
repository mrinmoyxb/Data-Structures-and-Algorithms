#include <iostream>
#include <vector>

//! Open Chaining(Closed Addressing)
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
    public:
    Node* head = NULL;
    Node* tail = NULL;

    void insertAtTail(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display(){
        Node* current = head;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    ~LinkedList(){
        Node* current = head;
        while(current!=NULL){
            Node* forward = current->next;
            Node* temp = current;
            delete temp;
            current = forward;
        }
    }
};

class Hashing{
    public:
    std::vector<LinkedList> hashTable;
    int buckets;

    Hashing(int size){
        buckets = size;
        hashTable.resize(size);
    }

    int hashFunction(int key){
        return key%buckets;
    }

    void add(int key){
        int index = hashFunction(key);
        hashTable[index].insertAtTail(key);
    }

    void display(){
        for(int i=0; i<buckets; i++){
            std::cout<<"index "<<i<<" : ";
            hashTable[i].display();
            std::cout<<"\n";
        }
    }

};

int main(){
    Hashing h(10);
    h.add(102);
    h.add(119);
    h.add(142);
    h.add(102);
    h.add(643);
    h.add(507);
    h.display();
    return 0;
}