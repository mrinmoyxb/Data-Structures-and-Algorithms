#include <iostream>
#include <set>
#include <stack>
using namespace std;

void addNum(stack<int>& st, int num){
    if(st.empty()){
        st.push(num);
        return;
    }
    int temp = st.top();
    st.pop();
    addNum(st, num);
    st.push(temp);
}

void reverseAStack(stack<int>& st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    reverseAStack(st);
    addNum(st, temp);
}

bool palindrome(int arr[], int i, int j){
    if(i>j) return true;
    if(arr[i]!=arr[j]) return false;
    return palindrome(arr, i+1, j-1);
}

bool palindrome1(string arr, int i, int j){
    if(i>j) return true;
    if(arr[i]!=arr[j]) return false;
    return palindrome1(arr, i+1, j-1);
}

int reverseNum(int num, int rev){
    if(num==0) return rev;
    rev = (rev*10)+(num%10);
    return reverseNum(num/10, rev);
}

bool palindrome2(int num){
    if(num<0) return false;
    int revNum = reverseNum(num, 0);
    return revNum==num;
}

void genK(vector<char>& chars, int k, string& s, vector<string>& str){
    if(s.size()==k){
        str.push_back(s);
        return;
    }

    for(char c: chars){
        s.push_back(c);
        genK(chars, k, s, str);
        s.pop_back();
    }
}

int myAtoi(string &s){
    int sign = 1, res = 0, idx = 0;
    while(idx < s.size() && s[idx]==' '){
        idx++;
    }
    if(idx < s.size() && s[idx]=='-' || s[idx]=='+'){
        if(s[idx]=='-'){
            sign = -1;
        }
        idx++;
    }
    while(idx < s.size() && s[idx]>='0' && s[idx]<='9'){
        if(res>INT_MAX / 10 || (res==INT_MAX/10 && s[idx]-'0'>7)){
            return sign == 1 ? INT_MAX: INT_MIN;
        }
        res = 10 * res + (s[idx++]-'0');
    }
    return res*sign;
}



int main(){
    // vector<char> chars = {'a', 'b', 'c'};
    // vector<string> str;
    // string current = "";
    // int k = 2;

    // genK(chars, k, current, str);
    // for(string word: str){
    //     cout<<word<<endl;
    // }
 
    return 0;
}