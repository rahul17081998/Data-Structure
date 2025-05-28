/*
Approach: Floyd-Warshall Algorithm for All-Pairs Shortest Path
--------------------------------------------------------------
- Initialize the distance matrix with the input graph matrix.
- Update distances by considering each vertex as an intermediate node (k).
- For each pair (i, j), check if path i->k->j is shorter than current i->j.
- Update dist[i][j] if shorter path is found.
- Detect negative weight cycles if dist[i][i] < 0 for any i.
- Finally, print shortest distances between all pairs.
*/

import java.util.Arrays;

public class FloydWarshall {

    static final int V = 6;
    static final int INF = Integer.MAX_VALUE;

    static void floydWarshall(int[][] graph) {
        int[][] dist = new int[V][V];

        // Initialize distance matrix same as graph matrix
        for (int i = 0; i < V; i++) {
            dist[i] = Arrays.copyOf(graph[i], V);
        }

        // Update distances considering each vertex as intermediate
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    // Check for overflow before adding
                    if (dist[i][k] != INF && dist[k][j] != INF
                            && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (int i = 0; i < V; i++) {
            if (dist[i][i] < 0) {
                System.out.println("Negative edge weight cycle is present");
                return;
            }
        }

        // Print shortest path distances
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    System.out.println(i + " to " + j + " distance is INF");
                } else {
                    System.out.println(i + " to " + j + " distance is " + dist[i][j]);
                }
            }
        }
        System.out.println("*************************");
    }

    public static void main(String[] args) {
        int[][] graph = {
                {0, 1, 4, INF, INF, INF},
                {INF, 0, 4, 2, 7, INF},
                {INF, INF, 0, 3, 4, INF},
                {INF, INF, INF, 0, INF, 4},
                {INF, INF, INF, 3, 0, INF},
                {INF, INF, INF, INF, 5, 0}
        };

        floydWarshall(graph);
    }
}