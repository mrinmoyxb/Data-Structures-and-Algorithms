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

//! Height of a tree: 
//* 1. Number of edges between root node and leaf node (the longest path)
int heightOfTree(Node* root){
    if(root==NULL){
        return -1;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return std::max(left, right)+1;
}

//* 2. Number of nodes between root node and leaf node
int heightOfTreeNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = heightOfTreeNodes(root->left);
    int right = heightOfTreeNodes(root->right);
    return std::max(left, right)+1;
}

//! Diameter of tree: number of nodes on the longest path between two leaf nodes
int hoftree(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = hoftree(root->left);
    int right = hoftree(root->right);
    return std::max(left, right)+1;
}
int diameterOfTree(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = diameterOfTree(root->left);
    int right = diameterOfTree(root->right);
    int both = hoftree(root->left) + hoftree(root->right) + 1;
    return std::max(std::max(left, right), both);
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

//! Check balanced tree: difference between height of left and right subtree is not more than 1
bool isBalancedTree(Node* root){
    if(root==NULL){
        return true;
    }

    bool left = isBalancedTree(root->left);
    bool right = isBalancedTree(root->right);
    int diff = abs(hoftree(root->left) - hoftree(root->right))<=1;
    if(left && right && diff){
        return true;
    }else{
        return false;
    }
}

int main(){
    Node* root = buildTree();
    // std::cout<<"\nnumber of nodes: "<<numberOfNodes(root)<<std::endl;
    // std::cout<<"\nheight of tree: "<<heightOfTree(root)<<std::endl;
    // std::cout<<"Is the tree a full binary: "<<isFullBinaryTree(root)<<std::endl;
    // std::cout<<"Height(Nodes): "<<heightOfTreeNodes(root);
    // std::cout<<"Diameter: "<<diameterOfTree(root)<<std::endl;
    std::cout<<"is tree balanced: "<<isBalancedTree(root)<<std::endl;
    return 0;
}