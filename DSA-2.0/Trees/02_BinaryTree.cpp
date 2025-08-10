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

int numberOfNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = numberOfNodes(root->left);
    int right = numberOfNodes(root->right);
    return left + right + 1;
}

int main(){
    Node* root = buildTree();
    std::cout<<"number of nodes: "<<numberOfNodes(root)<<std::endl;
    return 0;
}