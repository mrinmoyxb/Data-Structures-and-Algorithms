#include <iostream>
using namespace std;

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

Node* createNode(int data){
    Node* newNode = new Node(data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(Node* root){
    int data;
    cout<<"\nEnter data: ";
    cin>>data;

    root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Insert in left of "<<root->data<<" : ";
    root->left = buildTree(root->left);

    cout<<"Insert in right of "<<root->data<<" : ";
    root->right = buildTree(root->right);

    return root;
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){

    Node* root = buildTree(root);
    cout<<"Preorder: "<<endl;
    preOrder(root);
    inOrder(root);
    postOrder(root);

    return 0;
}