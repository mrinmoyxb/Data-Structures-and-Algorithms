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

void insertAtHead(Node*& head, int data){
    if(head==NULL){
        head = new Node(data);
    }else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node*& head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(Node*& head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
        count+=1;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void display(Node* head){
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

Node* reverseList(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* prev = NULL;
    Node* current = head;
    while(current!=NULL){
        Node* forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    return prev;
}

Node* midOfList(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int lengthOfList(Node* head){
    Node* current = head;
    int count = 0;
    while(current!=NULL){
        count+=1;
        current = current->next;
    }
    return count;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 100);
    insertAtHead(head, 200);
    insertAtTail(head, 999);
    insertAtPosition(head, 400, 2);
    insertAtTail(head, 999);
    display(head);
    // std::cout<<std::endl;
    // Node* r = reverseList(head);
    // display(r);
    // std::string s = "123";
    // for(int i=0; i<s.length(); i++){
    //     std::cout<<s[i]<<"\n";
    // }

    std::cout<<lengthOfList(head)<<std::endl;
    return 0;
}