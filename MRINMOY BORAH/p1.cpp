#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX], n;

// Add edge
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// BFS
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        struct Node* temp = adjList[node];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
            temp = temp->next;
        }
    }
}

// DFS
void DFS(int node) {
    visited[node] = 1;
    printf("%d ", node);

    struct Node* temp = adjList[node];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {
            DFS(v);
        }
        temp = temp->next;
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); // undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("\nDFS: ");
    DFS(start);

    return 0;
}