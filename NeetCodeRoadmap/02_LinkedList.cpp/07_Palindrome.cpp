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
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void display(Node* &head){
    cout<<"\nList: "<<endl;
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<endl;
        cout<<"\nhead: "<<head->data<<endl;
        current = current->next;
    }
}

Node* copy(Node* &head){

    Node* current = head;
    Node* copy= NULL;
    Node* prev = NULL;

    if(copy==NULL && current != NULL){
        copy =  new Node(current->data);
        prev = copy;
        current = current->next;
    }

    while(current!=NULL){
        Node* newNode = new Node(current->data);
        prev->next = newNode;
        prev = newNode;
        current = current->next;
    }


    Node* c = copy;
    Node* p = NULL;
    Node* forward = NULL;

    while(c!=NULL){
        forward = c->next;
        c->next = p;
        p = c;
        c = forward;
    }
    
    return p;

}

void checkPalindrome(Node* &head){
    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;
    Node* temp = head;
    bool isPalindrome = true;

    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    while(temp!=NULL){
        cout<<"\nrev: "<<prev->data<<endl;
        cout<<"current: "<<temp->data<<endl;
        if(prev->data != temp->data){
            isPalindrome = false;
        }

        prev = prev ->next;
        temp = temp->next;       
    }

    cout<<"\nPalindrome: "<<isPalindrome<<endl;
}


void checkPalindromeUsigVector(Node* &head){
    vector<int> vec;
    Node* temp = head;
    bool isPalindrome = true;

    //* copying linked list data to vector
    while(temp!=NULL){
        vec.push_back(temp->data);
        temp = temp->next;
    }
    
    //* vector
    cout<<"\nVector: "<<endl;
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    int j = 0;
    for(int i=vec.size()-1; i>=0;  i--){
        if(vec[i] != vec[j]){
            isPalindrome = false;
            break;
        }
        j++;
    }

    cout<<"\nIsPalindrome: "<<isPalindrome<<endl;

}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head);

    //checkPalindrome(head);
//    Node* c = copy(head);
//    display(c);
//    display(head);

    checkPalindromeUsigVector(head);
    return 0;
}