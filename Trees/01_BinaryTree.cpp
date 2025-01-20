#include <iostream>

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
    std::cout<<"Enter data: ";
    std::cin>>data;
    if(data==-1){
        return NULL;
    }

    root = new Node(data);

    std::cout<<"Insert in the left of "<<data<<"\n";
    root->left = buildTree(root->left);
    std::cout<<"Insert in the right of "<<data<<"\n";
    root->right = buildTree(root->right);

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

int max(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}

//! Height of tree - Analysis
int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    std::cout<<"Root value: "<<root->data<<"\n";
    int left = heightOfTree(root->left);
    std::cout<<"Root value: "<<root->data<<"     Left: "<<left<<"\n";
    int right = heightOfTree(root->right);
    std::cout<<"Root value: "<<root->data<<"     Right: "<<right<<"\n";
    return max(left, right)+1;
}

//! Diameter of tree - Optimised
//! pair<diameter, height>
std::pair<int, int> diameterOfTree(Node* root){
    if(root==NULL){
        std::pair<int, int> p = std::make_pair(0, 0);
        return p;
    }
    std::pair<int, int> left = diameterOfTree(root->left);
    std::pair<int, int> right = diameterOfTree(root->right);

    int op1 = left.first; // diameter of left subtree
    int op2 = right.first; // diameter of right subtree
    int op3 = left.second + right.second + 1; // left height + right height + 1

    std::pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root){
    std::pair<int, int> result = diameterOfTree(root);
    return result.first;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    std::cout<<"Inorder: ";
    inorder(root);

    //std::cout<<"\nHeight of tree: "<<heightOfTree(root);
    std::cout<<"\nDiameter of tree: "<<diameter(root);
    return 0;
}