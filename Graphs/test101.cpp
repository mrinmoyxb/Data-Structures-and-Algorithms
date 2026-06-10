#include <iostream>
#include <vector>
#include <map>
using namespace std;

void check(){
    vector<vector<int>> v = {{1,1,0}, {1,1,0}, {0,0,1}};
    unordered_map<int, vector<int>> adj;
        int rows = v.size();
        int cols = v[0].size();

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(v[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        for(auto& value: adj){
            cout<<value.first<<" : ";
            for(auto& v: value.second){
                cout<<v<<" ";
            }
            cout<<endl;
        }
}


int main(){
    check();
    return 0;
}