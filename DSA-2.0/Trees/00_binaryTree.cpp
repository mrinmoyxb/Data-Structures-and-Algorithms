#include <iostream>
#include <queue>

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

Node* buildTree(){
    int data;
    std::cout<<"Enter data: ";
    std::cin>>data;
    Node* root = new Node(data);

    if(data==-1){
        return NULL;
    }
    
    std::cout<<"Enter data for insertion in the left of the "<<data<<std::endl;
    root->left = buildTree();
    std::cout<<"Enter data for insertion in the right of the "<<data<<std::endl;
    root->right = buildTree();

    return root;
}

//! Left -> Root -> Right
void inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    std::cout<<root->data<<" ";
    inorderTraversal(root->right);
}

//! Root -> Left -> Right
void preorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//! Left -> Right -> Root
void postorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout<<root->data<<" ";
}

//! Level Order Traversal
void levelOrderTraversal(Node* root){
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp==NULL){
            std::cout<<std::endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            std::cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = buildTree();
    std::cout<<"Preorder Traversal"<<std::endl;
    preorderTraversal(root);
    levelOrderTraversal(root);
    return 0;
}