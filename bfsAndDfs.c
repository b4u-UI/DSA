#include<stdio.h>
#define MAX 10

void initializeMatrix(int graph[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void displayMatrix(int graph[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void breadthFirstSearch(int graph[][MAX], int visited[], int start, int n) {
    int queue[MAX];
    int front = 0, rear = -1;

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Enqueue starting node
    rear++;
    queue[rear] = start;
    visited[start] = 1;
    printf("BFS Traversal: ");

    while (front <= rear) {
        int current = queue[front];
        front++;
        printf("%d ", current);

        // Explore neighbors
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void depthFirstSearch(int graph[][MAX], int visited[], int start, int n) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            depthFirstSearch(graph, visited, i, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    int graph[MAX][MAX], edge;
    initializeMatrix(graph, n);

    int v1, v2;
    printf("Enter the number of edges: ");
    scanf("%d", &edge);
    
    for(int i = 0; i < edge; i++) {
        printf("Edges (A -> B): ");
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
    }
    
    printf("\nAdjacency Matrix:\n");
    displayMatrix(graph, n);

    int visited[MAX] = {0};
    printf("\nBFS Traversal: ");
    breadthFirstSearch(graph, visited, 0, n);

    // Reset visited array for DFS
    for(int i = 0; i < n; i++) visited[i] = 0;
    
    printf("DFS Traversal: ");
    depthFirstSearch(graph, visited, 0, n);
    printf("\n");
    
    return 0;
}
