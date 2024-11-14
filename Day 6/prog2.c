#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int u, v, weight;
};
struct Subset {
    int parent, rank;
};
int find(struct Subset subsets[], int i);
void unionSet(struct Subset subsets[], int u, int v);
int compareEdges(const void* a, const void* b);
void kruskalMST(struct Edge edges[], int n, int m);

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    struct Edge edges[m];
    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    kruskalMST(edges, n, m);

    return 0;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void unionSet(struct Subset subsets[], int u, int v) {
    int rootU = find(subsets, u);
    int rootV = find(subsets, v);

    if (subsets[rootU].rank < subsets[rootV].rank) {
        subsets[rootU].parent = rootV;
    } else if (subsets[rootU].rank > subsets[rootV].rank) {
        subsets[rootV].parent = rootU;
    } else {
        subsets[rootV].parent = rootU;
        subsets[rootU].rank++;
    }
}
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}
void kruskalMST(struct Edge edges[], int n, int m) {
    struct Edge mst[n - 1];  
    struct Subset subsets[n];
    int mstCost = 0;
    int edgeCount = 0;
    for (int i = 0; i < n; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    qsort(edges, m, sizeof(struct Edge), compareEdges);
    for (int i = 0; i < m && edgeCount < n - 1; i++) {
        struct Edge nextEdge = edges[i];

        int uRoot = find(subsets, nextEdge.u - 1);
        int vRoot = find(subsets, nextEdge.v - 1);
        if (uRoot != vRoot) {
            mst[edgeCount++] = nextEdge;
            mstCost += nextEdge.weight;
            unionSet(subsets, uRoot, vRoot);
        }
    }
    printf("Edge\t\tCost\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("%d--%d\t\t%d\n", mst[i].u, mst[i].v, mst[i].weight);
    }
    printf("Total Weight of the Spanning Tree: %d\n", mstCost);
}
