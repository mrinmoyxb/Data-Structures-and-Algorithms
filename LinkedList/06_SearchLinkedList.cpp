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

//! Insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//! Display 
void display(Node* head){
    Node* current = head;
    std::cout<<"Linked List: "<<std::endl;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Linear search in linked list
void linearSearch(Node* &head, int key){
    Node* current = head;
    while(current!=NULL){
        if(current->data == key){
            std::cout<<key<<" found in the linked list"<<std::endl;
            break;
        }
        else{
            current = current->next;
        }
    }
    if(current==NULL){
        std::cout<<"Not found in the linked list"<<std::endl;
    }
}

Node* findMid(Node* head, Node* last){
    Node* slow = head;
    Node* fast = slow->next;
    while(fast!=last){
        fast = fast->next;
        slow = slow->next;
        if (fast != last) {
            fast = fast->next;
        }
    }
    return slow;
}

//! Binary search in linked list
bool binarySearch(Node* head, int key){
    Node* start = head;
    Node* end = NULL;
    Node* mid = findMid(head, end);

    while(true){
        if(mid==NULL){
            return false;
        }

        if(mid->data == key){
            return true;
        }

        if(key > mid->data){
            start = mid->next;
        }
        else{
            end = mid;
        }
        mid = findMid(head, end);
    }
    return false;
}

int main(){
    Node* node = new Node(1000);
    Node* head = node;
    insertAtHead(head, 800);
    insertAtHead(head, 700);
    insertAtHead(head, 400);
    insertAtHead(head, 100);
    display(head);

    int key;
    std::cout<<"\nEnter the key you want to search: ";
    std::cin>>key;

    linearSearch(head, key);

    std::cout<<"\nBinary search: "<<binarySearch(head, key)<<std::endl;
}