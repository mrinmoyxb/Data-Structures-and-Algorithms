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

    cout<<"Enter data in the left of "<<root->data<<" : ";
    root->left = buildTree(root->left);

    cout<<"Enter the data in the right of "<<root->data<<" : ";
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


//* Balanced Tree 

int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = heightOfTree(root->left);
    // int right = heightOfTree(root->right);
    // int ans = max(left, right);
    return left;
}

bool balancedTree(Node* root){
    if(root==NULL){
        return true;
    }

    int heightOfleft = heightOfTree(root->left);
    int heightOfright = heightOfTree(root->right);
    bool isBalanced = abs(heightOfleft - heightOfright)<= 1 ? true : false;
    return isBalanced;
}


int heightOfTreeleft(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = heightOfTree(root);
    // int right = heightOfTree(root->right);
    // int ans = max(left, right) + 1;
    return left;
}


int main(){

    Node* root = buildTree(root);

    cout<<"\nPreorder: "<<endl;
    preOrder(root);

    cout<<"\nIs tree balanced: "<<balancedTree(root)<<endl;

    cout<<"\nheightOfTree: "<<heightOfTreeleft(root->left)<<endl;

    return 0;
}