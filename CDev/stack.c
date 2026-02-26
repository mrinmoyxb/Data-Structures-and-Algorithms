#include <stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(int data){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    
    top+=1;
    stack[top] = data;
}

void pop(){
    if(top==-1){
        printf("Stack underflow");
        return;
    }

    printf("Removed element is: %d", stack[top]);
    top+=1;
}

void peek(){
    if(top==-1){
        printf("Stack underflow");
        return;
    }

    printf("Top element: %d", stack[top]);
}

int size(){
    return top+1;
}

void display(){
    for(int i=top; i>=0; i--){
        printf("%d\n", stack[i]);
    }
}

int main(){
    push(1);
    push(2);
    push(3);

    display();
    int s = size();
    printf("Size of stack : %d", size());
    return 0;
}