#include <iostream>
#include <vector>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node*& head, int data){
    Node* newNode = new Node(data);
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void display(Node* head){
    std::cout<<"\nLinked list: "<<std::endl;
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

Node* swapNodesInPairs(Node* list){
    if(list==NULL){
        return NULL;
    }

    int length = lengthOfList(list);
    if(length==1){
        return list;
    }else{
        Node* head = list;
        Node* current = list;
        bool isEven = false;
        int count = 1;
        while(count<length && current->next!=NULL){
            if(count%2!=0){
                std::swap(current->data, current->next->data);
                current = current->next;
                count+=1;
            }else{
                current = current->next;
                count+=1;
            }
        }

        return head;

    }

}

int main(){
    Node* l1 = new Node(100);
    Node* head = l1;
    insertAtTail(head, 200);
    insertAtTail(head, 300);
    display(head);

    Node* swapList = swapNodesInPairs(head);
    display(swapList);
    return 0;
}