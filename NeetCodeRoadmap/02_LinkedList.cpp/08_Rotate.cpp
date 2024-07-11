#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void display(Node* &head){
    cout<<"\nList: "<<endl;
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int lengthOfList(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

Node* rotate(Node* &head, int k){
    Node* temp = head;
    Node* prev = NULL;
    int count = lengthOfList(head);

    if(temp==NULL or temp->next==NULL){
        return temp;
    }
    else{
        k = k%count;
        while(k){
            while(temp->next!=NULL){
                prev = temp;
                temp = temp->next;
            }
            Node* lastNode = temp;
            prev->next = NULL;
            lastNode->next = head;
            head = lastNode;
            k--;
        }
        return head;
    }
    
}



int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    insertAtHead(head, 11);
    insertAtHead(head, 10);
    // cout<<"\nLength of linkd list: "<<lengthOfList(head)<<endl;
    // display(head);

    vector<int> v;
    v.push_back(100);
    v.push_back(2);
    v.push_back(40);
    v.push_back(5);

    cout<<"\nVec"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    sort(v.begin(), v.end());

    cout<<"\nVec"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    
    return 0;
}