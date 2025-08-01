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

int lengthOfLinkedList(Node* head){
    Node* current = head;
    int count = 0;
    while(current!=NULL){
        count+=1;
        current = current->next;
    }
    return count;
}

void insertAtTail(Node*& head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void display(Node* head){
    std::cout<<"\nLinked list: "<<std::endl;
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! Merge two sorted linked list
Node* mergeTwoSortedLinkedList(Node* list1, Node* list2){
    Node* current1 = list1;
    Node* current2 = list2;
    int l1 = lengthOfLinkedList(list1);
    int l2 = lengthOfLinkedList(list2);
    int count1, count2 = 0;
    Node* head = NULL;
    Node* tail = NULL;

    while(count1<l1 && count2<l2){
        if (head==NULL){
            if(current1->data  < current2->data){
                Node* newNode = new Node(current1->data);
                head = tail = newNode;
                count1+=1;
                current1 = current1->next;
            }else{
                Node* newNode = new Node(current2->data);
                head = tail = newNode;
                count2+=1;
                current2 = current2->next;
            }
        }else{
            if(current1->data < current2->data){
                Node* newNode = new Node(current1->data);
                tail->next = newNode;
                tail = newNode;
                count1+=1;
                current1 = current1->next;
            }else{
                Node* newNode = new Node(current2->data);
                tail->next = newNode;
                tail = newNode;
                count2+=1;
                current2 = current2->next;
            }
        }
    }
    while(count1<l1){
        Node* newNode = new Node(current1->data);
        tail->next = newNode;
        tail = newNode;
        count1+=1;
        current1 = current1->next;
    }
    while(count2<l2){
        Node* newNode = new Node(current2->data);
        tail->next = newNode;
        tail = newNode;
        count2+=1;
        current2 = current2->next;
    }
    return head;
}

Node* removeNthNode(Node*& head, int n){
    if(head==NULL){
        return NULL;
    }

    Node* current = head;
    int length = lengthOfLinkedList(head);
    int position = length - n;
    int count = 0;

    if(length==1 && n==1){
        return NULL;
    }

    if(length==n){
        Node* temp = current;
        current = current->next;
        temp->next = NULL;
        delete temp;
        return current;
    }else{
        while(count<=position-1){
            count+=1;
            current = current->next;
        }   
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return head;
    }
}

int main(){
    Node* l1 = new Node(12);
    // Node* l2 = new Node(120);
    Node* head1 = l1;
    // Node* head2 = l2;
    insertAtTail(head1, 22);
    // insertAtTail(head1, 13);
    // insertAtTail(head1, 49);
    // insertAtTail(head1, 60);
    // insertAtTail(head1, 120);
    // insertAtTail(head2, 190);
    // insertAtTail(head2, 320);
    // insertAtTail(head2, 500);
    display(head1);
    // display(head2);

    // Node* sortedLinkedList = mergeTwoSortedLinkedList(head1, head2);
    // display(sortedLinkedList);
    
    Node* updateList = removeNthNode(head1, 1);
    display(updateList);
    return 0;
}