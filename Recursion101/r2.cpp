#include <iostream>
#include <stack>

void insertElement(std::stack<int>& st, int data){
    if(st.empty()){
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();
    insertElement(st, data);
    st.push(temp);
}

void reverseStack(std::stack<int>& st){
    if(st.empty()) return;
    int top = st.top();
    st.pop();

    reverseStack(st);

    std::stack<int> temp;
    while(!st.empty()){
        int top = st.top();
        temp.push(top);
        st.pop();
    }
    st.push(top);
    while(!temp.empty()){
        int top = temp.top();
        st.push(top);
        temp.pop();
    }
}

void insertAtBottom(std::stack<int>& st, int data){
    if(st.empty()){
        st.push(data);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, data);
    st.push(top);
}

void reverseStackOptimised(std::stack<int>& st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

int main(){
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStackOptimised(s);

    while(!s.empty()){
        int top = s.top();
        s.pop();
        std::cout<<top<<std::endl;
    }

    return 0;
}