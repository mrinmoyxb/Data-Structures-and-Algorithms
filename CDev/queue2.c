#include <stdio.h>

const int size = 5;
int queue[size];
int front = -1;
int rear = -1;

void enqueue(int data){
    if(front==-1 && rear==-1){
        front+=1;
        rear+=1;
        queue[rear] = data;
    }else{
        if(rear<size-1){
            rear+=1;
            queue[rear] = data;
        }else{
            printf("Queue is full\n");
        }
    }
}

void enqueuec(int data){
    if(rear==size-1){
        printf("Queue is full");
        return;
    }

    if(front==-1){
        front = 0;
    }

    rear+=1;
    queue[rear] = data;
}

void dequeue(){
    if(front==-1){
        printf("Queue is empty");
    }else{
        printf("\nRemoved element is: %d", queue[front]);
        front++;
    }
}

void show(){
    printf("\nQueue: \n");
    for(int i=front; i<rear+1; i++){
        printf("%d ", queue[i]);
    }
}

int main(){
    enqueue(100);
    enqueue(200);
    enqueue(300);
    enqueue(400);
    enqueue(500);
    show();

    dequeue();
    show();
    return 0;
}