#include <iostream>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    std::cout<<"Enter data: ";
    std::cin>>data;
    if(data==-1){
        return NULL;
    }
    root = new Node(data);
    std::cout<<"Insert in the left of "<<data;
    root->left = buildTree(root->left);
    std::cout<<"Insert in the right of "<<data;
    root->right = buildTree(root->right);

    return root;
}

//! Root -> Left -> Right
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//! Left -> Root -> Right
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}

//! Left -> Right -> Root
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<" ";
}


int main(){
    return 0;
}