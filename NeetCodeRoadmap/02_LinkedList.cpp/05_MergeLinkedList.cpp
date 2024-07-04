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

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* temp = head;
    Node* newNode = new Node(data);
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* &head){
    Node* temp = head;
    cout<<"\nLinked list: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* mergeLinkedList(Node* &head1, Node* &head2){
    Node* mergeLinkedList = NULL;
    Node* prev = NULL;
    Node* current1 = head1;  // 1
    Node* current2 = head2;  // 

    if(mergeLinkedList == NULL && current1 == NULL){
        mergeLinkedList = new Node(current2->data);
        prev = mergeLinkedList;
        return mergeLinkedList;
    }
    else if(mergeLinkedList == NULL && current2 == NULL){
        mergeLinkedList = new Node(current1->data);
        prev = mergeLinkedList;
        return mergeLinkedList;
    }

    while(mergeLinkedList==NULL && (current1 != NULL || current2 != NULL)){
        if(current1->data <= current2->data){
            mergeLinkedList = new Node(current1->data);
            prev = mergeLinkedList;
            current1 = current1->next;
        }
        else{
            mergeLinkedList = new Node(current2->data);
            prev = mergeLinkedList;
            current2 = current2->next;
        }
    }

    while(current1!=NULL && current2!=NULL){
        if(current1->data <= current2->data){
            Node* newNode = new Node(current1->data);
            prev->next = newNode;
            prev = newNode;
            current1 = current1->next;
        }
        else{
            Node* newNode = new Node(current2->data);
            prev->next = newNode;
            prev = newNode;
            current2 = current2->next;
        }
    }

    while(current1 != NULL){
        Node* newNode = new Node(current1->data);
        prev->next = newNode;
        prev = newNode;
        current1 = current1->next;
    }

    while(current2 != NULL){
        Node* newNode = new Node(current2->data);
        prev->next = newNode;
        prev = newNode;
        current2 = current2->next;
    }

    return mergeLinkedList;
}


int main(){

    Node* node1 = new Node(4);
    Node* head1 = node1;

    insertAtHead(head1, 2);
    insertAtHead(head1, 1);
    display(head1);

    Node* node2 = new Node(4);
    Node* head2 = node2;

    insertAtHead(head2, 3);
    insertAtHead(head2, 1);
    display(head2);

    // test case 1
    Node* d1 = mergeLinkedList(head1, head2);
    display(d1);


    // test case 2
    cout<<endl;
    Node* head3 = NULL;
    Node* head4 = NULL;
    Node* d2 = mergeLinkedList(head3, head4);
    display(d2);

    // test case 3
    cout<<endl;
    Node* head5 = NULL;
    Node* head6 = new Node(0);

    Node* d3 = mergeLinkedList(head5, head6);
    display(d3);

    
    return 0;
}