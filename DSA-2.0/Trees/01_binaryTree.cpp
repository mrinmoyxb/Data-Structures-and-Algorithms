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

class NodeInt{
    public:
    int data;
    NodeInt* left;
    NodeInt* right;
    NodeInt(int data){
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

NodeInt* buildIntTree(){
    int data;
    std::cout<<"Enter data: ";
    std::cin>>data;
    NodeInt* root = new NodeInt(data);

    if(data==-1){
        return NULL;
    }

    std::cout<<"Enter data in the left of "<<data<<std::endl;
    root->left = buildIntTree();
    std::cout<<"Enter data in the right of "<<data<<std::endl;
    root->right = buildIntTree();
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

//! Depth First Search Using Recursion
void depthFirstSearchRecursion(NodeChar* root){
    if(root==NULL){
        return;
    }
    depthFirstSearchRecursion(root->right);
    depthFirstSearchRecursion(root->left);
    std::cout<<root->data<<" ";
}

//! Searching using Breadth First Search
void searchUsingBFS(NodeChar* root, char key){
    NodeChar* rootNode = root;
    std::queue<NodeChar*> result;
    result.push(rootNode);

    while(!result.empty()){
        NodeChar* temp = result.front();
        result.pop();
        if(temp->data == key){
            std::cout<<"Yes, "<<key<<" is available"<<std::endl;
            return;
        }

        if(temp->left){
            result.push(temp->left);
        }

        if(temp->right){
            result.push(temp->right);
        }
    }

    std::cout<<"No, "<<key<<" is not available"<<std::endl;
}

//! Search using Depth First Search
void searchUsingDFS(NodeChar* root, char key){
    NodeChar* rootNode = root;
    std::stack<NodeChar*> result;
    result.push(rootNode);

    while(!result.empty()){
        NodeChar* temp = result.top();
        result.pop();
        if(temp->data == key){
            std::cout<<"Yes, "<<key<<" is available"<<std::endl;
            return;
        }

        if(temp->left){
            result.push(temp->left);
        }

        if(temp->right){
            result.push(temp->right);
        }
    }
    std::cout<<"No, "<<key<<" is not available"<<std::endl;
}

int sumOfAllElements(NodeInt* root){
    if(root==NULL){
        return 0;
    }

    int left = sumOfAllElements(root->left);
    int right = sumOfAllElements(root->right);
    return left+right+root->data;
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

    // display(root);
    // depthFirstSearch(root);
    // breadthFirstSearch(root);
    // std::cout<<"\nBreadth first search using recursion: "<<std::endl;
    // breadthFirstSearch(root);
    
    // std::cout<<"\nSearch using BFS: "<<std::endl;
    // searchUsingBFS(root, 'd');

    // std::cout<<"\nSearch using DFS: "<<std::endl;
    // searchUsingDFS(root, 'd');

    NodeInt* rootInt = buildIntTree();
    std::cout<<"sum of all elements: "<<sumOfAllElements(rootInt);
    return 0;
}