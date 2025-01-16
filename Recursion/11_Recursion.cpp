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

//! Insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//! Display
void display(Node* head){
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Display using recursion
void displayUsingRecursion(Node* head){
    if(head==NULL){
        return;
    }

    std::cout<<head->data<<" ";
    displayUsingRecursion(head->next);
}

//! Linear search using recursion
bool linearSearch(Node* head, int key){
    if(head==NULL){
        return false;
    }

    if(head->data==key){
        return true;
    }
    return linearSearch(head->next, key);
}

//! Mid element of linked list
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//! Binary search in linked list
bool binarySearch(Node* head, int key){
    if(head==NULL){
        return false;
    }

    Node* mid = findMid(head);
    if(mid->data==key){
        return true;
    }

    if(key>mid->data){
        return binarySearch(mid->next, key);
    }else{
        Node* current = head;
        Node* temp = head;
        while(temp->next!=mid){
            temp = temp->next;
        }
        temp->next = NULL;
        bool result = binarySearch(current, key);
        temp->next = mid;
        return result;
    }
}

//! Function to return max between two numbers
int max(int num1, int num2){
    return num1>num2 ? num1 : num2;
}

//! Function to return min between two numbers
int min(int num1, int num2){
    return num1>num2 ? num2 : num1;
}

//! Max element using recursion
int maxInLinkedList(Node* head){
    if(head->next==NULL){
        return head->data;
    }
    return max(head->data, maxInLinkedList(head->next));
}

//! Min element using recursion
int minInLinkedList(Node* head){
    if(head->next==NULL){
        return head->data;
    }

    return min(head->data, minInLinkedList(head->next));
}

//! Check sorted and unsorted
bool checkSorted(Node* head){
    Node* current = head;
    bool isSorted = true;
    while(current!=NULL && current->next!=NULL){
        if(current->data > current->next->data){
            isSorted = false;
            break;
        }
        current = current->next;
    }
    return isSorted;
}

//! Check if the linked list is sorted using recursion
bool checkSortedUsingRecursion(Node* head){
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return true;
    }

    if(head->data > head->next->data){
        return false;
    }else{
        return checkSortedUsingRecursion(head->next);
    }
}

int main(){
    Node* node = new Node(800);
    Node* head = node;
    insertAtHead(head, 400);
    insertAtHead(head, 200);
    insertAtHead(head, 900);
    insertAtHead(head, 500);
    insertAtHead(head, 10);

    displayUsingRecursion(head);
    //std::cout<<"\nLinear search : "<<linearSearch(head, 200);

    //std::cout<<"\nBinary Search: "<<binarySearch(head, 900);
    std::cout<<std::endl;

    // std::cout<<"\nMax Element: "<<maxInLinkedList(head);
    // std::cout<<std::endl;

    // std::cout<<"\nMin Element: "<<minInLinkedList(head);
    // std::cout<<std::endl;

    //std::cout<<"\nIs sorted: "<<checkSorted(head);
    std::cout<<"\nIs sorted using recursion: "<<checkSortedUsingRecursion(head);
    return 0;
}