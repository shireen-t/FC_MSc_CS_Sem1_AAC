// Find the minimum cost spanning Tree of a given
// undirected graph using Prim's and Kruskal's Alsgorithm

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 99999

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function prototypes
void primsAlgorithm(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);
void kruskalsAlgorithm(struct Edge edges[], int vertices, int edgesCount);
int find(int parent[], int i);
void unionSets(int parent[], int x, int y);
int compareEdges(const void* a, const void* b);

int main() {
    int vertices, edgesCount;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &edgesCount);
    
    struct Edge edges[edgesCount];

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < edgesCount; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        graph[edges[i].src][edges[i].dest] = edges[i].weight;
        graph[edges[i].dest][edges[i].src] = edges[i].weight; // Undirected graph
    }

    printf("\nMinimum Cost Spanning Tree using Prim's Algorithm:\n");
    primsAlgorithm(graph, vertices);

    printf("\nMinimum Cost Spanning Tree using Kruskal's Algorithm:\n");
    kruskalsAlgorithm(edges, vertices, edgesCount);

    return 0;
}

// Function to implement Prim's Algorithm
void primsAlgorithm(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES] = {0};

    for (int i = 0; i < vertices; i++) {
        key[i] = INF; // Initialize keys to infinity
        mstSet[i] = 0; // Initialize MST set
    }
    
    key[0] = 0; // Starting vertex
    parent[0] = -1; // First node is the root of the MST

    for (int count = 0; count < vertices - 1; count++) {
        int minKey = INF, u;

        // Find the minimum key vertex not yet included in the MST
        for (int v = 0; v < vertices; v++) {
            if (mstSet[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Add the selected vertex to the MST
        mstSet[u] = 1;

        // Update the key and parent index of the adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    for (int i = 1; i < vertices; i++) {
        printf("Edge: %d - %d, Weight: %d\n", parent[i], i, graph[parent[i]][i]);
    }
}

// Function to implement Kruskal's Algorithm
void kruskalsAlgorithm(struct Edge edges[], int vertices, int edgesCount) {
    // Sort edges based on their weights
    qsort(edges, edgesCount, sizeof(edges[0]), compareEdges);

    int parent[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        parent[i] = i; // Initialize parent
    }

    int mstWeight = 0;
    printf("Edges in the Minimum Spanning Tree:\n");

    for (int i = 0; i < edgesCount; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        // If including this edge does not cause a cycle
        if (x != y) {
            printf("Edge: %d - %d, Weight: %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(parent, x, y);
        }
    }
    printf("Total Weight of MST: %d\n", mstWeight);
}

// Function to find the parent of a node
int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

// Function to unite two subsets
void unionSets(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

// Function to compare edges by weight (for qsort)
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}
