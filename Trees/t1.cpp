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

Node* buildBinaryTree(Node* root){
    int data;
    std::cout<<"Enter data: ";
    std::cin>>data;

    if(data==-1){
        return NULL;
    }
    
    root = new Node(data);

    std::cout<<"Insert data in the left of "<<data<<std::endl;
    root->left = buildBinaryTree(root->left);
    std::cout<<"Insert data in the right of "<<data<<std::endl;
    root->right = buildBinaryTree(root->right);

    return root;
}

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
        }else{
            std::cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

void averageLOT(Node* root){
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
        }else{
            std::cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }

    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<" ";
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    int ans = std::max(left, right) + 1;
    return ans;
}

std::pair<int, int> diameter(Node* root){
    if(root==NULL){
        std::pair<int, int> p = std::make_pair(0, 0);
        return p;
    }

    std::pair<int, int> left = diameter(root->left);
    std::pair<int, int> right = diameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    std::pair<int, int> ans;

    ans.first = std::max(op1, std::max(op2, op3));
    ans.second = std::max(left.second, right.second)+1;
    return ans;
}

void leafNodes(Node* root){
    if(root==NULL){
        return;
    }

    if(root->left==NULL && root->right==NULL){
        std::cout<<root->data<<" ";
    }

    leafNodes(root->left);
    leafNodes(root->right);
}

void sumOfLeftLeaves(Node* root){
    if(root==NULL){
        return;
    }

    if(root->left!=NULL && (root->left->left==NULL && root->left->right==NULL)){
        std::cout<<root->left->data<<" ";
    }

    sumOfLeftLeaves(root->left);
    sumOfLeftLeaves(root->right);
}

int checkHeight(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = checkHeight(root->left);
    if(left==-1) return -1;
    int right = checkHeight(root->right);
    if(right==-1) return -1;
    if(abs(left-right)>1) return -1;
    return std::max(left, right) +1;
}

bool isBalanced(Node* root){
    return checkHeight(root)!=-1;
}


int main(){
    Node* root = NULL;
    root = buildBinaryTree(root);

    std::cout<<"Preorder: "<<std::endl;
    preorder(root);

    std::cout<<"Leaf Nodes: "<<std::endl;
    sumOfLeftLeaves(root);

    return 0;
}