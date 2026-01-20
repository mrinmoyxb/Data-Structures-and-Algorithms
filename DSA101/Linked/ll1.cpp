#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int data): data(data), next(nullptr){};
};

void insertAtHead(Node*& head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=nullptr){
        current = current->next;
    }
    current->next = newNode;
}

void display(Node* head){
    Node* current = head;
    std::cout<<"\nLinked List: "<<std::endl;
    while(current!=nullptr){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//! LEETCODE 237 ✅
void deleteNode(Node*& node){
    if(node==nullptr || node->next==nullptr){
        return;
    }
    Node* current = node;
    Node* deleteNode;
    while(current->next!=nullptr){
        if(current->next->next==nullptr){
            deleteNode = current->next;
            current->data = current->next->data;
            current->next = nullptr;
            break;
        }
        current->data = current->next->data;
        current = current->next;
    }

    delete deleteNode;
}

//! LEETCODE 2095 ✅
Node* deleteMid(Node*& head){

    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    Node* delNode = slow;
    slow->next = NULL;
    delete delNode;

    return head;
}

//! LEETCODE 876 ✅
Node* midNode(Node*& head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//! LEETCODE 328: ✅
Node* oddEvenLinkedList(Node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* evenCopy = head->next;

    while(even!=NULL && even->next!=NULL){
        odd->next = even->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = evenCopy;
    return head;
}

//! LEETCODE 142: 
Node* linkedListCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }

    if(slow!=fast){
        return NULL;
    }

    Node* p = head;
    while(p!=slow){
        p=p->next;
        slow=slow->next;
    }

    return p;
}



int main(){
    Node* head = new Node(100);
    insertAtTail(head, 200);
    insertAtTail(head, 300);
    insertAtTail(head, 400);
    insertAtTail(head, 500);
    display(head);

    Node* oe = oddEvenLinkedList(head);
    display(oe);

    return 0;
}