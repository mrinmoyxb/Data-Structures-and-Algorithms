#include <stdio.h>

int currSize=0;
const int cap = 5;
int front = 0, rear = -1;
int queue[cap];

void enqueue(int data){
    if(currSize==cap){
        printf("Circular queue is full");
        return;
    }

    rear = (rear+1)%cap;
    queue[rear] = data;
    currSize++;
}

void dequeue(){
    if(currSize==0){
        printf("Queue is empty");
        return;
    }

    front = (front+1)%cap;
    currSize--;
}

void show(){
    int count = currSize;
    int i = front;
    while(count > 0){
        printf("%d ", queue[i]);
        i = (i + 1) % cap;
        count--;
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
   
    show();
    dequeue();
    show();
    enqueue(8);
    show();

    return 0;
}