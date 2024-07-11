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

Node* buildTree(Node* root){
    int data;
    cout<<"\nEnter data: ";
    cin>>data;

    if(data==-1){
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

void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* current = q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
        q.pop();
    }
}

//* level order traversal
vector<vector<int>> levelOrder(Node* root){
    if(root==NULL){
        return {};
    }

    vector<vector<int> > vec;

    queue<Node*> q;
    q.push(root);
    vec.push_back({root->data});

    while(!q.empty()){
        Node* current = q.front();
        vec.push_back({current->data});
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
        q.pop();
    }
    return vec;
}

//* zig zag traversal
vector<int> zigZagTraversal(Node* root){
    if(root==NULL){
        return;
    }

    bool isLeftToRight = true;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.push(current);
        q.pop();

        if(isLeftToRight){
            isLeftToRight = false;
            if(current->right!=NULL){
                q.push(current->right);
            }
            if(current->left!=NULL){
                q.push(current->left);
            }
        }

        if(!isLeftToRight){
            isLeftToRight = true;
            if(current->left!=NULL){
                q.push(current->left);
            }
            if(current->right!=NULL){
                q.push(current->right);
            } 
        }


    }


    cout<<"\nZig Zag : "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
}

int main(){
    Node* root = buildTree(root);

    cout<<"\nPreorder: "<<endl;
    preOrder(root);

    zigZagTraversal(root);
    return 0;
}