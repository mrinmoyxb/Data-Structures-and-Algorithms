#include <stdio.h>
#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;

void enqueu(int data){
    if((rear+1)%MAX == front){
        return;
    }
    if(front==-1){
        front = rear = 0;
    }else{
        rear = (rear+1)%MAX;
    }
    queue[rear] = data;
}

void dequeue(){
    if(front==-1){
        return;
    }

    if(front==rear){
        front = rear = -1;
    }else{
        front = (front+1)%MAX;
    }
}

void display(){
    int i = front;
    print("Queue");
    while(1){
        printf("%d", queue[i]);
        if(i==rear) break;
        i = (i+1)%MAX;
    }
}