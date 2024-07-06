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


Node* buildTree(Node* root){
    int data;
    cout<<"\nEnter data: ";
    cin>>data; 

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"Insert in the left of "<<root->data;
    root->left = buildTree(root->left);

    cout<<"Insert in the right of "<<root->data;
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


int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    int maxHeight = max(left, right)+1;
    return maxHeight;
}

int main(){

    Node* root = buildTree(root);
    cout<<"Preorder: "<<endl;
    preOrder(root);

    cout<<"\nHeight of tree: "<<heightOfTree(root)<<endl;
    return 0;
}