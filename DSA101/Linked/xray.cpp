#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

void xray(){
    Node* node1 = new Node(100);
    Node* node2 = new Node(200);
    node1->next = node2;
    node2->next = node1;

    std::cout<<"Node1: "<<std::endl;
    std::cout<<"The data of node1: "<<node1->data<<std::endl;
    std::cout<<"The data of node1 (*node1).data: "<<(*node1).data<<std::endl;
    std::cout<<"The next of node1: "<<node1->next<<std::endl;
    std::cout<<"The next of node1 (*node1).next: "<<(*node1).next<<std::endl;
    std::cout<<"The address of the node1: "<<node1<<std::endl;
    std::cout<<"The address of the node1 pointer: "<<&node1<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Node2: "<<std::endl;
    std::cout<<"The data of node2: "<<node2->data<<std::endl;
    std::cout<<"The data of node1 (*node1).data: "<<(*node2).data<<std::endl;
    std::cout<<"The next of node2: "<<node2->next<<std::endl;
    std::cout<<"The next of node1 (*node2).next: "<<(*node2).next<<std::endl;
    std::cout<<"The address of the node2: "<<node2<<std::endl;
    std::cout<<"The address of the node2 pointer: "<<&node2<<std::endl;

    delete node1;
    delete node2;
}

void xray1Func(Node* node1, Node*& node2){
    Node* newNode1 = new Node(120);
    std::cout<<"address of newNode1: "<<newNode1<<std::endl;
    Node* newNode2 = new Node(120);
    std::cout<<"address of newNode2: "<<newNode2<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Node1 inside function: "<<std::endl;
    std::cout<<"The data of node1: "<<node1->data<<std::endl;
    std::cout<<"The data of node1 (*node1).data: "<<(*node1).data<<std::endl;
    std::cout<<"The next of node1: "<<node1->next<<std::endl;
    std::cout<<"The next of node1 (*node1).next: "<<(*node1).next<<std::endl;
    std::cout<<"The address of the node1: "<<node1<<std::endl;
    std::cout<<"The address of the node1 pointer: "<<&node1<<std::endl;
    node1->next = newNode1;
    std::cout<<"(after) The next of node1: "<<node1->next<<std::endl;
    std::cout<<"(after) The next of node1 (*node1).next: "<<(*node1).next<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Node2 inside function: "<<std::endl;
    std::cout<<"The data of node2: "<<node2->data<<std::endl;
    std::cout<<"The data of node2 (*node2).data: "<<(*node2).data<<std::endl;
    std::cout<<"The next of node2: "<<node2->next<<std::endl;
    std::cout<<"The next of node2 (*node2).next: "<<(*node2).next<<std::endl;
    std::cout<<"The address of the node2: "<<node2<<std::endl;
    std::cout<<"The address of the node2 pointer: "<<&node2<<std::endl;
    node2->next = newNode2;
    std::cout<<"(after) The next of node2: "<<node2->next<<std::endl;
    std::cout<<"(after) The next of node2 (*node2).next: "<<(*node2).next<<std::endl;
}
void xray1(){
    Node* node1 = new Node(100);
    std::cout<<"Node1: "<<std::endl;
    std::cout<<"The data of node1: "<<node1->data<<std::endl;
    std::cout<<"The data of node1 (*node1).data: "<<(*node1).data<<std::endl;
    std::cout<<"The next of node1: "<<node1->next<<std::endl;
    std::cout<<"The next of node1 (*node1).next: "<<(*node1).next<<std::endl;
    std::cout<<"The address of the node1: "<<node1<<std::endl;
    std::cout<<"The address of the node1 pointer: "<<&node1<<std::endl;
    std::cout<<std::endl;

    xray1Func(node1, node1);

    std::cout<<"\nAfter function call: "<<std::endl;
    std::cout<<"(after) The next of node1: "<<node1->next<<std::endl;
    std::cout<<"(after) The next of node1 (*node1).next: "<<(*node1).next<<std::endl;
}

void xray(Node* head){
    Node* current = head;
    while(current!=nullptr){
        std::cout<<"data: "<<current->data<<std::endl;
        std::cout<<"next address: "<<current->next<<std::endl;
        std::cout<<"address of the node: "<<current<<std::endl;
        std::cout<<std::endl;
        current = current->next;
    }
}

int main(){
    Node* head = new Node(100);
    xray(head);
    xray1();
    return 0;
}
