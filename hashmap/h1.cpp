#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
using namespace std;

void check()
{
    vector<vector<int>> m = {{1, 2}, {3, 4}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << m[j][i] << " ";
            cout << endl;
        }
    }
}

void insertAtEnd(stack<int> &st, int data)
{
    if (st.empty())
    {
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtEnd(st, data);
    st.push(temp);
}

void stackReverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int dt = st.top();
    st.pop();
    stackReverse(st);
    insertAtEnd(st, dt);
}

void a1()
{
    // string s = " 2-1 + 2 ";
    string s = "(1+(4+5+2)-3)+(6+8)";
    stack<int> st;
    stack<char> op;
    int count = 0;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            continue;
        }
        else
        {
            if (ch == '+' || ch == '-' || ch == '(' || ch == ')')
            {
                if (ch == ')')
                {
                    if (op.top() == '(')
                    {
                        op.pop();
                    }
                    else
                    {
                        while (op.top() != '(')
                        {
                            int top = st.top();
                            st.pop();
                            if (op.top() == '+')
                                count += top;
                            if (op.top() == '-')
                                count -= top;
                            op.pop();
                            st.push(count);
                        }
                        op.pop();
                    }
                }
                else
                {
                    op.push(ch);
                }
                continue;
            }
            if ((!op.empty() && isdigit(ch)) && !st.empty())
            {
                if (op.top() == '(')
                {
                    st.push(ch - '0');
                }
                else
                {
                    int top = st.top();
                    st.pop();
                    int num = ch - '0';
                    if (op.top() == '+')
                        count = top + num;
                    if (op.top() == '-')
                        count = top - num;
                    op.pop();
                    st.push(count);
                }
            }
            else
            {
                int num = ch - '0';
                st.push(num);
            }
        }
    }

    cout << "COUNT " << count << endl;
}

void a2()
{
    string s = " 2-1 + 2 ";
    // string s = "(1+(4+5+2)-3)+(6+8)";
    stack<int> st;
    stack<char> op;
    int count = 0;
    for (char ch : s)
    {
        if (ch == ' ')
        {
            continue;
        }
        else
        {
            if (ch == '+' || ch == '-')
            {
                op.push(ch);
                continue;
            }
            if ((!op.empty() && isdigit(ch)) && !st.empty())
            {
                std::cout << ch << std::endl;
                int top = st.top();
                st.pop();
                if (op.top() == '+')
                    count = top + (ch - '0');
                if (op.top() == '-')
                    count = top - (ch - '0');
                op.pop();
                st.push(count);
            }
            else
            {
                std::cout << ch << std::endl;
                st.push(ch - '0');
            }
        }
    }

    cout << "TOP " << st.top() << endl;
    cout << "COUNT " << count << endl;
}

void genSubarray()
{
    vector<int> v = {3, 1, 2, 4};
    int n = v.size();
    vector<int> mins;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            vector<int> v1;
            for (int k = i; k < j; k++)
            {
                v1.push_back(v[k]);
            }
            int num = *min_element(v1.begin(), v1.end());
            mins.push_back(num);
            ans.push_back(v1);
        }
    }

    for (auto v : ans)
    {
        for (int value : v)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    for (auto i : mins)
        cout << i << " ";

    int sum = accumulate(mins.begin(), mins.end(), 0);
    cout << sum << endl;
}

void check1()
{
    string s = "leet**cod*e";
    stack<char> st;
    for (char ch : s)
    {
        if (ch != '*')
            st.push(ch);
        else if (ch == '*')
        {
            st.pop();
        }
    }
    // while(!st.empty()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }
    string word = "";
    while (!st.empty())
    {
        char c = st.top();
        word += c;
        st.pop();
    }

    cout << word << endl;

    // reverse(word.begin(), word.end());
}

class Solution {
public:
    vector<int> nums = {42,11,1,97};

    int rev(int num){
        int sum = 0;
        while(num!=0){
            int rem = num%10;
            sum = sum*10 + rem;
            num/=10;
        }
        return sum;
    }

    void countNicePairs() {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int num = nums[i];
            int reversed = rev(num);
            int diff = num - reversed;
            mp[diff].push_back(i);
        }

        for(auto& m: mp){
            cout<<m.first<<" : ";
            for(auto num: m.second){
                cout<<num<<" ";
            }
            cout<<endl;
        }

        // int count = 0;
        // for(auto& m: mp){
        //     if(m.second.size()==2) count++;
        //     else continue;
        // }

        // return count;
    }
};

int main()
{
    Solution st;
    st.countNicePairs();

    return 0;
}
