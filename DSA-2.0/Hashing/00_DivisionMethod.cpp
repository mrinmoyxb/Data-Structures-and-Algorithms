#include <iostream>
#include <vector>

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

    bool search(int key){
        Node* current = head;
        while(current!=NULL){
            if(current->data == key){
                return true;
            }else{
                current = current->next;
            }
        }
        return false;
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

//! Division Method to generate hash value
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

    void search(int key){
        int index = hashFunction(key);
        bool isAvailable = hashTable[index].search(key);
        if(isAvailable){
            std::cout<<"Yes, "<<key<<" is available at "<<index<<std::endl;
        }else{
            std::cout<<"No"<<std::endl;
        }
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
    h.add(120);
    h.add(322);
    h.add(430);
    h.add(544);
    h.add(939);
    h.add(128);
    h.add(892);
    h.display();

    h.search(544);

    return 0;
}