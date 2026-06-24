#include <iostream>
#include <vector>
using namespace std;

int rows, cols;

int traverseGridBFS(vector<vector<int>>& grid, vector<vector<int>>& targets){
    int count = 0;
    for(auto& target: targets){
        int target_i = target[0];
        int target_j = target[1];

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        grid[0][0] = 1;

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int step = q.front().second;
            cout<<"{i: "<<i<<", j: "<<j<<"}"<<", step: "<<step<<endl;
            q.pop();

            if(i-1>=0 && grid[i-1][j]==0){
                grid[i-1][j]=1;
                if(i-1==target_i && j==target_j){
                    count+=step+1;
                    break;
                }
                q.push({{i-1, j}, step+1});
            }if(i+1<rows && grid[i+1][j]==0){
                grid[i+1][j]=1;
                if(i+1==target_i && j==target_j){
                    count+=step+1;
                    break;
                }
                q.push({{i+1, j}, step+1});
            }if(j-1>=0 && grid[i][j-1]==0){
                grid[i][j-1]=1;
                if(i==target_i && j-1==target_j){
                    count+=step+1;
                    break;
                }
                q.push({{i, j-1}, step+1});
            }if(j+1<cols && grid[i][j+1]==0){
                grid[i][j+1]=1;
                if(i==target_i && j+1==target_j){
                    count+=step+1;
                    break;
                }
                q.push({{i, j+1}, step+1});
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                grid[i][j] = 0;
            }
        }

        cout<<"Done with target!!!"<<endl;
        cout<<endl;
    }

    return count;
}

void traverseGridDFS(vector<vector<int>>& grid, int i, int j){
    if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]!=1) return;
    grid[i][j] = 0;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<grid[i][j]<<endl;
    }
    cout<<endl;

    cout<<"Down Direction: "<<endl;
    traverseGridDFS(grid, i+1, j);
    cout<<"Up Direction: "<<endl;
    traverseGridDFS(grid, i-1, j);
    cout<<"Right Direction: "<<endl;
    traverseGridDFS(grid, i, j+1);
    cout<<"Left Direction: "<<endl;
    traverseGridDFS(grid, i, j-1);
}

int main(){
    int n = 5;
    rows = 3, cols = 3;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<int>> grid1 = {{1, 1, 1}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> targets = {{2, 2}, {1, 3}};
    //cout<<"Minimum: "<<traverseGridBFS(grid, targets);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid1[i][j]==1){
                traverseGridDFS(grid1, i, j);
            }
        }
    }

    return 0;
}