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
std::vector<int> commonElementsInListAndArray(Node*& head, std::vector<int> arr){
   
    std::map<int, int> hashTable;

    Node* current = head;
    while(current!=NULL){
        hashTable[current->data] += 1;
        current = current->next;
    }

    std::vector<int> common;
    for(int i=0; i<arr.size()-1; i++){
        if(hashTable[arr[i]]!=0){
            common.push_back(arr[i]);
        }
    }

    return common;
}

//! Removal of common elements
void removalCommonElements(Node* &head, std::vector<int> arr){
    std::vector<int> result = commonElementsInListAndArray(head, arr);

    for(const auto& key: arr){
        Node* current = head;
        Node* prev = head;
        if(head->data==key){
            Node* delNode = head;
            head = head->next;
            delete delNode;
        }else{
            current = current->next;
        }
        while(current!=NULL){
            if(current->data==key){
                Node* delNode = current;
                prev->next = current->next;
                current = current->next;
                delete delNode;
            }else{
                prev = current;
                current = current->next;
            }
        }
    }
}

//? Remove elements present in an array
void removeElements(Node* &head, std::vector<int> arr){
    
    for(const auto& key: arr){
        std::cout<<"\nCurrent key: "<<key<<"\n";
        Node* current = head;
        Node* prev = head;
        if(head->data==key){
            Node* delNode = head;
            head = head->next;
            delete delNode;
        }else{
            current = current->next;
        }
        while(current!=NULL){
            if(current->data==key){
                Node* delNode = current;
                prev->next = current->next;
                current = current->next;
                delete delNode;
            }else{
                prev = current;
                current = current->next;
            }
        }
    }
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

//? display linked list
void display(Node* head){
    Node* current = head;
    std::cout<<"\nLinked List: "<<"\n";
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Traverse linked lsit using for loop
void displayUsingForLoop(Node* head){
    std::cout<<"Traversal of linked list using for loop: "<<"\n";
    for(Node* current = head; current!=NULL; current = current->next){
        std::cout<<current->data<<" ";
    }
}

int main(){
    Node* node = new Node(1);
    Node* head = node;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    
    displayUsingForLoop(head);
    std::vector<int> arr = {100, 1, 3, 5, 500, 600};
    std::cout<<"\nArray: "<<"\n";
    for(const auto& item: arr){
        std::cout<<item<<" ";
    }
    
    std::vector<int> result = commonElementsInListAndArray(head, arr);
    std::cout<<"\nCommon elements: "<<"\n";
    for(const auto& value: result){
        std::cout<<value<<" ";
    }

    removalCommonElements(head, arr);
    display(head);

    return 0;
}