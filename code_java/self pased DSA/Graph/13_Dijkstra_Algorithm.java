import java.util.Arrays;

/**
 * Problem Statement:
 * ------------------
 * Given a weighted, undirected graph represented as an adjacency matrix,
 * find the shortest distance from a given source vertex to all other vertices
 * using Dijkstra's Algorithm.
 *
 * Input:
 * ------
 * - A 2D matrix `graph[V][V]` where `graph[i][j]` represents the weight of the edge
 *   between vertex `i` and vertex `j`. If `graph[i][j]` is 0, it means there is no edge.
 * - An integer `src` denoting the source vertex.
 *
 * Output:
 * -------
 * - An array of shortest distances from the source to each vertex.
 *
 * What is Dijkstra’s Algorithm?
 * -----------------------------
 * Dijkstra’s Algorithm is a greedy algorithm used to find the shortest path from a single
 * source node to all other nodes in a graph with non-negative edge weights.
 * It continuously selects the unvisited node with the smallest known distance,
 * updates distances to its neighbors, and finalizes the shortest path to that node.
 *
 * Characteristics:
 * - Works only with non-negative weights.
 * - Can be implemented using an adjacency list with a min-heap (efficient: O(E log V)) or
 *   an adjacency matrix with simple linear scanning (slower: O(V^2)).
 *
 * Approach Used in This Code (Adjacency Matrix - O(V^2)):
 * -------------------------------------------------------
 * 1. Initialize a distance array `dist[]` with `Integer.MAX_VALUE` for all vertices.
 *    Set `dist[src] = 0` because the distance to the source is zero.
 * 2. Create a boolean array `fin[]` to track vertices whose minimum distance is finalized.
 * 3. Repeat (V-1) times:
 *    a. Pick the unvisited vertex `u` with the smallest tentative distance.
 *    b. Mark `u` as finalized.
 *    c. For each vertex `v`, if there is an edge from `u` to `v`, and `v` is not finalized,
 *       and the total distance to `v` via `u` is less than the current `dist[v]`, then update it.
 * 4. After all iterations, `dist[]` contains the shortest distances from the source.
 *
 * Time Complexity:
 * ----------------
 * O(V^2) - because for each of the V vertices, we scan all V nodes to find the minimum.
 *
 * Assumptions:
 * ------------
 * - The graph is undirected and connected.
 * - All weights are non-negative.
 * - The adjacency matrix is symmetric (since undirected).
 */

public class DijkstraAlgorithm {

    static final int V = 4;

    // Function to perform Dijkstra's Algorithm using adjacency matrix
    static int[] dijkstra(int[][] graph, int src) {
        int[] dist = new int[V];         // Array to hold shortest distances
        boolean[] fin = new boolean[V];  // Tracks vertices whose shortest distance is finalized

        Arrays.fill(dist, Integer.MAX_VALUE); // Step 1: Initialize all distances as infinite
        dist[src] = 0; // Distance to source is 0

        // Step 2: Iterate V-1 times to finalize shortest distances
        for (int count = 0; count < V - 1; count++) {
            int mini = Integer.MAX_VALUE, u = -1;

            // Find the unvisited vertex with the smallest tentative distance
            for (int i = 0; i < V; i++) {
                if (!fin[i] && dist[i] < mini) {
                    mini = dist[i];
                    u = i;
                }
            }

            // Mark the selected vertex as finalized
            fin[u] = true;

            // Step 3: Relax adjacent vertices
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && !fin[v] && dist[u] != Integer.MAX_VALUE
                        && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        return dist;
    }

    // Main method with example input
    public static void main(String[] args) {
        int[][] graph = {
                {0, 50, 100, 0},
                {50, 0, 30, 200},
                {100, 30, 0, 20},
                {0, 200, 20, 0}
        };

        int src = 0;
        int[] dist = dijkstra(graph, src);

        System.out.println("Shortest distances from source node " + src + ":");
        for (int i = 0; i < dist.length; i++) {
            System.out.println("To node " + i + " : " + dist[i]);
        }
    }
}