# BFS and DFS Traversal of an Undirected Graph
This is the fifth question of the assignment where we have to implement Breadth First Search (BFS) and Depth First Search (DFS) for an undirected graph using an adjacency matrix.
## Data Structure
The program uses a **2D array** (adjacency matrix) and a visited array for traversal.

```c 
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n = 5;

```
- adj[][] tells does the vertices have edge between them or not
- visited[] tracks which vertices have been visited.

## Functions Implemented

1. void BFS(int start)
```c
void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
```

Traverses the graph level by level using a queue.

2. void DFS(int v)
```c
void DFS(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

```
Traverses the graph depth-first using recursion.


## Main Function Overview

```c

int main()
{
    // Initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // undirected edges
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[3][4] = adj[4][3] = 1;

    BFS(0);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS: ");
    DFS(0);

    return 0;
}

```
### Workflow of main function
- Adjacency matrix is initialized.
- Hardcoded edges are added to form the graph.
- BFS traversal is performed starting from vertex 0.
- Visited array is reset.
- DFS traversal is performed starting from vertex 0.

## Sample Output
<img width="1425" height="107" alt="Image" src="https://github.com/user-attachments/assets/1ca69ca3-5aaa-4503-bca0-d6824abab370" />

