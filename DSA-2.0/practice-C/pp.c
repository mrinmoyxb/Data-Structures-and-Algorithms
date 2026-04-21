#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int priority(char x){
    if(x=='(') return 0;
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    return 0;
}

void infp(char infix[], char postfix[]){
    int i=0, k=0;
    char ch;

    while((ch=infix[i++]!='\0')){
        if(isalnum(ch)){
            postfix[k++] = ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(stack[top]!='('){
                postfix[k++] = pop();
            }
            pop();
        }
        else{
            while(top!=-1 && priority(stack[top])>=priority(ch)){
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
}