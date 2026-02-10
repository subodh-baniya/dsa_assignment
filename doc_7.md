# B# Dijkstra’s Algorithm (Shortest Path from Source Node)
This is the seventh question of the assignment where we  implement **Dijkstra’s Algorithm** to find the shortest path from a **source node** to all other nodes in a weighted graph using an **adjacency matrix** representation.

# Data Structure
The program uses a **2D array (adjacency matrix)** to represent the weighted graph.

```c 
#define MAX 10
#define INF INT_MAX

int graph[MAX][MAX];

```
- graph[i][j] stores the weight of the edge between node i and node j.
- INF represents no direct edge between two nodes.

## Functions Implemented

1. minDistance(int dist[], bool visited[], int n)
```c

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
```

Finds the unvisited node with the minimum tentative distance.

2. void printPath(int parent[], int v)
```c
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

```
Prints the shortest path from the source node to a given node using the parent array.

3. void dijkstra(int graph[MAX][MAX], int n, int src)
```c
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
```
Computes the shortest distance and path from the source node to all other nodes.


## Main Function Overview

```c

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



```
### Workflow of main function
- Graph is defined using an adjacency matrix.
- Source node is selected (0).
- Dijkstra’s algorithm is applied.
- Shortest distance and path from the source to each node are displayed.


## Sample Output
<img width="357" height="264" alt="Image" src="https://github.com/user-attachments/assets/e678744a-7828-4949-b170-5eef709effd6" />

