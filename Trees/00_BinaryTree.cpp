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

Node* buildTree(Node* &root){
    int data;
    std::cout<<"Enter data: ";
    std::cin>>data;
    if(data==-1){
        return NULL;
    }
    root = new Node(data);

    std::cout<<"Enter data for inserting in left of "<<data<<" : "<<"\n";
    root->left = buildTree(root->left);
    std::cout<<"Enter data for inserting in the right of "<<data<<" : "<<"\n";
    root->right = buildTree(root->right);

    return root;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    
    return 0;
}