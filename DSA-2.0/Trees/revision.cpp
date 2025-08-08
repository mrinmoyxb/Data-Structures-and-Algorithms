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
    std::cout<<"Enter data: "<<std::endl;
    std::cin>>data;
    Node* root = new Node(data);

    if(data==-1){
        return NULL;
    }

    std::cout<<"Enter data in the left of "<<data<<std::endl;
    root->left = buildTree();
    std::cout<<"Enter data in the right of "<<data<<std::endl;
    root->right = buildTree();

    return root;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<" ";
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root = buildTree();
    std::cout<<"Preorder: "<<std::endl;
    preorder(root);

    std::cout<<"Postorder: "<<std::endl;
    postorder(root);
    
    std::cout<<"Inorder: "<<std::endl;
    inorder(root);

    return 0;
}