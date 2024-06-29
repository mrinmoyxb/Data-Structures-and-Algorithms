#include <iostream>
#include <stack>
using namespace std;

class Stack{
    public:
    int size;
    char *stack;
    int top;

    Stack(int size){
        this->size = size;
        stack = new char[this->size];
        top = -1;
    }

    void push(char data){
        if(top<size-1){
            top++;
            stack[top] = data;
        }
        else{
            cout<<"Stack Overflow, can't push "<<data<<endl;
        }
    }

    void pop(){
        if(top>-1){
            cout<<"Popped element is: "<<stack[top]<<endl;
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    void display(){
        cout<<"Stack is: "<<endl;
        for(int i=top; i>=0; i--){
            cout<<stack[i]<<endl;
        }
    }

    //* overloading [] 
    char& operator[](int index) {
    if (index >= 0 && index < size) {
        return stack[index];
    } else {
        throw std::out_of_range("Index out of bounds");
    }
}

};

int main(){
    string word = "abcd";
    cout<<"Word is: "<<word<<endl;
    
    Stack s = Stack(word.length());

    for(int i=0; i<word.length(); i++){
        char ch = word[i];
        s.push(ch);
    }

    string reverseWord = "";
    
    for(int i=s.top; i>=0; i--){
        char c = s[i];
        reverseWord.push_back(c);
        s.pop();
    }


    cout<<"Reverse word: "<<reverseWord<<endl;
    return 0;
}
