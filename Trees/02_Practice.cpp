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

//! Build tree
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

int max(int num1, int num2){
    return num1>num2 ? num1: num2;
}

//! Height of tree - Analysis
int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    std::cout<<"Root value: "<<root->data<<"\n";
    int left = heightOfTree(root->left);
    std::cout<<"Root value: "<<root->data<<"     Left: "<<left<<"\n";
    int right = heightOfTree(root->right);
    std::cout<<"Root value: "<<root->data<<"     Right: "<<right<<"\n";
    return max(left, right)+1;
}

//! Diameter of tree - Optimised
std::pair<int, int> diameterOfTree(Node* root){
    if(root==NULL){
        std::pair<int, int> p = std::make_pair(0, 0);
        return p;
    }
    std::pair<int, int> left = diameterOfTree(root->left);
    std::pair<int, int> right = diameterOfTree(root->right);

}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    std::cout<<"Inorder: "<<"\n";
    inorder(root);

    // std::cout<<"\nPreorder: "<<"\n";
    // preorder(root);

    // std::cout<<"\nPostorder: "<<"\n";
    // postorder(root);

    std::cout<<"\nHeight: \n"<<heightOfTree(root);
    //std::cout<<"Diameter: "<<diameterOfTree(root)<<"\n";

    return 0;
}