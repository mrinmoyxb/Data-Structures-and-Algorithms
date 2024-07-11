//* A graph is a data structure combination of nodes and edges

//? Terms: 
//* degree
//* undirected and directed
//* weighted and unweighted edges
//* cyclic graph and acyclic graph

//? Representation:
//* Adjacency Matrix
//* Adjacency List

#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int key, int value, bool direction){

        //* 0 = undirected graph
        //* 1 = directed graph

        adj[key].push_back(value);
        if(direction==0){
            adj[value].push_back(key);
        }
    }

    void displayAdjList(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};


int main(){
    int n, e;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    cout<<"Enter the number of edges: "<<endl;
    cin>>e;

    Graph g;

    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v, 0);
    }

    cout<<"\nGraph: "<<endl;
    g.displayAdjList();

    return 0;
}


