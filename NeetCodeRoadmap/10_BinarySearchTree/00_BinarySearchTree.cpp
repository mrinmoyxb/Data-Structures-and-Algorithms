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

Node* insertAtBST(Node* root, int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertAtBST(root->right, data);
    }
    else{
        root->left = insertAtBST(root->left, data);
    }
    return root;
}

void inputData(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertAtBST(root, data);
        cin>>data;
    }
}

int main(){
    
    Node* root = NULL;
    cout<<"Enter data to create BST: "<<endl;
    inputData(root);

    return 0;
}