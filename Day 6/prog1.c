#include <stdio.h>
#include <limits.h>

#define MAX 100

int n; 
int graph[MAX][MAX]; 
int selected[MAX]; 
int mst[MAX][MAX];
void readGraphFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);
}

void displayMatrix(int matrix[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void primsAlgorithm(int start) {
    int noOfEdges = 0;
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        selected[i] = 0;
        for (int j = 0; j < n; j++) {
            mst[i][j] = 0;
        }
    }

    selected[start] = 1;

    while (noOfEdges < n - 1) {
        int min = INT_MAX;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) { 
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        mst[x][y] = graph[x][y];
        mst[y][x] = graph[x][y];
        totalCost += graph[x][y];
        selected[y] = 1;
        noOfEdges++;
    }
    printf("\nCost Adjacency Matrix of the Minimum Spanning Tree:\n");
    displayMatrix(mst);
    printf("\nTotal Weight of the Spanning Tree: %d\n", totalCost);
}

int main() {
    int start;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);
    start--;
    readGraphFromFile("inUnAdjMat.txt");
    printf("\nInput Cost Adjacency Matrix:\n");
    displayMatrix(graph);
    primsAlgorithm(start);
    return 0;
}
