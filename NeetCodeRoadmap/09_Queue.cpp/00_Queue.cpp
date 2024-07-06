#include <iostream>
#include <vector>
using namespace std;

class Queue{
    public:
    vector<int> queue;
    int size;
    int front = -1;
    int tail = -1;

    Queue(int size){
        this->size = size;
    }

    void enqueue(int data){
        if(front == -1 && tail == -1){
            front = 0;
            tail = 0;
            queue.push_back(data);
        }
        else if(size-tail>1){
            tail += 1;
            queue.push_back(data);
        }
        else{
            cout<<"\nQueue is full, can't insert "<<data<<endl;
        }
    }

    void dequeue(){
        if(front == -1){
            cout<<"\nQueue is empty"<<endl;
        }
        else{
            cout<<"Deleted element: "<<queue.front()<<endl;
            front++;
            if(front>tail){
                front = -1;
                tail = -1;
            }
        }
    }

    void display(){
        cout<<"Queue is: "<<endl;
        for(int i=front; i<queue.size(); i++){
            cout<<queue[i]<<" ";
        }
    }

};

int main(){

    // Queue q = Queue(5);
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);
    // q.enqueue(100);
    // q.display();

    // q.dequeue();
    // q.display();

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    int front1 = 0;
    int front2 = 2;

    cout<<"\nVec1: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\nTop: "<<v.front()<<endl;

    v.erase(v.begin()+front1);

    cout<<"\nVec1: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    v.erase(v.begin()+front2);

    cout<<"\nTop: "<<v.front()<<endl;

    cout<<"\nVec1: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    int front = 0;
    //int n =v[v.begin()];

    return 0;
}