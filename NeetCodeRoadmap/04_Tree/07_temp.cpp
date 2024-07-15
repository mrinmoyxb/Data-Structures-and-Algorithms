#include <iostream>
#include <sstream>
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

int length(Node* head){
    int count = 0;
    Node* current = head;
    while(current!=NULL){
        count++;
        current = current->next;
    }
    return count;
}

void deleteMid(Node* &head){
    int count = 1;
    Node* current = head;
    int  = length(head);

    while(count<mid-1){
        current = current->next;
        count++;
    }

    Node* deleteNode = current->next;
    current->next = deleteNode->next;
    deleteNode->next = NULL;
    delete deleteNode;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    display(head);

    cout<<"\n"<<length(head)<<endl;
    deleteMid(head);
    display(head);
    return 0;
}

/*

int getLength(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        ListNode* current = head;
        int length = getLength(head);
        if(length==1){
            delete current;
            return NULL;
        }
        else{
            int mid = (length/2)+1;
            int count = 1;
            while(count<mid-1){
                current = current->next;
                count++;
            }
            ListNode* midNode = current->next;
            current->next = current->next->next;
            midNode->next = NULL;
            delete midNode;
            return temp;
        }
    }
*/