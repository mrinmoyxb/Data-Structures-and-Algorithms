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

int main(){
    Node* node = NULL;
    Node* tail = node;
    insertAtTail(tail, 100);
    insertAtTail(tail, 200);
    insertAtTail(tail, 300);
    insertAtTail(tail, 400);

    std::cout<<"\nLinked List: "<<"\n";
    display(tail);

    std::cout<<"\nHashmap: "<<"\n";
    hashMap(tail);

    return 0;
}