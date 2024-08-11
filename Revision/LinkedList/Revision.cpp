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

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(Node* &head, int data, int position){
    Node* newNode = new Node(data);
    Node* current = head;
    int count = 1;
    while(count<position-1){
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void display(Node*&head){
    Node* current = head;
    cout<<"\nLinked List: "<<endl;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int lengthOfLinkedList(Node* &head){
    if(head==NULL){
        return 0;
    }
    int count = 0;
    Node* current = head;
    while(current!=NULL){
        count++;
        current = current->next;
    }
    return count;
}

Node* reverseLinkedList(Node* &head){
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

void findMid(Node* &head){
    Node* current = head;
    int mid = (lengthOfLinkedList(head)/2)+1;
    int count = 1;
    while(count<mid){
        current = current->next;
        count++;
    }
    cout<<"Mid element is: "<<current->data<<endl;
}

Node* deleteMid(Node* &head){
    Node* current = head;
    int mid = (lengthOfLinkedList(head)/2)+1;
    int count = 1;
    while(count<mid-1){
        current = current->next;
        count++;
    }
    Node* temp = current->next;
    current->next = temp->next;
    temp->next = NULL;
    delete temp;
    return head;
}

//* random
void findMidNodeUnusual(Node* &head){
    Node* current = head;
    int l = lengthOfLinkedList(head)/2;
    int mid = l+1;
    int count = 1;
    if(l%2==0){
       while(count<mid){
        current = current->next;
        count++;
       }
       cout<<"Mid element is: "<<current->data<<endl;
    }else{
        while(count<mid-1){
            current = current->next;
            count++;
        }
        cout<<"Mid elements are: "<<current->data<<" and "<<current->next->data<<endl;
    }
}


bool isPalindromeFunc(Node* &head){
    vector<int> reverseVec;
    Node* current = head;
    bool isPalindrome = true;

    while(current!=NULL){
        reverseVec.push_back(current->data);
        current = current->next;
    }
    int j = reverseVec.size()-1;
    for(int i=0; i<reverseVec.size(); i++){
        if(reverseVec[i]!=reverseVec[j]){
            isPalindrome = false;
            break;
        }
        j--;
    }
    return isPalindrome;
}

Node* evenOdd(Node* &head){
    Node* current = head;
    Node* evenHead = current->next;
    Node* even = current->next;
    Node* odd = current;
    while(even && even->next!=NULL){
        odd->next = even->next;
        even->next = odd->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 100);
    insertAtTail(head, 400);
    insertAtTail(head, 900);
    display(head);

    Node* r = evenOdd(head);
    display(r);

    return 0;
}