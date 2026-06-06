#include <iostream>
#include <vector>
#include <map>
using namespace std;


bool isCyclic(unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion, int u){
    visited[u] = true;
    inRecursion[u] = true;
    for(int& v: adj[u]){
        if(visited[v] == false && isCyclic(adj, visited, inRecursion, v)) return true;
        else if(visited[v]==true && inRecursion[v]==true) return true;
    }

    inRecursion[u] = false;
    return false;
}

int main(){
    vector<vector<int>> graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    
    // data structure of adjacency list
    unordered_map<int, vector<int>> adj;
    int nodes = graph.size();
    for(int i=0; i<nodes; i++){
        for(auto v = graph[i].begin(); v!=graph[i].end(); v++){
            adj[i].push_back(*v);
        }
    }

    // printing the graph - adjacency list
    for(auto& it: adj){
        cout<<it.first<<" : ";
        for(auto& num: it.second){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    vector<bool> visited(nodes+1, false);
    vector<bool> inRecursion(nodes+1, false);

    for(int i=0; i<nodes; i++){
        if(!visited[i] && isCyclic(adj, visited, inRecursion, i)){
            return true;
        }
    }

    return 0;
}