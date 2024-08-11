#include <iostream>
#include <queue>
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

Node* BuildTree(Node* root){
    int data;
    cout<<"\nEnter the data: ";
    cin>>data;
    root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Insert in left of "<<data<<endl;
    root->left = BuildTree(root->left);
    cout<<"Insert in right of "<<data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

Node* insertDataAtTree(Node* root){
    int data;
    cout<<"\nEnter the data: "<<endl;
    cin>>data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data in the left of "<<data<<endl;
    root->left = BuildTree(root->left);
    cout<<"Enter data in the right of "<<data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int calNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = calNodes(root->left);
    int right = calNodes(root->right);
    return left+right+1;
}

int main(){
    Node* root = BuildTree(root);
    cout<<"\nInorder: "<<endl;
    inorder(root);
    cout<<"\nPreorder: "<<endl;
    preorder(root);

    cout<<"\n Nodes: "<<calNodes(root);
    return 0;
}