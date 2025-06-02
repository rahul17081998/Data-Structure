import java.util.*;

/**
 * Bridges in a Graph (Tarjan's Algorithm)
 * ---------------------------------------
 * Problem Statement:
 * ------------------
 * Given an undirected graph, find all the bridges (critical connections) in the graph.
 * A **bridge** is an edge whose removal increases the number of connected components.
 *
 * Use Cases:
 * ----------
 * - Network design and fault tolerance
 * - Finding vulnerabilities in communication or power grids
 * - Analyzing critical roads in a transport network
 *
 * Definitions:
 * ------------
 * - Discovery Time (`disc[u]`): The time when a node `u` is first visited in DFS.
 * - Low Value (`low[u]`): The lowest discovery time reachable from the subtree rooted at `u`, including back edges.
 *
 * Approach (Tarjan’s Algorithm using DFS):
 * ----------------------------------------
 * 1. Perform DFS traversal on the graph.
 * 2. For each vertex `u`, compute:
 *    - `disc[u]`: when it was first discovered
 *    - `low[u]`: the lowest discovery time reachable from `u` or its subtree
 * 3. For every edge `u → v`:
 *    - If `low[v] > disc[u]`, then the edge `u-v` is a **bridge**.
 * 4. Use a parent array to avoid treating the back edge to the parent as a bridge.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

public class BridgesInGraph {
    private int V; // Number of vertices
    private List<List<Integer>> adj; // Adjacency list representation of the graph
    private int time = 0; // Global timer for discovery time

    /**
     * Constructor to initialize graph with V vertices
     */
    public BridgesInGraph(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    /**
     * Adds an undirected edge between vertex v and w
     */
    public void addEdge(int v, int w) {
        adj.get(v).add(w);
        adj.get(w).add(v);
    }

    /**
     * Recursive utility function for DFS to find bridges
     *
     * @param u       Current node
     * @param visited Visited array
     * @param disc    Discovery times
     * @param low     Low values
     * @param parent  Parent of current node in DFS tree
     */
    private void bridgeUtil(int u, boolean[] visited, int[] disc, int[] low, int[] parent) {
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                parent[v] = u;
                bridgeUtil(v, visited, disc, low, parent);

                // Update low value of u for subtree rooted at v
                low[u] = Math.min(low[u], low[v]);

                // Bridge condition: if v cannot reach an ancestor of u
                if (low[v] > disc[u]) {
                    System.out.println(u + " - " + v + " is a bridge");
                }
            } else if (v != parent[u]) {
                // Update low value for back edge
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }

    /**
     * Main function to find and print all bridges in the graph
     */
    public void bridge() {
        boolean[] visited = new boolean[V];
        int[] disc = new int[V];     // Discovery times
        int[] low = new int[V];      // Low values
        int[] parent = new int[V];   // Parent vertices

        Arrays.fill(parent, -1); // Initialize all parents as -1

        // Apply DFS for each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bridgeUtil(i, visited, disc, low, parent);
            }
        }
    }

    /**
     * Driver method to demonstrate bridge finding
     */
    public static void main(String[] args) {
        System.out.println("Bridges in the graph:");

        BridgesInGraph g = new BridgesInGraph(5);
        g.addEdge(1, 0);
        g.addEdge(0, 2);
        g.addEdge(2, 1);
        g.addEdge(0, 3);
        g.addEdge(3, 4);

        g.bridge();
    }
}