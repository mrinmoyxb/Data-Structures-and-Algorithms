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
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
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
    if(position==1){
        newNode->next = head;
        head = newNode;
    }
    else{
        int count = 1;
        Node* current = head;
        while(count<position-1){
            current = current->next;
            count+=1;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
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

int midNode(Node*& head){
    Node* current = head;
    int length = lengthOfList(head);
    int count = 1;
    int mid;
    if(length%2==0){
        mid = (length/2)+1;
    }else{
        mid = (length/2)+1;
    }

    while(count<mid){
        current = current->next;
        count+=1;
    }

    return current->data;

}

Node* reverse(Node*& head){
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

int midNodeOptimised(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    
    return slow->data;
}

void display(Node* head){
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* head = new Node(200);
    insertAtHead(head, 100);
    insertAtTail(head, 1000);
    insertAtTail(head, 1001);
    insertAtTail(head, 1002);
    insertAtTail(head, 1003);
    insertAtPosition(head, 99, 1);
    insertAtPosition(head, 69, 8);

    // display(head);

    // std::cout<<"\nLength: "<<lengthOfList(head)<<std::endl;
    // std::cout<<"Mid element: "<<midNode(head)<<std::endl;

    std::cout<<"Mid node: "<<midNodeOptimised(head)<<std::endl;

    return 0;
}