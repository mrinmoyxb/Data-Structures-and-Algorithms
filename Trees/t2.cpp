#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

std::vector<int> verticalOrder(Node* root){
    std::map<int, std::map<int, std::vector<int>>> nodes;
    std::queue<std::pair<Node*, std::pair<int, int>>> q;
    std::vector<int> ans;

    if(root==NULL){
        return ans;
    }

    q.push(std::make_pair(root, std::make_pair(0, 0)));

    while(!q.empty()){
        std::pair<Node*, std::pair<int, int>> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
    }

    for(auto i: nodes){
        for(auto j:i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
}

std::vector<vector<int>> vertical(Node* root){
    vector<vector<int>> ans;
    queue<pair<Node*, int>> q;
    map<int, vector<int>> m;
    q.push({root, 0});

    vector<int> result;

    while(!q.empty()){
        auto temp = q.front();
        Node* frontNode = temp.first;
        int hd = temp.second;
        q.pop();

        m[hd].push_back(frontNode->data);

        if(frontNode->left){
            q.push({frontNode->left, hd-1});
        }
        if(frontNode->right){
            q.push({frontNode->right, hd+1});
        }
    }

    for(auto i: m){
        ans.push_back(i.second);
    }

    return ans;
}


int main(){
    return 0;
}