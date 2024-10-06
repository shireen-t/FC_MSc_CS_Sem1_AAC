// From a given vertex in a weighted connected graph,
// find shortest paths to other vertices using Dijikstra's
// algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

// Function prototypes
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex);
void printShortestPaths(int dist[], int vertices, int startVertex);

int main() {
    int vertices, startVertex;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                graph[i][j] = 0; // Distance to itself is 0
            } else {
                graph[i][j] = INT_MAX; // Initialize to infinity
            }
        }
    }

    printf("Enter the number of edges: ");
    int edges;
    scanf("%d", &edges);
    
    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight; // Directed graph
        graph[dest][src] = weight; // Uncomment for undirected graph
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dijkstra(graph, vertices, startVertex);

    return 0;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    // Initialize distances
    for (int i = 0; i < vertices; i++) {
        dist[i] = graph[startVertex][i]; // Initial distances from startVertex
    }
    visited[startVertex] = 1; // Mark the starting vertex as visited

    // Dijkstra's algorithm
    for (int count = 0; count < vertices - 1; count++) {
        int minDist = INT_MAX;
        int u;

        // Find the vertex with the minimum distance
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        // Mark the selected vertex as visited
        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest paths
    printShortestPaths(dist, vertices, startVertex);
}

// Function to print the shortest paths
void printShortestPaths(int dist[], int vertices, int startVertex) {
    printf("Shortest paths from vertex %d:\n", startVertex);
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX) {
            printf("Vertex %d: Unreachable\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
}
