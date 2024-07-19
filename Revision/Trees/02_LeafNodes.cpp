#include <iostream>
#include <vector>
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


Node* buildTree(Node* &root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    if(data==-1){
        return root;
    }

    root = new Node(data);
    cout<<"Insert in the left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Insert in the right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void displayPreorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    displayPreorder(root->left);
    displayPreorder(root->right);
}

vector<int> leafNodes;

void printLeafNodes(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        leafNodes.push_back(root->data);
    }
    if(root->left){
        printLeafNodes(root->left);
    }
    if(root->right){
         printLeafNodes(root->right);
    }
}

int main(){
    Node* root = buildTree(root);
    cout<<"Preorder: "<<endl;
    displayPreorder(root);
    printLeafNodes(root);

    cout<<"\nLeaf Nodes: "<<endl;
    for(int i:leafNodes){
        cout<<i<<" ";
    }
    return 0;
}