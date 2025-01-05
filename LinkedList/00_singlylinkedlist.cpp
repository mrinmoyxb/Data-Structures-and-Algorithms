#include <iostream>
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

//! Insert at head
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
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
}

//! Insert at mid
void insertAtMid(Node* &head, int data, int position){
    Node* current = head;
    Node* newNode = new Node(data);
    int count = 1;
    while(count<position-1){
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

//! Reverse linked list
Node* reverseLinkedList(Node* &head){
    if(head==NULL){
        return head;
    }
    Node* current = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

//! Display linked list
void display(Node* head){
    Node* current = head;
    cout<<"Linked List: "<<endl;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

//! Length of linked list
int lengthOfLinkedList(Node* &head){
    int count = 0;
    Node* current = head;
    while(current!=NULL){
        count++;
        current = current->next;
    }
    return count;
}

//! Delete mid node
void deleteMid(Node* &head){
    int length = lengthOfLinkedList(head);
    int mid = (length/2)+1;
    int count = 1;
    Node* current = head;
    while(count<mid-1){
        current = current->next;
        count+=1;
    }
    Node* deleteNode = current->next;
    cout<<"\nDelete node: "<<deleteNode->data<<endl;
    current->next = current->next->next;
    delete deleteNode;
}

//! Delete element at any position 
void deleteNode(Node* &head, int position){
    try{
        int length = lengthOfLinkedList(head);
        if(position<=length){
            if(position==1){
                Node* delNode = head;
                cout<<"\nDelete Node: "<<delNode->data<<endl;
                head = head->next;
                delete delNode;
            }
            else{
                int count = 1;
                Node* current = head;
                while(count<position-1){
                    current = current->next;
                    count++;
                }
                Node* delNode = current->next;
                cout<<"\nDelete Node: "<<delNode->data<<endl;
                current->next = current->next->next;
                delete delNode;
            }
        }
        else{
            throw "\nError: Out of range";
        }
        
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    
}



int main(){
    Node* node1 = new Node(100);
    Node* head = node1;
    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    insertAtTail(head, 1000);
    display(head);

    cout<<endl;
    insertAtMid(head, 1000, 3);
    display(head);

    cout<<endl;
    // Node* rev = reverseLinkedList(head);
    // display(rev);

    // deleteMid(head);
    // display(head);

    deleteNode(head, 7);
    display(head);

    return 0;
}