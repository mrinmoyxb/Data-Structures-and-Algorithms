#include <iostream>

//! Palindrome
//* Approach 1
int reverseNumRec(int num, int rev = 0){
    if(num==0){
        return rev;
    }

    return reverseNumRec(num/10, (rev*10)+(num%10));
}

bool isPalindrome(int num){
    if(num<0){
        return false;
    }
    return num == reverseNumRec(num);
}

//* Approach 2
bool isPalindromeStringApproach(std::string str, int start, int end){
    if(start>=end){
        return true;
    }

    if(str[start]!=str[end]){
        return false;
    }
    return isPalindromeStringApproach(str, start+1, end-1);
}

bool isPalindromeCheck(int n){
    std::string num = std::to_string(n);
    return isPalindromeStringApproach(num, 0, num.length()-1);
}

//! Print a string in reverse
void revString(std::string& s, int start, int end){
    if(start>end){
        return;
    }
    std::swap(s[start], s[end]);
    revString(s, start+1, end-1);
}

//! Reverse a stack
void reverseStack(std::stack<int>& st){
    if(st.empty()){
        return;
    }

    int top = st.top();
    st.pop();
    reverseStack(st);
    std::stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    st.push(top);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

//! insertion at bottom of stack
void bottomOfStack(std::stack<int>& st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int item = st.top();
    st.pop();
    bottomOfStack(st, element);
    st.push(item);
}

//! Reverse a stack
void reverseStack1(std::stack<int>& st){
    if(st.empty()){
        return;
    }
    
    int top = st.top();
    st.pop();
    reverseStack1(st);
    std::cout<<"Current status of stack: "<<std::endl;
    std::cout<<"Is stack empty ?: "<<st.empty()<<std::endl;
    bottomOfStack(st, top);
}

void printStack(std::stack<int> st){
    std::cout<<"Stack: "<<std::endl;
    while(!st.empty()){
        std::cout<<st.top()<<std::endl;
        st.pop();
    }
}

int main(){
    std::stack<int> st;
    st.push(2);
    st.push(3);
    st.push(4);

    printStack(st);
    
    reverseStack1(st);

    printStack(st);
    
    return 0;
}