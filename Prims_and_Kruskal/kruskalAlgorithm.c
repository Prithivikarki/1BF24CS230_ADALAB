#include <stdio.h>

#define MAX 100

int parent[MAX];

// Find function
int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, i, j, ne = 0;
    int cost[MAX][MAX];
    int min, u, v, a, b;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    // Initialize parent array
    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    while(ne < n - 1) {
        min = 9999;

        // Find minimum edge
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }

        // Check cycle
        if(find(a) != find(b)) {
            printf("%d -> %d  cost = %d\n", u, v, min);
            totalCost += min;
            unionSet(a, b);
            ne++;
        }

        // Remove edge
        cost[u][v] = cost[v][u] = 9999;
    }

    printf("\nTotal cost of MST = %d\n", totalCost);

    return 0;
}
