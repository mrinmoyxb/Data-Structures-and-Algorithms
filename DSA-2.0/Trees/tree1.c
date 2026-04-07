#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createTree(){
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct Node* root = malloc(sizeof(struct Node));
    root->data = data;

    if(data==-1){
        return NULL;
    }

    printf("insertion in the left of: %d\n", root->data);
    root->left = createTree();
    printf("insertion in the right of: %d\n", root->data);
    root->right = createTree();

    return root;
}

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    struct Node* root = createTree();
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    return 0;
}