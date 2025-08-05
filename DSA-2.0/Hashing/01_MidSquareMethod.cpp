#include <iostream>
#include <vector>
#include <string>

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

    bool search(int data){
        Node* current = head;
        while(current!=NULL){
            if(current->data==data){
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
        Node* forward = NULL;
        while(current!=NULL){
            forward = current->next;
            Node* temp = current;
            delete current;
            current = forward;
        }
    }
};

//! Mid sqaure method 
class Hashing{
    public:
    int buckets;
    std::vector<LinkedList> hashTable;

    Hashing(int size){
        buckets = size;
        hashTable.resize(size);
    }

    int hashFunction(int key){
        int squared = key*key;
        std::string str = std::to_string(squared);
        int len = str.length();
        if(len%2==0){
            return std::stoi(str.substr(len/2-1, 2));
        }else{
            return std::stoi(str.substr(len/2, 1));
        }
    }

    void add(int key){
        int index = hashFunction(key);
        hashTable[index].insertAtTail(key);
    }

    void search(int key){
        int index = hashFunction(key);
        bool isAvailable = hashTable[index].search(key);
        if(isAvailable){
            std::cout<<"Yes, "<<key<<" is available at index "<<index<<std::endl;
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
    h.add(20);
    h.add(12);
    h.add(13);
    h.add(25);
    h.add(144);
    h.display();

    h.search(25);

    return 0;
}