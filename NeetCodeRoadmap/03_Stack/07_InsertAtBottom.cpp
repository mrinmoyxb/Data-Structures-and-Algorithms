#include <iostream>
#include <stack>
using namespace std;

//* Approach 1:
void insertAtBottom1(stack<int> &s, int count, int size, int value){
    if(count==size-1){
        s.push(value);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom1(s, count+1, size, value);
    s.push(num);
}


//* Approach 2:
void insertAtBottom2(stack<int> &s, int value){
    if(s.empty()){
        s.push(value);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom2(s, value);
    s.push(num);
}

int main(){
    stack<int> s;
    int size = 5;
    int count = 0;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    stack<int> s1 = s;

    cout<<"Before: "<<endl;
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }

    insertAtBottom1(s, count, size, 99);

    stack<int> &s2 = s;

    cout<<"\nAfter: "<<endl;
    while(!s2.empty()){
        cout<<s2.top()<<endl;
        s2.pop();
    }

    return 0;
}