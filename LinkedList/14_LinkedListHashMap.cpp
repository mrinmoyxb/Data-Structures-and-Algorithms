#include <iostream>
#include <map>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail = newNode;
        tail->next = tail;
    }else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void insert(Node*& head, Node*& tail, int data){
    Node* newNode = new Node(data);
    if(head==NULL && tail==NULL){
        head = newNode;
        tail = head;
        tail->next = head;
    }else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void display(Node* tail){
    Node* current = tail;
    Node* head = current->next;
    do{
        std::cout<<head->data<<" ";
        head = head->next;
    }while(current->next!=head);
}

void hashMap(Node* tail){
    std::map<Node*, int> hashTable;
    Node* current = tail;
    Node* head = tail->next;
    do{
        std::cout<<head->data<<" "<<head<<"\n";
        hashTable[head] +=1;
        head = head->next;
    }while(current->next!=head);

    std::cout<<"\n";

    hashTable[head] += 1;

    for(const auto& value: hashTable){
        std::cout<<value.first<<"    "<<value.second<<"\n";
    }
}

void isListCircular(Node* head){
    Node* current = head;
    std::map<Node*, int> hashTable;

    do{
        hashTable[head]+=1;
        std::cout<<head->data<<" ";
        head = head->next;
    }while(hashTable[head]!=1);
    std::cout<<"\n";

    for(const auto& value: hashTable){
        std::cout<<value.first<<"   "<<value.second<<"\n";
    }
}

int main(){
    Node* node = NULL;
    Node* head = node;
    Node* tail = node;
    insert(head, tail, 100);
    insert(head, tail, 200);
    insert(head, tail, 300);
    insert(head, tail, 400);

    std::cout<<"\nLinked List: "<<"\n";
    display(tail);

    std::cout<<"\nHashmap: "<<"\n";
    isListCircular(head);

    return 0;
}