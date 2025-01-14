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

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//! Traverse linked list without recursion
void displayWithoutRecursion(Node* head){
    Node* current = head;
    std::cout<<"\nLinked List: "<<std::endl;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Traverse linked list with recursion
void displayWithRecursion(Node* head){
    if(head==NULL){
        return;
    }

    std::cout<<head->data<<" ";
    displayWithRecursion(head->next);
}

//! Linear search using recursion
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

//! Mid element;
Node* findMidElement(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//! Binary search using recursion
bool binarySearch(Node* head, int key){
    if(head==NULL){
        return false;
    }

    Node* mid = findMidElement(head);
    if(mid->data == key){
        return true;
    }

    if(key > mid->data){
        return binarySearch(mid->next, key);
    }else{
        Node* leftHead = head;
        Node* temp = head;
        while(temp->next!=mid){
            temp = temp->next;
        }
        temp->next = NULL;
        bool result = binarySearch(leftHead, key);
        temp->next = mid;
        return result;
    }
}

//! Check even num in linked list 
void checkNum(Node* head){
    if(head==NULL){
        return;
    }

    if(head->data%2==0){
        std::cout<<head->data<<" is even"<<std::endl;
    }
    checkNum(head->next);
}

int main(){
    Node* node = new Node(600);
    Node* head = node;
    insertAtHead(head, 533);
    insertAtHead(head, 400);
    insertAtHead(head, 789);
    insertAtHead(head, 233);
    insertAtHead(head, 100);
    displayWithoutRecursion(head);
    Node* copyHead = head;

    std::cout<<std::endl;
    std::cout<<"\nDisplay with recursion"<<std::endl;
    displayWithRecursion(head);

    std::cout<<std::endl;
    std::cout<<"\nLinear search: "<<linearSearch(head, 200)<<std::endl;

    std::cout<<std::endl;
    Node* mid = findMidElement(head);
    std::cout<<"Mid element: "<<mid->data<<std::endl;

    std::cout<<std::endl;
    int key;
    std::cout<<"\nEnter key: ";
    std::cin>>key;
    std::cout<<"Binary search: "<<binarySearch(head, key)<<std::endl;

    std::cout<<std::endl;
    checkNum(copyHead);
    return 0;
}