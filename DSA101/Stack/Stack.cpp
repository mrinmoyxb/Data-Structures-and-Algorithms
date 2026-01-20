#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define MAX 5

int stack[MAX];
int top = -1;
int size = 5;

void push(int data){
    if(top<size-1){
        top++;
        stack[top]=data;
    }else{
        std::cout<<"Stack Overflow"<<std::endl;
    }
}

void pop(){
    if(top<0){
        
    }
}

int main(){
    return 0;
}