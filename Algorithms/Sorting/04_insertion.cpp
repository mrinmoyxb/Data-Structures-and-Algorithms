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

void display(Node* &head){
    Node* current = head;
    cout<<"\nLinked List: "<<endl;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}




Node* insertionSort(Node* &head){

    Node* current = head;
    Node* insertPointer = head;
    current = current->next;

    while(current!=NULL){
        insertPointer = head;

        while(insertPointer!=current){
            if(insertPointer->data > current->data){
               swap(insertPointer->data, current->data);
            }
            else{
                insertPointer = insertPointer->next;
            }
        }
        current = current->next;
    }

    return head;

}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;

    insertAtHead(head, 20);
    insertAtHead(head, 5);
    insertAtHead(head, 9);

    display(head);

    Node* r = insertionSort(head);
    display(r);

    return 0;
}