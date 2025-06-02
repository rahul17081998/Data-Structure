import java.util.*;

/**
 * Articulation Points in a Graph (Tarjan's Algorithm)
 * ---------------------------------------------------
 * Problem Statement:
 * ------------------
 * Given an undirected graph, find all **articulation points** (also called cut vertices).
 * An articulation point is a vertex that, when removed (along with its edges),
 * increases the number of connected components of the graph.
 *
 * Use Cases:
 * ----------
 * - Network reliability: Identifying nodes that, if fail, split the network
 * - Road/bridge analysis in transport networks
 * - Weak points in distributed systems
 *
 * Definitions:
 * ------------
 * - disc[u]: Discovery time of node u during DFS
 * - low[u]: Lowest discovery time reachable from node u (including back edges)
 *
 * Key Observations:
 * -----------------
 * 1. A **non-root** node `u` is an articulation point if it has a child `v` such that `low[v] >= disc[u]`.
 * 2. A **root node** is an articulation point if it has **2 or more children** in the DFS tree.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

public class ArticulationPoints {
    private int V;                      // Number of vertices
    private List<List<Integer>> adj;   // Adjacency list
    private int time = 0;              // Timer used in DFS

    /**
     * Constructor: Initializes a graph with V vertices
     */
    public ArticulationPoints(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    /**
     * Adds an undirected edge between vertices u and v
     */
    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    /**
     * Utility DFS method to find articulation points
     *
     * @param u      Current vertex
     * @param visited Tracks visited nodes
     * @param disc    Discovery times
     * @param low     Low values
     * @param parent  Parent of current node in DFS
     * @param isAP    Flags indicating articulation points
     */
    private void APUtil(int u, boolean[] visited, int[] disc, int[] low, int parent, boolean[] isAP) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0; // Count children of u in DFS tree

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                children++;
                APUtil(v, visited, disc, low, u, isAP);

                // Update low value for parent
                low[u] = Math.min(low[u], low[v]);

                // Case 1: u is not root and low[v] >= disc[u]
                if (parent != -1 && low[v] >= disc[u]) {
                    isAP[u] = true;
                }
            } else if (v != parent) {
                // Back edge case
                low[u] = Math.min(low[u], disc[v]);
            }
        }

        // Case 2: u is root with 2 or more children
        if (parent == -1 && children > 1) {
            isAP[u] = true;
        }
    }

    /**
     * Finds and prints all articulation points in the graph
     */
    public void findArticulationPoints() {
        boolean[] visited = new boolean[V];
        int[] disc = new int[V];     // Discovery times
        int[] low = new int[V];      // Low values
        boolean[] isAP = new boolean[V]; // Articulation point flags

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                APUtil(i, visited, disc, low, -1, isAP);
            }
        }

        System.out.print("Articulation points are: ");
        for (int i = 0; i < V; i++) {
            if (isAP[i]) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    /**
     * Driver method with example graphs
     */
    public static void main(String[] args) {
        // First graph
        ArticulationPoints graph1 = new ArticulationPoints(5);
        graph1.addEdge(1, 0);
        graph1.addEdge(0, 2);
        graph1.addEdge(2, 1);
        graph1.addEdge(0, 3);
        graph1.addEdge(3, 4);
        System.out.println("Articulation points in first graph:");
        graph1.findArticulationPoints();

        // Second graph
        ArticulationPoints graph2 = new ArticulationPoints(7);
        graph2.addEdge(0, 1);
        graph2.addEdge(1, 2);
        graph2.addEdge(2, 0);
        graph2.addEdge(1, 3);
        graph2.addEdge(1, 4);
        graph2.addEdge(1, 6);
        graph2.addEdge(3, 5);
        graph2.addEdge(4, 5);
        System.out.println("Articulation points in second graph:");
        graph2.findArticulationPoints();
    }
}