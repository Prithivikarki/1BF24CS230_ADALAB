#include <stdio.h>
#define MAX 100
#define INF 9999

int main() {
    int n, i, j;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int min, u = 0, v = 0;
    int totalCost = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF (except diagonal)
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    // Start from vertex 0
    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d  cost = %d\n", u, v, min);

        totalCost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nTotal cost of MST = %d\n", totalCost);

    return 0;
}
