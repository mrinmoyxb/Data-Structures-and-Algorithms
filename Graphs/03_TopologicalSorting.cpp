#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//* "Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering."

//! Topological Sort using DFS
void topologicalSortDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st){
    visited[u] = true;

    for(int& v: adj[u]){
        if(!visited[v]) topologicalSortDFS(adj, v, visited, st);
    }

    st.push(u);
}

//! Topological Sort using BFS - KAHN's Algo
//! node with indegree 0 will come first
void genIndegree(vector<int>& indegree, unordered_map<int, vector<int>>& adj){
    int nodes = adj.size();
    for(int i=0; i<nodes; i++){
        for(int& v: adj[i]){
            indegree[v]++;
        }
    }
}

vector<int> topologicalSortBFS(vector<int>& indegree, unordered_map<int, vector<int>>& adj){
    int nodes = adj.size();
    queue<int> q;

    for(int i=0; i<nodes; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> result;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        result.push_back(u);

        for(int& v: adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }

    }
    return result;
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
    stack<int> st;

    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            topologicalSortDFS(adj, i, visited, st);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}