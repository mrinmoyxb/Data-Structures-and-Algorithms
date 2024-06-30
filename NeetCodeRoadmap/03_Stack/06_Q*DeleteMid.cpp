#include <iostream>
#include <stack>
using namespace std;

void deleteMidElement(stack<int>&s, int count, int size){

    if(count==size/2){
        s.pop();
        return;
    }
    
    cout<<"count: "<<count<<endl;
    int num = s.top();
    cout<<"num: "<<num<<endl;
    s.pop();
    deleteMidElement(s, count+1, size);
    s.push(num);
}

int main(){

    stack<int> s1;
    int size = 5;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    stack<int> scopy = s1;
    
    cout<<"Before: "<<endl;
    while(!scopy.empty()){
        cout<<scopy.top()<<endl;
        scopy.pop();
    }

    deleteMidElement(s1, 0, 5);
    
    stack<int> &s2 = s1;

    cout<<"\nAfter: "<<endl;
    while(!s2.empty()){
        cout<<s2.top()<<endl;
        s2.pop();
    }

    return 0;
}