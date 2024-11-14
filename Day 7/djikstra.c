#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


void dijkstra(int graph[5][5], int numVertices, int source, int dist[], int prev[]) {
    int visited[5] = {0}; 
    int i, j;
    for (i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;      
    }
    dist[source] = 0; 
    for (i = 0; i < numVertices - 1; i++) {
        int minDist = INT_MAX, minIndex = -1;
        for (j = 0; j < numVertices; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minIndex = j;
            }
        }
        visited[minIndex] = 1; 
        for (j = 0; j < numVertices; j++) {
            if (!visited[j] && graph[minIndex][j] && dist[minIndex] != INT_MAX && 
                dist[minIndex] + graph[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + graph[minIndex][j];
                prev[j] = minIndex; 
            }
        }
    }
}

void printPath(int prev[], int source, int destination) {
    int path[5];
    int count = 0;
    int current = destination;
    while (current != -1) {
        path[count++] = current;
        current = prev[current];
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", path[i] + 1);
        if (i > 0) {
            printf("->");
        }
    }
}

int main() {
    int graph[5][5];
    int dist[5]; 
    int prev[5]; 
    int numVertices, source;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the Source Vertex: ");
    scanf("%d", &source);
    source--;
    FILE *file = fopen("inDiAdjMat1.txt", "r");
    if (!file) {
        fprintf(stderr, "Could not open file.\n");
        return 1;
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);

    dijkstra(graph, numVertices, source, dist, prev);
    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < numVertices; i++) {
        if (i != source) {
            printf("%d\t\t%d\t", source + 1, i + 1); 
            printf("%d\t\t", dist[i] == INT_MAX ? -1 : dist[i]); 
            if (dist[i] == INT_MAX) {
                printf("-\n");
            } else {
                printPath(prev, source, i);
                printf("\n");
            }
        }
    }

    return 0;
}