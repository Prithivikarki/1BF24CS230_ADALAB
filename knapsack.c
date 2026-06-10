#include <stdio.h>
#define INF 99999
#define MAX 10
void floydwarshall(int n, int graph[MAX][MAX]){
    int dist[MAX][MAX];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (dist[i][i] < 0) {
            printf("Negative cycle detected\n");
            return;
        }
    }
    printf("\nAll-pairs shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int n;
    int graph[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    floydwarshall(n, graph);
    return 0;
}
