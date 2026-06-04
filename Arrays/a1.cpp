#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//ttext-label-1 dark:text-dark-label-1 font-medium

void check1(){
    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // 1 2 3 4
    // 5 6 7 8
    // 9 10 11 12
    int rows = v.size(); // 3
    int columns = v[0].size(); // 3

    // 1 2 3
    for(int i=0; i<1; i++){
        for(int j=0; j<columns; j++){
            cout<<v[i][j]<<" ";
        }
    }

    // 6
    for(int i=1; i<=rows-2; i++){
        for(int j=columns-1; j<=columns-1; j++){
            cout<<v[i][j]<<" ";
        }
    }

    // 7 8 9
    for(int i=rows-1; i<rows; i++){
        for(int j=columns-1; j>=0; j--){
            cout<<v[i][j]<<" ";
        }
    }

    // 4 5
    for(int i=1; i<=rows-2; i++){
        for(int j=0; j<columns-1; j++){
            cout<<v[i][j]<<" ";
        }
    }
}

void check(){
    string str = "ccaab";
    sort(str.begin(), str.end());
    cout<<str<<endl;
}

bool check2(){
    string str = ")()";
    int n = str.size();
    int i = 0;
    stack<char> st;
    
    while(i<n){
        if(str[i]==')' && !st.empty()){
            if(st.top()=='(') st.pop();
            i++;
        }else{
            st.push(str[i]);
            i++;
        }
    }
    return st.empty();
}

// k = k % len(nums)
void check4(){
    vector<int> v = {1, 2, 3, 4};
    int k = 3;

    
    int index = v.size()-1;

    for(int i=0; i<k; i++){
        int count = 1;
        int temp = v[v.size()-count];
        cout<<"temp: "<<temp<<endl;

        for(int i=index; i>=1; i--){
            v[i] = v[i-1];
        }
        v[0] = temp;
        for(auto& i: v){
            cout<<i<<" ";
        }

        count++;
    }
    
}

int main(){
    check4();

    return 0;
}