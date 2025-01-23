#include <iostream>
#include <stack>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//! Insert at tail
void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

//! Display linked list
void display(Node* head){
    std::cout<<"\nLinked List: "<<"\n";
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<" ";
        current = current->next;
    }
}

//* Using Stack - Approach 1
Node* deleteNode1(Node* head){
    std::stack<Node*> st;
    Node* current = head;
    while(current!=NULL){
        st.push(current);
        current = current->next;
    }

    current = st.top();
    st.pop();
    int max = current->data;

    Node* resultHead = new Node(current->data);
    while(!st.empty()){
        current = st.top();
        st.pop();
        if(current->data < max){
            continue;
        }else{
            Node* newNode = new Node(current->data);
            newNode->next = resultHead;
            resultHead = newNode;
        }
    }

    return resultHead;
}

//! Delete Node using reverse linked list
Node* reverseLinkedList(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* forward;
    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

Node* deleteNode(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* rev = reverseLinkedList(head);
    Node* current = rev;
    int max = current->data;
    while(current!=NULL){
        if(current->data < current->next->data){
            Node* delNode = current->next;
            current->next = delNode->next;
            delete delNode;
        }else{
            max = current->data;
            current = current->next;
        }
    }

    return current;
}


int main(){
    Node* node = new Node(5);
    Node* head = node;
    insertAtTail(head, 2);
    insertAtTail(head, 13);
    insertAtTail(head, 3);
    insertAtTail(head, 8);

    display(head);

    Node* rev = deleteNode1(head);
    display(rev);
    return 0;
}