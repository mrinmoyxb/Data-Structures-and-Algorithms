#include <iostream>
#include <stack>
using namespace std;

int evaluateExpression(string expr){
    stack<int> st;
    int n = expr.size();
    long long num = 0;
    char op = '+';
    
    for(int i=0; i<n; i++){
        if(isdigit(expr[i])){
            num = num*10 + (expr[i]-'0');
        }

        if((!isdigit(expr[i]) && expr[i]!=' ') ||
            i == expr.size()-1){
                if(op=='+') st.push(num);
                else if(op=='-') st.push(-num);
                else if(op=='*'){
                    int top = st.top();
                    st.pop();
                    st.push(top*num);
                }
                else if(op=='/'){
                    int top = st.top();
                    st.top();
                    st.push(top/num);
                }
                op = expr[i];
                num = 0;
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
}


void genExpr(string digits, vector<string>& res, string& expr, int index, vector<char>& vec, int target){
    if(index==digits.size()){
        if(evaluateExpression(expr)==target) res.push_back(expr);
        return;
    }

    for(char ch: vec){
        if(ch=='#'){
            expr.push_back(digits[index]);
            genExpr(digits, res, expr, index+1, vec, target);
            expr.pop_back();
        }else{
            expr.push_back(ch);
            expr.push_back(digits[index]);
            genExpr(digits, res, expr, index+1, vec, target);
            expr.pop_back();
            expr.pop_back();
        }
    }
}

int main(){
    string digits = "125";
    int target = 7;
    vector<char> v = {'+', '-', '*', '/', '#'};
    vector<string> res;
    string expr = "";
    expr.push_back(digits[0]);
    genExpr(digits, res, expr, 1, v, target);

    for(auto& st: res){
        cout<<st<<endl;
    }

    return 0;
}