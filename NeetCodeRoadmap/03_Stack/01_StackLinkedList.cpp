#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"Destructor called"<<endl;
    }
};

class Stack{
    public: 
    int size;
    int top = -1;
    Node* head = 0;
    
    Stack(int size, int data){
        this->size = size;
        Node* newNode = new Node(data);
        head = newNode;
        top++;
    }

    void push(int data){
        if(top<size-1){
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            top++;
        }
        else{
            cout<<"Stack Overflow, can't push "<<data<<endl;
        }
    }

    void pop(){
        if(top>-1){
            cout<<"Popped element: "<<head->data<<endl;
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            top--;
        }
        else{
            cout<<"Stack Underflow" <<endl;
        }

    }

    void display(){
        cout<<"Linked list: "<<endl;
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }

    void topElement(){
        cout<<"Top element: "<<head->data<<endl;
    }

    void numberOfElements(){
        int count = 0;
        Node* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        cout<<"Count: "<<count<<endl;
    }

};

int main(){
    Stack s = Stack(5, 10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(100);
    s.display();
    s.topElement();

    s.pop();
    s.display();
    s.topElement();
    return 0;
}