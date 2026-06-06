#include <iostream>
#include <vector>
using namespace std;

void check(){
    vector<vector<int>> v = {{0,1,0}, {1,0,0}, {0,0,0}};
    int rows = v.size();
    int cols = v[0].size();
    unordered_map<int, int> mp;
    vector<int> ans;
    for(int i=0; i<rows; i++){
        int sum = 0;
        for(int j=0; j<cols; j++){
            sum+=v[i][j];
        }
        ans.push_back(sum);
    }

    cout<<"Result: "<<endl;
    for(auto& v: ans){
        cout<<v<<endl;
    }

}


int main(){
    check();
    return 0;
}