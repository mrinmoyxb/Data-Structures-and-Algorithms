#include <iostream>

class Node{
    public:
    int data;
    Node* prev;
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
    head->prev = newNode;
    head = newNode;
}

//! Insert at tail
void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

//! Insert at mid
void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
        count+=1;
    }
    newNode->next = current->next;
    current->next = newNode;
    newNode->prev = current;
}

//! Display using recursion
void displayUsingRecursion(Node* head){
    if(head==NULL){
        return;
    }
    std::cout<<head->data<<" ";
    displayUsingRecursion(head->next);
}

void display(Node* head){
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Reverse traverse
void reverseTraverse(Node* head){
    Node* start = head;
    Node* end = head;
    while(end->next!=NULL){
        end = end->next;
    }
    
    std::cout<<"\nReverse Linked List"<<std::endl;
    while(end!=NULL){
        std::cout<<end->data<<" ";
        end = end->prev;
    }
}

//! Reverse traverse Using recursion
void reverseUsingRecursion(Node* head){
    if(head==NULL){
        return;
    }

    reverseUsingRecursion(head->next);
    std::cout<<head->data<<" ";
}

//! Linear search
bool linearSearch(Node* head, int key){
    if(head==NULL){
        return false;
    }

    if(head->data == key){
        return true;
    }else{
        return linearSearch(head->next, key);
    }
}

//! Length of linked list
int lengthOfLinkedList(Node* head){
    Node* current = head;
    int count = 0;
    while(current!=NULL){
        count+=1;
        current = current->next;
    }
    return count;
}

//! Find mid
void midOfLinkedList(Node* head){
    Node* current = head;
    int length = lengthOfLinkedList(head);
    int mid = (length/2)+1;
    int count = 1;
    while(count<mid){
        current = current->next;
        count+=1;
    }
    std::cout<<current->data<<std::endl;
}

//! Mid element 
Node* findMid(Node* start, Node* end){
    Node* slow = start;
    Node* fast = start;
    while(fast!=end && fast->next!=end){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//! Binary search
bool binarySearch(Node* start, Node* end, int key){
    if(start==NULL){
        return false;
    }

    Node* mid = findMid(start, end);
    if(mid->data == key){
        return true;
    }

    if(key > mid->data){
        return binarySearch(mid->next, end, key);
    }else{
        return binarySearch(start, mid, key);
    }
}

int main(){
    Node* node = new Node(500);
    Node* head = node;
    Node* temp = node;
    insertAtHead(head, 400);
    insertAtHead(head, 300);
    insertAtHead(head, 200);
    insertAtHead(head, 100);
    insertAtTail(head, 1200);
    insertAtMid(head, 250, 3);

    std::cout<<"\nLinked List: "<<std::endl;
    display(head);

    std::cout<<std::endl;
    std::cout<<"Binary Search: "<<binarySearch(head, NULL, 200);

    return 0;
}