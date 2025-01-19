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
Node* buildTree(Node* &root){
    int data;
    std::cout<<"Enter data: ";
    std::cin>>data;
    if(data==-1){
        return NULL;
    }
    root = new Node(data);

    std::cout<<"Insert in left of "<<data<<" : "<<"\n";
    root->left = buildTree(root->left);
    std::cout<<"Insert in the right of "<<data<<" : "<<"\n";
    root->right = buildTree(root->right);

    return root;
}

//! Inorder: Left -> Node -> Right
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}

//! Preorder: Node->Left->Right
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//! Postorder: Left->Right->Node
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<" ";
}

void customBuildTree(){
    //! Three nodes: node, leftNode, rightNode
    Node* root = new Node(10);
    Node* leftNode = new Node(20);
    Node* rightNode = new Node(30);

    root->left = leftNode;
    root->right = rightNode;

    Node* leftNodeLeft = NULL;
    Node* leftNodeRight = NULL;
    Node* rightNodeLeft = NULL;
    Node* rightNodeRight = NULL;

    leftNode->left = leftNodeLeft;
    leftNode->right = leftNodeRight;

    rightNode->left = rightNodeLeft;
    rightNode->right = rightNodeRight;
    
    std::cout<<"Inorder: "<<"\n";
    inorder(root);
    std::cout<<"\nPreorder: "<<"\n";
    preorder(root);
    std::cout<<"\nPostorder: "<<"\n";
    postorder(root);
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    std::cout<<"Preorder: "<<"\n";
    preorder(root);

    std::cout<<"\nInorder: "<<"\n";
    inorder(root);

    std::cout<<"\nPostorder: "<<"\n";
    postorder(root);
    
    return 0;
}