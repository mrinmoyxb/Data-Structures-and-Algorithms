#include <stdio.h>
#define MAX 100

int stack[MAX];
int size;
int top = -1;

void push(int data){
    if(top<size-1){
        top+=1;
        stack[top] = data;
    }else{
        printf("\nStack Overflow, can't push %d", data);
    }
}

void pop(){
    if(top==-1){
        printf("\nStack Underflow");
    }else{
        printf("\nPopped element is: %d\n", stack[top]);
        top--;
    }
}

void display(){
    printf("\nStack: \n");
    for(int i=top; i>=0; i--){
        printf("%d\n", stack[i]);
    }
}

int main(){
    printf("Enter size: ");
    scanf("%d", &size);

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    display();

    pop();

    display();
    return 0;
}