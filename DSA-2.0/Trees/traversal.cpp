#include <iostream>
#include <queue>
#include <stack>

//! Depth First Search: Stack
//* Preorder Traversal
//* Inorder Traversal
//* Postorder Traversal

//! Breadth First Search: Queue
//* Level Order Traversal

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

    if(data==-1){
        return NULL;
    }

    Node* root = new Node(data);
    std::cout<<"Enter data in the left of "<<data<<std::endl;
    root->left = buildTree();
    std::cout<<"Enter data in the right of "<<data<<std::endl;
    root->right = buildTree();
    return root;
}

//! Preorder = Root -> Left -> Right
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//! Postorder = Left -> Right -> Root
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<" ";
}

//! Inorder = Left -> Root -> Right
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}

//! DFS - Depth First Search
void depthFirstSearch(Node* root){
    std::cout<<"Depth First Search: "<<std::endl;
    Node* rootNode = root;
    std::stack<Node*> result;
    result.push(rootNode);

    while(!result.empty()){
        Node* temp = result.top();
        result.pop();
        std::cout<<temp->data<<" ";

        if(temp->right){
            result.push(temp->right);
        }

        if(temp->left){
            result.push(temp->left);
        }
    }
}

//! BFS - Breadth First Search
void breadthFirstSearch(Node* root){
    std::cout<<"Breadth First Search: "<<std::endl;
    Node* rootNode = root;
    std::queue<Node*> result;
    result.push(rootNode);

    while(!result.empty()){
        Node* temp = result.front();
        result.pop();
        std::cout<<temp->data<<" ";

        if(temp->left){
            result.push(temp->left);
        }
        if(temp->right){
            result.push(temp->right);
        }
    }
}

//! DFS using recursion
void dfsRecursion(Node* root){
    if(root==NULL){
        return;
    }

    std::cout<<root->data<<" ";
    dfsRecursion(root->left);
    dfsRecursion(root->right);
}

//! Level Order Traversal
void levelOrderTraversal(Node* root){
    Node* rootNode = root;
    std::queue<Node*> result;
    result.push(rootNode);

    while(!result.empty()){
        Node* temp = result.front();
        result.pop();
        std::cout<<temp->data<<" ";
        
        if(temp->left){
            result.push(temp->left);
        }

        if(temp->right){
            result.push(temp->right);
        }
    }
}

int main(){
    Node* root = buildTree();
    // breadthFirstSearch(root);

    // std::cout<<"\nBreadth First Search Using Recursion: "<<std::endl;
    // dfsRecursion(root);

    // std::cout<<"\nDepth First Search: "<<std::endl;
    // depthFirstSearch(root);

    std::cout<<"\nLevel Order Traversal: "<<std::endl;
    levelOrderTraversal(root);
    return 0;
}