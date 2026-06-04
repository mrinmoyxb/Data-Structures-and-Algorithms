#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void adjacencyMatrix(){
    vector<vector<int>> arr = {{1}, {0, 2}, {1, 3}, {2}};
    int n = arr.size();
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(auto& v: arr[i]){
            adjMatrix[i][v] = 1;
        }
    }

    cout<<"Adjacency Matrix: "<<endl;
    for(auto& row: adjMatrix){
        for(auto& value: row){
            cout<<value<<" ";
        }
        cout<<endl;
    }
}

void adjacencyList(){
    unordered_map<int, vector<int>> adjList;
    vector<vector<int>> arr = {{1}, {0, 2}, {1, 3}, {2}};
    for(int i=0; i<arr.size(); i++){
        for(auto& value: arr[i]){
            adjList[i].push_back(value);
        }
    }

    cout<<"Adjacency List: "<<endl;
    for(auto v = adjList.begin(); v!=adjList.end(); v++){
        cout<<v->first<<" : ";
        for(int& value: (*v).second){
            cout<<value<<" ";
        }
        cout<<endl;
    }
}

int main(){
    adjacencyMatrix();
    adjacencyList();
    return 0;
}