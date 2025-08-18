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

void display(Node* head){
    std::cout<<"\nLinked List"<<std::endl;
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
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

Node* mergeList(Node* list1, Node* list2){
    int l1 = lengthOfList(list1);
    int l2 = lengthOfList(list2);
    Node* current1 = list1;
    Node* current2 = list2;

    Node* head = NULL;
    Node* tail = NULL;

    while(current1!=NULL && current2!=NULL){
        if(current1->data <= current2->data){
            Node* newNode = new Node(current1->data);
            if(head==NULL){
                head = tail = newNode;
                current1 = current1->next;
            }else{
                tail->next = newNode;
                tail = newNode;
                current1 = current1->next;
            }
        }else{
            Node* newNode = new Node(current2->data);
            if(head==NULL){
                head = tail = newNode;
                current2 = current2->next;
            }else{
                tail->next = newNode;
                tail = newNode;
                current2 = current2->next;
            }
        }
    }

    while(current1!=NULL){
        Node* newNode = new Node(current1->data);
        tail->next = newNode;
        current1 = current1->next;
    }

    while(current2!=NULL){
        Node* newNode = new Node(current2->data);
        tail->next = newNode;
        current2 = current2->next;
    }
    return head;
}

int main(){
    Node* node1 = new Node(120);
    Node* head1 = node1;
    insertAtHead(head1, 100);
    insertAtTail(head1, 190);
    insertAtTail(head1, 910);
    insertAtTail(head1, 8000);
    display(head1);

    Node* node2 = new Node(90);
    Node* head2 = node2;
    insertAtHead(head2, 70);
    insertAtTail(head2, 200);
    insertAtTail(head2, 210);
    display(head2);

    Node* merge = mergeList(head1, head2);
    display(merge);

    return 0;
}