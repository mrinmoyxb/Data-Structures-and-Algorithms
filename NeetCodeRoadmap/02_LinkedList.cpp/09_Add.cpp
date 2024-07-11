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

    ~Node(){}
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void display(Node* &head){
    cout<<"\nLinked List: "<<endl;
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}







void InsertAtTail(Node* &head1, Node* &tail, int digit){
    Node* newNode = new Node(digit);
    if(head1==NULL){
        head1 = newNode;
        tail = newNode;
        return;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }

}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;

    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    return prev;
}

Node* Add(Node* &first, Node* &second){
    int carry = 0;
    int sum = 0;
    Node* headPtr = NULL;
    Node* tailPtr = NULL;

    while(first!=NULL && second !=NULL){
        sum = carry + first->data + second->data;
        int digit = sum%10;
        InsertAtTail(headPtr, tailPtr, digit);
        carry = sum/10;
        first = first->next;
        second = second->next;
    }

    while(first!=NULL){
        sum = carry + first->data + second->data;
        int digit = sum%10;
        InsertAtTail(headPtr, tailPtr, digit);
        carry = sum/10;
        first = first->next;
    }

    while(second!=NULL){
        sum = carry + first->data + second->data;
        int digit = sum%10;
        InsertAtTail(headPtr, tailPtr, digit);
        carry = sum/10;
        second = second->next;
    }

    while(carry!=0){
        sum = carry;
        int digit = sum%10;
        InsertAtTail(headPtr, tailPtr, digit);
        carry = sum/10;
    }
}

Node* sumOfTwoLinkedList(Node* &head1, Node* &head2){
    Node* first = reverse(head1);
    Node* second = reverse(head2);
    Node* ans = Add(first, second);
    ans = reverse(ans);
    return ans;
}

int main(){
    Node* node1 = new Node(1);
    Node* head1 = node1;
    insertAtHead(head1, 2);
    insertAtHead(head1, 1);

    Node* node2 = new Node(2);
    Node* head2 = node2;
    insertAtHead(head2, 2);

    return 0;
}