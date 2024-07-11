#include <iostream>
#include <vector>
using namespace std;

class UndirectedGraph{
    public:
    vector<vector<int>> undirectedGraph;

    void addAdjacentVertices(int node, int adjacent){
        undirectedGraph[node].push_back(adjacent);
    }

    // void display(){
    //     cout<<"Graph: "<<endl;
    //     for(int i = 0; i<=undirectedGraph.size(); i++){
    //         cout<<undirectedGraph[i]<<" "
    //     }
    // }
};

void test(){
    int num_vertices;  // Number of vertices in the graph

    cout << "Enter the number of vertices: ";
    cin >> num_vertices;

    // Create an adjacency list with empty vectors for each vertex
    vector<vector<int>> adj_list(num_vertices);

    // Get input for adjacent edges for vertex at index 0
    int num_edges_for_vertex_0;
    cout << "Enter the number of adjacent edges for vertex 0: ";
    cin >> num_edges_for_vertex_0;

    for (int i = 0; i < num_vertices; i++) {
         int num_edges_for_vertex_0;
         cout << "Enter the number of adjacent edges for vertex 0: ";
        cin >> num_edges_for_vertex_0;
        for(int j=0; j<num_edges_for_vertex_0; j++){
        int edge;
        cout << "Enter adjacent edge for vertex 0: ";
        cin >> edge;
        adj_list[i].push_back(edge);
        }  // Add edge to the adjacency list of vertex 0
    }

    // (Optional) You can repeat the same process for other vertices if needed
    // ...

    // Print the adjacency list (optional)
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < num_vertices; i++) {
        cout << "Vertex " << i << ": ";
        for (int neighbor : adj_list[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main(){
    test();

    

    return 0;
}