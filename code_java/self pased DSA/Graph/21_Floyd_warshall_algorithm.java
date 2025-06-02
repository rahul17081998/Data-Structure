/*
 * Approach: Floyd-Warshall Algorithm for All-Pairs Shortest Path
 * --------------------------------------------------------------
 * The Floyd-Warshall algorithm finds shortest paths between all pairs of vertices
 * in a weighted graph (with positive or negative edge weights but no negative cycles).
 *
 * How it works:
 * - Initialize a distance matrix 'dist' same as the input graph adjacency matrix.
 * - Consider each vertex 'k' as an intermediate point on the path between vertices 'i' and 'j'.
 * - For every pair (i, j), update dist[i][j] if going through 'k' gives a shorter path:
 *   dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
 * - Repeat for all vertices as intermediate nodes.
 *
 * Negative cycle detection:
 * - If dist[i][i] < 0 for any vertex 'i', it means there is a negative weight cycle in the graph.
 *
 * Time Complexity:
 * - O(V^3), where V is the number of vertices.
 * - Because it uses three nested loops over all vertices.
 *
 * Space Complexity:
 * - O(V^2) for storing the distance matrix.
 *
 * Benefits of Floyd-Warshall Algorithm:
 * -------------------------------------
 * 1. Handles both positive and negative edge weights (unlike Dijkstra which only works with non-negative weights).
 * 2. Detects presence of negative weight cycles in the graph.
 * 3. Computes shortest paths between **all pairs** of vertices simultaneously.
 * 4. Simple and easy to implement with a clear DP approach.
 *
 * When to use:
 * - When you need shortest path information between all pairs of vertices, not just from a single source.
 * - When the graph is dense, Floyd-Warshall is often more efficient and simpler than running Dijkstra V times.
 * - When negative edges are present but no negative cycles.
 *
 * Limitations:
 * - For very large graphs, O(V^3) time can be expensive compared to specialized algorithms.
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