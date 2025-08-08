#include <iostream>
#include <stack>
#include <queue>

class NodeChar{
    public:
    char data;
    NodeChar* left;
    NodeChar* right;
    NodeChar(char data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//! Build Tree
NodeChar* buildTree(NodeChar* root){
    int data;
    std::cout<<"Enter data: ";
    std::cin>>data;
    if(data==-1){
        return NULL;
    }

    std::cout<<"Enter data in the left of "<<data<<std::endl;
    root->left = buildTree(root->left);
    std::cout<<"Enter data in the right of "<<data<<std::endl;
    root->right = buildTree(root->right);

    return root;
}

//! Root -> Left -> Right
void display(NodeChar* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

//! Depth First Search 
void depthFirstSearch(NodeChar* root){
    std::cout<<"\nDepth First Search: "<<std::endl;
    std::stack<NodeChar*> result;
    NodeChar* rootNode = root;
    result.push(rootNode);

    while(!result.empty()){
        NodeChar* temp = result.top();
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

//! Breadth First Search
void breadthFirstSearch(NodeChar* root){
    std::cout<<"\nBreadth First Search: "<<std::endl;
    std::queue<NodeChar*> result;
    NodeChar* rootNode = root;
    result.push(rootNode);

    while(!result.empty()){
        NodeChar* temp = result.front();
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

//! Manual way of building tree:
//?             a
//?            / \
//?           b   c
//?          / \   \
//?         d   e   f

int main(){
    NodeChar* root = new NodeChar('a');
    NodeChar* b = new NodeChar('b');
    NodeChar* c = new NodeChar('c');
    NodeChar* d = new NodeChar('d');
    NodeChar* e = new NodeChar('e');
    NodeChar* f = new NodeChar('f');

    root->left = b;
    root->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    display(root);
    depthFirstSearch(root);
    breadthFirstSearch(root);

    return 0;
}