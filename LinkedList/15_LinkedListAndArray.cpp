#include <iostream>
#include <vector>
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

void insertAtTail(Node*& head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

//! Common elements in array and linked list using hashmap
std::vector<int> commonElementsInListAndArray(Node*& head){
    std::vector<int> arr = {100, 200, 3, 4, 500, 600};
    std::map<int, int> hashTable;

    std::cout<<"\nArray: "<<"\n";
    for(auto value: arr){
        std::cout<<value<<" ";
    }

    Node* current = head;
    while(current!=NULL){
        hashTable[current->data] += 1;
        current = current->next;
    }

    std::cout<<"\nHash Table"<<"\n";
    for(const auto& value: hashTable){
        std::cout<<value.first<<"   "<<value.second<<"\n";
    }

    std::vector<int> common;

    std::cout<<"\nCommon elements: "<<"\n";
    for(int i=0; i<arr.size()-1; i++){
        if(hashTable[arr[i]]!=0){
            common.push_back(arr[i]);
            std::cout<<arr[i]<<" ";
        }
    }

    return common;
}

//! Removal of common elements
void removalCommonElements(Node* &head, int data){
    std::vector<int> result = commonElementsInListAndArray(head);
    Node* current = head;
    Node* prev = head;
    
    // while(current!=NULL){
    //     for(auto& value: result){

    //     }
    // }
}

//! Deleting any element in linked list
void deleteELement(Node* &head, int key){
    if(head==NULL){
        return;
    }

    Node* current = head;
    Node* prev = head;
    if(head->data==key){
        Node* delNode = head;
        head = head->next;
        prev = head;
        delete delNode;
        return;
    }

    while(current!=NULL){
        if(current->data==key){
            Node* delNode = current;
            current = current->next;
            prev->next = current;
            delete delNode;
        }else{
            prev = current;
            current = current->next;
        }
    }
}

void display(Node* head){
    Node* current = head;
    std::cout<<"\nLinked List: "<<"\n";
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* node = new Node(1);
    Node* head = node;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 2);
    display(head);
    
    deleteELement(head, 2);
    display(head);
    // deleteELement(head, 4);
    // deleteELement(head, 4);

    return 0;
}