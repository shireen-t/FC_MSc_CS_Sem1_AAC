// Write a program to obtain the Topological ordering
// of vertices in a given digraph.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph {
    int vertices;
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
};

// Function prototypes
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void topologicalSort(struct Graph* graph);

int main() {
    int vertices, edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Topological Sort of the given graph:\n");
    topologicalSort(graph);

    // Free the graph memory
    free(graph);
    return 0;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Initialize adjacency matrix
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->adj[i][j] = 0; // No edges initially
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1; // Add edge from src to dest
}

// Function to perform topological sorting
void topologicalSort(struct Graph* graph) {
    int inDegree[MAX_VERTICES] = {0}; // Array to store in-degrees
    int topologicalOrder[MAX_VERTICES]; // Array to store the topological order
    int index = 0;

    // Calculate in-degrees of all vertices
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adj[j][i] == 1) {
                inDegree[i]++;
            }
        }
    }

    // Queue for processing vertices with in-degree 0
    int queue[MAX_VERTICES], front = 0, rear = -1;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < graph->vertices; i++) {
        if (inDegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    // Process the queue
    while (front <= rear) {
        int currentVertex = queue[front++]; // Dequeue
        topologicalOrder[index++] = currentVertex; // Store in topological order

        // Decrease the in-degree of neighbors
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adj[currentVertex][i] == 1) {
                inDegree[i]--;
                // If in-degree becomes 0, add it to the queue
                if (inDegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    // Check if there was a cycle in the graph
    if (index != graph->vertices) {
        printf("There exists a cycle in the graph. Topological sorting is not possible.\n");
    } else {
        // Print the topological order
        for (int i = 0; i < index; i++) {
            printf("%d ", topologicalOrder[i]);
        }
        printf("\n");
    }
}
