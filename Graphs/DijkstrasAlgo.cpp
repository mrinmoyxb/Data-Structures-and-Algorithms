#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <functional>
using namespace std;

void dijkstraAlgo(int V, unordered_map<int, vector<pair<int, int>>>& adj, int source){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> result(V, INT_MAX);
    result[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(distance > result[node]) continue;

        for(auto& vec: adj[node]){
            int adjNode = vec.second;
            int wt = vec.first;
            if(distance + wt < result[adjNode]){
                result[adjNode] = distance+wt;
                pq.push({distance+wt, adjNode});
            }
        }
    }
}

int main(){
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
    int source = 2;

    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto& vec: edges){
        int u = vec[0];
        int v = vec[1];
        int wt = vec[2];
        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u});
    }

    for(auto& value: adj){
        cout<<value.first<<" : ";
        for(auto& v: value.second){
            cout<<"{ "<<v.first<<", "<<v.second<<" }  ";
        }
        cout<<endl;
    }



    return 0;
}