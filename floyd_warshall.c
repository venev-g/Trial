// All pairs of shortest paths
// Floyd Warshall

#include <stdio.h>
int i, j, k, n, dist[10][10];








































































































































































void floydWarshell()
{
    for (k = 0; k < n; k++) 
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}
int main()
{
    int i, j;
    printf("enter no of vertices :");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            printf("dist[%d] [%d]:", i, j);
            scanf("%d", &dist[i][j]);
        }
    floydWarshell();
    printf("\n\n shortest distances between every pair of vertices \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", dist[i][j]);
        printf("\n");
        }
return 0;
}

/*

Input:
enter no of vertices :3

dist[0] [0]:0
dist[0] [1]:4
dist[0] [2]:11
dist[1] [0]:6
dist[1] [1]:0
dist[1] [2]:2
dist[2] [0]:3
dist[2] [1]:999
dist[2] [2]:0

Algorithm:
floyd_warshall(int* W, int n) {
    for (int k = 0; k < n: k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
            }
        }
    }
}

Time Complexity:
Floyd Warshall Algorithm consists of three loops over all the nodes. 
• The inner most loop consists of only constant complexity operations. 
• Hence, the asymptotic complexity of Floyd Warshall algorithm is O(n^3). 
• Here, n is the number of nodes in the given graph
*/