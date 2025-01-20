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

//! Display using recursion
void displayRec(Node* head){
    if(head==NULL){
        return;
    }
    std::cout<<head->data<<" ";
    displayRec(head->next);
}

//! Length of linked list using recursion
int lengthUsingRecursion(Node* head){
    if(head==NULL){
        return 0;
    }
    return 1 + lengthUsingRecursion(head->next);
}

//! Mid of linked list
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//! binary search using recursion
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

//! Reverse print
void rev(Node* head){
    if(head==NULL){
        return;
    }
    rev(head->next);
    std::cout<<head->data<<" ";
}

//! Mid of linked list using recursion
int midOfLinkedList(Node* head, int start, int mid){
    if(start==mid){
        return head->data;
    }
    return midOfLinkedList(head->next, start+=1, mid);
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


int main(){
    Node* node = new Node(500);
    Node* head = node;
    insertAtHead(head, 400);
    insertAtHead(head, 300);
    insertAtHead(head, 200);
    insertAtHead(head, 100);

    displayRec(head);
    std::cout<<"\nLength: "<<lengthUsingRecursion(head);
    int key = 200;
    std::cout<<"\nKey: "<<key<<"\n";
    std::cout<<"\nBinary Search: "<<binarySearch(head, key);
    std::cout<<"\nLinked List"<<"\n";
    rev(head);

    int length = lengthUsingRecursion(head);
    std::cout<<"\nMid element of linked list: "<<midOfLinkedList(head, 1, (length/2)+1);

    std::cout<<"\nLinear Search: "<<linearSearch(head, key)<<"\n";

    return 0;
}