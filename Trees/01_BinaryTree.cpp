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

    std::cout<<"Insert in the left of "<<data<<"\n";
    root->left = buildTree(root->left);
    std::cout<<"Insert in the right of "<<data<<"\n";
    root->right = buildTree(root->right);

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

int max(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}

int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return max(left, right)+1;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    std::cout<<"Inorder: ";
    inorder(root);

    std::cout<<"\nHeight of tree: "<<heightOfTree(root);
    return 0;
}