#include <iostream>
using namespace std;

class LinkedList{
    public:
    int data;
    LinkedList* next;
    LinkedList(int data){
        this->data = data;
        this->next = NULL;
    }
};

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


Node* buildTree(Node* &root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    if(data==-1){
        return root;
    }

    root = new Node(data);
    cout<<"Insert in the left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Insert in the right of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void displayPreorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    displayPreorder(root->left);
    displayPreorder(root->right);
}

LinkedList* flatten(Node* root){
    if(root==NULL){
        return NULL;
    }
    LinkedList* newNode = new LinkedList(root->data);
    newNode = flatten(root->left);
    newNode = flatten(root->right);
    return newNode;
}

void display(LinkedList* node){
    cout<<"\nLinkedList: "<<endl;
    LinkedList* current = node;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* root = buildTree(root);

    cout<<"Preorder: "<<endl;
    displayPreorder(root);

    LinkedList* node = flatten(root);
    display(node);

    return 0;
}