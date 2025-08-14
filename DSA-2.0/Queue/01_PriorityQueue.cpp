#include <iostream>

class Node{
    public:
    int data;
    int priority;
    Node* next;
    Node(int data, int priority){
        this->data = data;
        this->priority = priority;
        this->next = NULL;
    }
};

//! Priority = Low ranks has higher priority
class PriorityQueue{
    public:
    Node* head = NULL;
    Node* tail = NULL;

    //! here we add elements with the highest priority 
    void enqueue(int data, int priority){
        Node* newNode = new Node(data, priority);

        if(head==NULL){
            head = tail = newNode;
            return;
        }

        if(newNode->priority < head->priority){
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head->next;
        Node* prev = head;
        while(current!=NULL){
            if(newNode->priority < current->priority){
                newNode->next = current;
                prev->next = newNode;
                return;
            }else{
                prev = current;
                current = current->next;
            }
        }

        tail->next = newNode;
        tail = newNode;
    }

    //! remove the element of highest rank
    void dequeue(){
        Node* temp = head;
        std::cout<<"\ndeleted node: "<<std::endl;
        std::cout<<"data: "<<head->data<<std::endl;
        std::cout<<"priority: "<<head->priority<<std::endl;
        std::cout<<std::endl;
        head = head->next;
        delete temp;
        temp = NULL;
    }

    std::pair<int, int> peek(){
        std::pair<int, int> result = {head->data, head->priority};
        return result;
    }

    void display(){
        Node* current = head;
        while(current!=NULL){
            std::cout<<"Data: "<<current->data<<std::endl;
            std::cout<<"Priority: "<<current->priority<<std::endl;
            std::cout<<std::endl;
            current = current->next;
        }
    }

    ~PriorityQueue(){
        Node* current = head;
        while(current!=NULL){
            Node* forward = current->next;
            Node* temp = current;
            delete current;
            current = forward;
        }
    }
};

int main(){
    PriorityQueue p;
    p.enqueue(100, 4);
    p.enqueue(120, 3);
    p.enqueue(80, 6);
    p.enqueue(200, 1);
    p.display();
    
    p.dequeue();
    p.display();

    return 0;
}