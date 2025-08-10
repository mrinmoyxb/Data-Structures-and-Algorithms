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

Node* buildTree(){
    int data;
    std::cout<<"Enter data: ";
    std::cin>>data;
    if(data==-1){
        return NULL;
    }

    Node* root = new Node(data);
    std::cout<<"Enter data in the left of "<<data<<std::endl;
    root->left = buildTree();
    
    std::cout<<"Enter data in the right of "<<data<<std::endl;
    root->right = buildTree();

    return root;
}

//! Number of nodes in a tree
int numberOfNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = numberOfNodes(root->left);
    int right = numberOfNodes(root->right);
    return left + right + 1;
}

//! Height of a tree: number of edges between root node and leaf node (the longest path)
int heightOfTree(Node* root){
    if(root==NULL){
        return -1;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return 1 + std::max(left, right);
}

//! Full Binary Tree/Proper Binary tree: Parent or internal node has either two or no children
bool isFullBinaryTree(Node* root){
    if(root==NULL){
        return true;
    }

    if(root->left == NULL && root->right ==NULL){
        return true;
    }

    if((root->left)&&(root->right)){
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    }
    return false;
}

int main(){
    Node* root = buildTree();
    // std::cout<<"\nnumber of nodes: "<<numberOfNodes(root)<<std::endl;
    // std::cout<<"\nheight of tree: "<<heightOfTree(root)<<std::endl;
    std::cout<<"Is the tree a full binary: "<<isFullBinaryTree(root)<<std::endl;
    return 0;
}