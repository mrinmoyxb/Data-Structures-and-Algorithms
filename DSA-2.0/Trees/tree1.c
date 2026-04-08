#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct Node* BinarySearchTree(struct Node* root, int data){
    if(root==NULL){
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(data < root->data){
        root->left = BinarySearchTree(root->left, data);
    }else if(data > root->data){
        root->right = BinarySearchTree(root->right, data);
    }

    return root;
}

struct Node* BinarySearchTree1(struct Node* root, int data){
    if(root==NULL){
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(data < root->data){
        root->left = BinarySearchTree1(root->left, data);
    }else if(data > root->data){
        root->right = BinarySearchTree1(root->right, data);
    }

    return root;
}

bool searchBST(struct Node* root, int key){
    if(root==NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(key > root->data){
        return searchBST(root->right, key);
    }else{
        return searchBST(root->left, key);
    }

    return false;
}

struct Node* getInorderSuccessor(struct Node* root){
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}

struct Node* deleteNodeBST(struct Node* root, int key){
    if(root==NULL){
        return NULL;
    }

    if(key > root->data){
        root->right = deleteNodeBST(root->right, key);
    }else if(key < root->data){
        root->left = deleteNodeBST(root->left, key);
    }

    else{
        if(root->left == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else {
            struct Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNodeBST(root->right, IS->data);
        }
    }

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
    struct Node* root = NULL;
    root = BinarySearchTree(root, 50);
    root = BinarySearchTree(root, 20);
    root = BinarySearchTree(root, 10);
    root = BinarySearchTree(root, 55);
    root = BinarySearchTree(root, 52);
    root = BinarySearchTree(root, 62);
    root = BinarySearchTree(root, 80);
    root = BinarySearchTree(root, 58);

    printf("\nInorder traversal: ");
    inorder(root);

    bool result = searchBST(root, 69);
    printf("\nResult: %d", result);
    return 0;
}