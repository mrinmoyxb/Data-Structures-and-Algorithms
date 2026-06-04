#include <iostream>
#include <vector>
#include <map>
using namespace std;

// DFS - approach
// if a node is already visited then there's a cycle 
bool isCycleDFS(vector<vector<int>>& adj, int i, vector<bool>& visited, int parent){
    visited[i] = true;
    for(int& v: adj[i]){
        if(v==parent) continue;
        if(visited[v]) return true;
        if(isCycleDFS(adj, v, visited, i)){
            return true;
        }
    }
    return false;
}

// BFS - approach
bool isCycleBFS(vector<vector<int>>& adj, int i, vector<bool>& visited){
    queue<pair<int, int>> q;
    q.push({i, -1});
    visited[i] = true;

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        
        for(auto& v: adj[p.first]){
            if(visited[v]==false){
                visited[v] = true;
                q.push({v, p.first});
            }else if(v!=p.second){
                return true;
            }
        }

    }
    return false;
}



bool isCycle(vector<vector<int>>& adj){
    int nodes = adj.size();
    vector<bool> visited(nodes, false);
    for(int i=0; i<nodes; i++){
        if(!visited[i] && isCycleDFS(adj, i, visited, -1)){
            return true;
        }
    }
    return false;
}


int main(){
    vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    
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

    return 0;
}