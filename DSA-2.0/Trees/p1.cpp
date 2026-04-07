#include <iostream>
#include <stack>
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

Node* createTree(){
    int data;
    std::cout<<"Enter data: ";
    std::cin>>data;
    Node* root = new Node(data);

    if(data==-1){
        return NULL;
    }

    std::cout<<"Enter the data in the left of "<<data<<std::endl;
    root->left = createTree();
    std::cout<<"Enter the data in the right of "<<data<<std::endl;
    root->right = createTree();

    return root;
}

void dfs(Node* root){
    if(root == NULL){
        return;
    }

    std::stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* current = st.top();
        st.pop();

        std::cout<<current->data<<" ";
        if(current->right) st.push(current->right);
        if(current->left) st.push(current->left);
    }
}

void dfs1(Node* root){
    if(root==NULL) return;

    std::stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* current = st.top();
        st.pop();

        std::cout<<current->data<<" ";

        if(current->right) st.push(current->right);
        if(current->left) st.push(current->left);
    }
}

void bfs(Node* root){
    if(root==NULL) return;

    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        std::cout<<current->data<<" ";
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}

int main(){
    return 0;
}