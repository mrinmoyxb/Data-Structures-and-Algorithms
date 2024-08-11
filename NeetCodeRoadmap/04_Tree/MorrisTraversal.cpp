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

//* go to the left and go to the right most node
vector<int> getInorder(Node* root){
    vector<int> inorder;
    Node* current = root;

    while(current!=NULL){
        if(current->left!=NULL){
            inorder.push_back(current->data);
            current = current->right;
        }
        else{
            Node* prev = current->left;
            while(prev->right && prev->right!=current){
                prev = prev->right;
            }
            if(prev->right==NULL){
                prev->right = current;
                current = current->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(current->data);
                current = current->right;
            }
        }
    }

    return inorder;
}

//* go to the left and go to the right most node
vector<int> getPreorder(Node* root){
    vector<int> preorder;
    Node* current = root;

    while(current!=NULL){
        if(current->left==NULL){
            preorder.push_back(current->data);
            current = current->right;
        }
        else{
            Node* prev = current->left;
            while(prev->right && prev->right!=current){
                prev = prev->right;
            }
            if(prev->right==NULL){
                prev->right = current;
                preorder.push_back(current->data);
                current = current->left;
            }
            else{
                prev->right = NULL;
                current = current->right;
            }
        }
    }

    return preorder;
}

int main(){

    return 0;
}