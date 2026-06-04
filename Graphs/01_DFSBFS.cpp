#include <iostream>
using namespace std;

void DFS(unordered_map<int, vector<int>>& adj, int u, vector<int>& result, vector<bool>& visited){
    if(visited[u]) return;
    visited[u] = true;
    result.push_back(u);

    for(auto& v: adj[u]){
        if(!visited[v]){
            DFS(adj, v, result, visited);
        }
    }
}

void BFS(unordered_map<int, vector<int>>& adj, int u, vector<int>& result, vector<bool>& visited){
    visited[u] = true;
    result.push_back(u);
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int& v: adj[front]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                result.push_back(v);
            }
        }
    }
}


int main(){
    vector<vector<int>> graph = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    int nodes = graph.size();
    unordered_map<int, vector<int>> adj;
    for(int i=0; i<nodes; i++){
        for(auto v = graph[i].begin(); v!=graph[i].end(); v++){
            adj[i].push_back(*v);
        }
    }

    for(auto& it: adj){
        cout<<it.first<<" : ";
        for(auto& num: it.second){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    vector<int> result;
    vector<bool> visited(nodes, false);
    DFS(adj, 0, result, visited);
    for(auto v: result){
        cout<<v<<" ";
    }

    return 0;
}