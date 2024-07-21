#include <iostream>
#include <vector>
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

Node* buildTree(Node* &root){
    int data;
    cout<<"\nEnter data: ";
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root = new Node(data);
    cout<<"Insert at the left of "<<root->data<<" ";
    root->left = buildTree(root->left);
    cout<<"Inset at the right of "<<root->data<<" ";
    root->right = buildTree(root->right);

    return root;
}

//* PREORDER TRAVERSAL
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//* INORDER TRAVERSAL
void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//* POSTORDER TRAERSAL
void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//* LEVEL ORDER TRAVERSAL
vector<int> levelOrder(Node* root){
    if(root==NULL){
        return {};
    }

    vector<int> vec;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        vec.push_back({current->data});
        q.pop();
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
    return vec;
}

//* ALL LEAF NODES:
void leafNodes(Node* root){
    if(root==NULL){
        return;
    }
    if(!root->left && !root->right){
        cout<<root->data<<" ";
    }
    leafNodes(root->left);
    leafNodes(root->right);
}

int main(){
    Node* root = buildTree(root);
    cout<<"\nPreorder: "<<endl;
    preOrder(root);

    cout<<"\nPostorder: "<<endl;
    postOrder(root);

    cout<<"\nInorder: "<<endl;
    inOrder(root);

    cout<<"\nLeaf Nodes are: "<<endl;
    leafNodes(root);

    cout<<"\nLevel Order Traversal: "<<endl;
    vector<int> v;
    v = levelOrder(root);
    for(int i: v){
        cout<<i<<" ";
    }
    return 0;
}