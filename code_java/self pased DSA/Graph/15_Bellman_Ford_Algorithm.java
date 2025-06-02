import java.util.*;

/**
 * Bellman-Ford Algorithm in Java
 * ------------------------------
 * Problem Statement:
 * ------------------
 * Given a directed, weighted graph with N vertices and a list of edges, find the shortest
 * distances from a given source vertex to all other vertices using the Bellman-Ford algorithm.
 *
 * The graph may contain negative edge weights, and the algorithm can also detect negative
 * weight cycles (cycles whose total weight is negative).
 *
 * What is Bellman-Ford Algorithm?
 * -------------------------------
 * The Bellman-Ford algorithm is a single-source shortest path algorithm that works even when
 * edge weights are negative. Unlike Dijkstra’s algorithm, Bellman-Ford:
 *  - Can handle graphs with negative edge weights.
 *  - Can detect negative weight cycles.
 *  - Has higher time complexity: O(N * E), where N = vertices and E = edges.
 *
 * When to Use:
 * ------------
 * - The graph contains negative edge weights.
 * - You need to detect if a negative weight cycle exists.
 *
 * Key Steps of the Algorithm:
 * ---------------------------
 * 1. Initialize all distances to infinity (`Integer.MAX_VALUE`), except for the source vertex
 *    which is set to 0.
 *
 * 2. Relax all edges (N - 1) times:
 *    - For each edge u → v with weight w:
 *      - If dist[u] + w < dist[v], update dist[v] = dist[u] + w.
 *
 * 3. Check for negative weight cycles:
 *    - Go through all edges one more time.
 *    - If any edge can still be relaxed, then a negative weight cycle exists.
 *
 * 4. Output the shortest distances from the source to each vertex.
 *
 * Time Complexity:
 * ----------------
 * O(N * E) where N = number of vertices, E = number of edges.
 *
 * Space Complexity:
 * -----------------
 * O(N) for distance array.
 *
 * Output:
 * -------
 * - Prints shortest distances if no negative weight cycle exists.
 * - Prints a message if a negative weight cycle is found.
 */

class Edge {
    int u, v, wt;

    Edge(int u, int v, int wt) {
        this.u = u;
        this.v = v;
        this.wt = wt;
    }
}

public class BellmanFordAlgorithm {

    /**
     * Function to run Bellman-Ford algorithm and print shortest distances.
     *
     * @param N     Number of vertices in the graph
     * @param edges List of edges representing the graph
     * @param src   The source vertex from which distances are calculated
     */
    public static void bellmanFord(int N, List<Edge> edges, int src) {
        int INF = 1_000_000;
        int[] dist = new int[N];
        Arrays.fill(dist, INF);
        dist[src] = 0;

        // Step 1: Relax all edges (N - 1) times
        for (int i = 1; i <= N - 1; i++) {
            for (Edge edge : edges) {
                if (dist[edge.u] != INF && dist[edge.u] + edge.wt < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.wt;
                }
            }
        }

        // Step 2: Check for negative weight cycle
        for (Edge edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.wt < dist[edge.v]) {
                System.out.println("Graph contains a negative weight cycle!");
                return;
            }
        }

        // Step 3: Output final distances
        System.out.println("Shortest distances from source node " + src + ":");
        for (int i = 0; i < N; i++) {
            if (dist[i] == INF) {
                System.out.println("To vertex " + i + " : Unreachable");
            } else {
                System.out.println("To vertex " + i + " : " + dist[i]);
            }
        }
    }

    /**
     * Main method to set up the graph and invoke the Bellman-Ford algorithm.
     */
    public static void main(String[] args) {
        int N = 6;
        int src = 0;

        // Directed edges in the format: from → to, weight
        List<Edge> edges = new ArrayList<>();
        edges.add(new Edge(0, 1, 5));
        edges.add(new Edge(1, 2, -2));
        edges.add(new Edge(1, 5, -3));
        edges.add(new Edge(2, 4, 3));
        edges.add(new Edge(3, 2, 6));
        edges.add(new Edge(3, 4, -2));
        edges.add(new Edge(5, 3, 1));

        // Run the algorithm
        bellmanFord(N, edges, src);
    }
}