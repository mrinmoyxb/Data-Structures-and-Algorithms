#include <iostream>
#include <queue>

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

//! build tree
Node* buildTree(Node* root){
    int data;
    std::cout<<"\nEnter data: ";
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

//! inorder
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}

//! level order traversal
void levelOrderTraversal(Node* root){
    std::queue<Node*> Q;
    Q.push(root);
    while(Q.empty()){
        Node* current = Q.front();
        std::cout<<current->data<<" ";
        if(current->left!=NULL){
            Q.push(current->left);
        }
        if(current->right!=NULL){
            Q.push(current->right);
        }
        Q.pop();
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    return 0;
}