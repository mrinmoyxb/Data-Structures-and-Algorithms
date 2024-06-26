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

    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

//* here I am using < &head > to use as a reference instead of creating a copy of the linked list
//* here < head > = address of the head and < *head > = value and < next > is a pointer that stores address 
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMid(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* &head){
    cout<<"\nLinked List: "<<endl;
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int LengthOfLinkedList(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void nodesWithEvenValues(Node* &head){
    vector<int> evenNodes;
    Node* temp = head;
    while(temp!=NULL){
        if((temp->data)%2==0){
            evenNodes.push_back(temp->data);
        }
        temp = temp->next;
    }

    cout<<"\nEven nodes: "<<endl;
    for(int i=0; i<evenNodes.size(); i++){
        cout<<evenNodes[i]<<" ";
    }
}

void deleteNode(Node* &head, int position){
    if(position==1){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* current = head;
        Node* previous = NULL;
        int count = 1;
        while(count<position){
            previous = current;
            current = current -> next;
            count++;
        }
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}



int main(){
    Node* newNode = new Node(100);
    Node* head = newNode;
    insertAtHead(head, 250);
    insertAtHead(head, 39);
    insertAtHead(head, 45);
    insertAtHead(head, 200);
    insertAtTail(head, 1000);
    insertAtMid(head, 69, 4);
    display(head);
    deleteNode(head, 7);
    display(head);
    return 0;
}