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

    cout<<"Enter the data in the right of "<<root->data<<" : ";
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

//* Approach 1: 

int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int diameterOfTree(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = diameterOfTree(root->left);
    int right = diameterOfTree(root->right);
    int combine = heightOfTree(root->left) + 1 + heightOfTree(root->right);
    int diameter = max(left, max(right, combine));

    return diameter;
}

//*************************************************************************************** */


//* Approach 2: 

pair<int, int> diameterOfBinaryTree(Node* root){
    if(root == NULL){
        pair<int, int> p  = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterOfBinaryTree(root->left);
    pair<int, int> right = diameterOfBinaryTree(root->right);
    
    int leftOption = left.first;
    int rightOption = right.first;
    int combine = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(leftOption, max(rightOption, combine));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root){
    return diameterOfBinaryTree(root).first;
}

int main(){
    Node* root = buildTree(root);
    cout<<"\nPreorder: "<<endl;
    preOrder(root);

    cout<<"\nDiameter: "<<diameterOfTree(root)<<endl;
    return 0;
}