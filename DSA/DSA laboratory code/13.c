#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 10

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge edges[MAX_EDGES];
};

struct Subset {
    int parent, rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int edgeComparator(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0; // Index variable for result[]
    int i = 0; // Index variable for sorted edges

    qsort(graph->edges, graph->E, sizeof(struct Edge), edgeComparator);

    struct Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in MST:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    struct Graph graph = {
        .V = 4, // Number of vertices
        .E = 5, // Number of edges
        .edges = {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4}
        }
    };

    kruskalMST(&graph);

    return 0;
}
