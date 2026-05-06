#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Stack{
    struct Node* data[100];
    int top;
};

void push(struct Stack* s, struct Node* node){
    if(s->top==99){
        printf("Stack overflow");
        return;
    }
    s->data[++s->top] = node;
}

struct Node* pop(struct Stack* s){
    if(s->top == -1){
        printf("Stack Underflow\n");
    }
    return s->data[s->top--];
}

int isEmpty(struct Stack *s){
    return s->top == -1;
}

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }

    struct Stack s;
    s.top = -1;

    push(&s, root);

    while(!isEmpty(&s)){
        struct Node* temp = pop(&s);
        printf("%d", temp->data);

        if(temp->right != NULL){
            push(&s, temp->right);
        }
        if(temp->left != NULL){
            push(&s, temp->left);
        }
    }
}

//! Create a binary tree:
struct Node* buildTree(){
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    if(data==-1){
        return NULL;
    }
    struct Node* root = malloc(sizeof(struct Node));
    root->data = data;

    printf("insertion in the left of: %d\n", root->data);
    root->left = buildTree();
    printf("insertion in the right of %d\n", root->data);
    root->right = buildTree();

    return root;
}

//! Inorder
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct Node* BinarySeachTree(struct Node* root, int data){
    if(root==NULL){
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(data < root->data){
        root->left = BinarySeachTree(root->left, data);
    }else if(data > root->data){
        root->right = BinarySeachTree(root->right, data);
    }

    return root;
}

int main(){
    struct Node* root = buildTree();
    printf("Inorder: ");
    inorder(root);
    return 0;
}