#include <stdio.h>
#define MAX 100

int size = 5;
int queue[MAX];
int front = -1, rear = -1;

int stack[MAX];
int top = -1;

void push(int data){
    if(top<size-1){
        top++;
        
    }
}

void enqueue(int data){
    if(front == -1){
        front+=1;
        rear+=1;
        queue[front] = data;
    }else{
        if(rear<size-1){
            rear+=1;
            queue[rear] = data;
        }else{
            printf("Queue is full");
        }
    }
}

int dequeue(){
    if(front==-1 && front > rear){
        printf("Queue is empty");
    }else{
        printf("Front %d", queue[front]);
        front+=1;
    }
}

void display(){
    for(int i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
}
