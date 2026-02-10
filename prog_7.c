#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10             
#define INF INT_MAX        

// Find the unvisited node with minimum distance 
int minDistance(int dist[], bool visited[], int n) {
    int min = INF;
    int idx = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

// Print path
void printPath(int parent[], int v) {
    int path[MAX];
    int len = 0;

    while (v != -1) {
        path[len++] = v;
        v = parent[v];
    }

    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i) printf(" -> ");
    }
}

// Dijkstra’s algorithm 
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];          
    int parent[MAX];      
    bool visited[MAX];     

    for (int i = 0; i < n; i++) {
        dist[i] = INF;   
        parent[i] = -1;    
        visited[i] = false;
    }

    dist[src] = 0;         

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Source node: %d\n\n", src);
    printf("Node\tDistance\tPath\n");

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("%d\tINF\t\tNo path\n", i);
        } else {
            printf("%d\t%d\t\t", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    int n = 5;

    // adjacency matrix representation of graph
    int graph[MAX][MAX] = {
        {0,   10,  5,  INF, INF},
        {10,  0,   2,  1,   INF},
        {5,   2,   0,  9,   2},
        {INF, 1,   9,  0,   4},
        {INF, INF, 2,  4,   0}
    };

    int source = 0;     // source node
    dijkstra(graph, n, source);

    return 0;
}
