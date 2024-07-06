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
        this->right =NULL;
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

    cout<<"Enter data in the right of "<<root->data<<" : ";
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

bool identicalTrees(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }

    if(root1==NULL && root2!=NULL){
        return false;
    }

    if(root1!=NULL && root2==NULL){
        return false;
    }

    bool left = identicalTrees(root1->left, root2->left);
    bool right = identicalTrees(root1->right, root2->right);
    bool data = root1->data == root2->data;

    if(left && right && data){
        return true;
    }
    else{
        return false;
    }


}

int main(){
    Node* root1 = buildTree(root1);
    cout<<"\nPreOrder: "<<endl;
    preOrder(root1);

    Node* root2 = buildTree(root2);
    cout<<"\nPreOrder: "<<endl;
    preOrder(root2);


    cout<<"\nIdentical: "<<identicalTrees(root1, root2);

    return 0;
}