#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//* insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//* insert at tail
void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

//* insert at specific position
void insertAtPosition(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

//* length of linked list
int lengthOfLinkedList(Node* &head){
    int count = 0;
    Node* current = head;
    while(current){
        count++;
        current = current->next;
    }
    return count;
}

//* delete node
void deleteNode(Node* &head, int position){
    Node* current = head;
    if(position==1){
        cout<<"\nDeleted Node is: "<<current->data<<endl;
        head = head->next;
        current->next = NULL;
        delete current;
    }
    else{
        int count = 1;
        Node* prev = NULL;
        while(count<position){
            prev = current;
            current = current->next;
            count++;
        }
        Node* nodeToBeDeleted = current;
        cout<<"\nDeleted Node is: "<<current->data<<endl;
        prev->next = nodeToBeDeleted->next;
        nodeToBeDeleted->next = NULL;
        delete nodeToBeDeleted;
    }

}

//* find mid element
void findMidElement(Node* &head){
    int length = lengthOfLinkedList(head);
    Node* current = head;
    int mid = (length/2)+1;
    int count = 1;
    while(count<mid){
        current = current->next;
        count++;
    }
    cout<<"Mid element: "<<current->data<<endl;
}

//* display
void display(Node* &head){
    cout<<"\nLinkedList: "<<endl;
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

//* reverse a linked list
Node* reverseLinkedList(Node* &head){
    Node* current = head;
    Node* prev = NULL;
    Node* forward = head;
    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

//* palindrome 
bool Palindrome(Node* &head){
    vector<int> vec;
    bool isPalindrome = true;

    Node* current = head;
    while(current!=NULL){
        vec.push_back(current->data);
        current = current->next;
    }

    int i=0;
    for(int j=vec.size()-1; j>=0; j--){
        if(vec[i]!=vec[j]){
            isPalindrome = false;
            break;
        }
        i++;
    }
    return isPalindrome;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head);
    bool result = Palindrome(head);
    cout<<"\nPalindrome result: "<<result<<endl;
    return 0;
}