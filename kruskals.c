// Kruskal's algorithm (Greedy Approach)

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);




































































































































































int uni(int, int);

int main() {
    printf("Kruskal's algorithm in C\n");
    printf("========================\n");

    printf("Enter the no. of vertices: \n");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix: \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    getch();
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

/*
Enter the no. of vertices: 
6

Enter the cost adjacency matrix:
0       16      0       0       10      0
16      0       20      14      0       0
0       20      0       18      0       22
0       14      18      0       0       17
10      0       0       0       0       12
0       0       22      17      12      0

Algorithm: 
Kruskal's algorithm also follows greedy approach, which finds an optimum 
solution at every stage instead of focusing on a global optimum. 
The sequence of steps for Kruskal’s algorithm is given as follows: 
1. First sort all the edges from the lowest weight to highest. 
2. Take edge with the lowest weight and add it to the spanning tree. If 
the cycle is created, discard the edge. 
3. Keep adding edges like in step 1 until all the vertices are considered.

Time Complexity:
O(E logE) or O(V logV) is the time complexity of the Kruskal algorithm. 
Here E indicates the no. of edges, and V indicates the no. of vertices. 
Auxiliary Space: O(V + E), where V is the number of vertices and E is 
the number of edges in the graph.
*/