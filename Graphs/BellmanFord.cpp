#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <functional>
using namespace std;

void bellmanFord(unordered_map<int, vector<pair<int, int>>>& adj, int V, int source){
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for(int i=0; i<V-1; i++){
        for(int u=0; u<V; u++){
            for(auto& edge: adj[u]){
                int wt = edge.first;
                int v = edge.second;
                if(dist[u]!=INT_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    cout<<"Result: "<<endl;
    for(int i=0; i<V; i++){
        cout<<i<<" -> "<<dist[i]<<endl;
    }
}

void bellmanFord1(vector<vector<int>>& edges, int V, int src){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i=0; i<V-1; i++){
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u]!=INT_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    cout<<"Result: "<<endl;
    for(auto& v: dist){
        cout<<v<<" ";
    }
}

int main(){
    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    int source = 0;
    int V = 5;

    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto& edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({wt, v});
    }

    cout<<"Adjacency Matrix: "<<endl;
    for(auto& value: adj){
        cout<<value.first<<" : ";
        for(auto& num: value.second){
            cout<<"{"<<num.first<<" , "<<num.second<<"} ";
        }
        cout<<endl;
    }

    bellmanFord(adj, V, source);

    return 0;
}