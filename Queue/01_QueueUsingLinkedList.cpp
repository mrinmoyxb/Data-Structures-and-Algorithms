#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    public:
    int size;
    Node* queue;
    Node* current;

    Queue(int size){
        this->size = size;
        queue = NULL;
        current = NULL;
    }

    //! Enqueue
    void enqueue(int data){
        if(queue==NULL){
            queue = new Node(data);
            current = queue;
            size-=1;
        }else{
            if(size!=0){
                Node* newNode = new Node(data);
                current->next = newNode;
                current = current->next;
                size-=1;
            }else{
                std::cout<<"\nQueue is full"<<"\n";
            }
        }
    }

    //! Dequeue
    void dequeue(){
        if(queue==NULL){
            std::cout<<"Queue is empty"<<"\n";
        }else{
            std::cout<<"\nDeleted element: "<<queue->data<<"\n";
            Node* delNode = queue;
            queue = queue->next;
            delete delNode;
            size+=1;
        }
    }

    //! Printing queue
    void display(){
        Node* current = queue;
        while(current!=NULL){
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    //! is queue empty
    bool isEmpty(){
        if(queue==NULL){
            return true;
        }else{
            return false;
        }
    }

    //! is queue full
    bool isFull(){
        if(size==0){
            return true;
        }else{
            return false;
        }
    }

    //! peek of queue
    int peek(){
        return queue->data;
    }

    //! Reverse
    Node* reverse(){
        if(queue==NULL){
            return NULL;
        }else{
            Node* prev;
            Node* current = queue;
            Node* forward;
            while(current!=NULL){
                forward = current->next;
                current->next = prev;
                prev = current;
                current = forward;
            }
            return prev;
        }
    }
};

int main(){
    Queue* q = new Queue(5);
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);

    q->display();

    std::cout<<"\nPeek element in the queue: "<<q->peek()<<"\n";
    q->enqueue(60);
    std::cout<<"Is queue empty: "<<q->isEmpty()<<"\n";
    std::cout<<"Is queue full: "<<q->isFull()<<"\n";
    q->dequeue();
    std::cout<<"Is queue empty: "<<q->isEmpty()<<"\n";
    std::cout<<"Is queue full: "<<q->isFull()<<"\n";
    std::cout<<"Peek element: "<<q->peek()<<"\n";


    return 0;
}