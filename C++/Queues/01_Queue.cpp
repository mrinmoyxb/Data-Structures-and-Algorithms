#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int size;
    int front=-1, rear = -1;
    public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
    }

    void enqueue(int data){
        if(rear==size-1){
            cout<<"Queue is full"<<endl;
        }
        else{
            if(front==-1){
                front = 0;
            }
            rear = rear+1;
            arr[rear]=data;
        }
    }

    void dequeue(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Dequeued "<<arr[front]<<endl;
            front++;
            if(front>rear){
                front = -1;
                rear = -1;
            }
        }
    }

    void display(){
        cout<<"The queue is: "<<endl;
        for(int i=0; i<=rear; i++){
            cout<<arr[i]<<" ";
        }
    }

};

int main(){
    Queue q1 = Queue(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.display();
    return 0;
}