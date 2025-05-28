import java.util.*;
/*
 Approach:
 Find all bridges in an undirected graph using DFS and low-link values.
 - Perform DFS traversal of the graph, recording discovery times (disc) and the lowest reachable vertex (low) for each vertex.
 - For each edge (u, v):
   - If low[v] > disc[u], then (u, v) is a bridge (removing it increases connected components).
 - Use a parent array to avoid considering the edge leading back to the parent as a bridge.
 - Bridges are edges which, if removed, increase the number of connected components.
*/

public class BridgesInGraph {
    private int V; // Number of vertices
    private List<List<Integer>> adj; // Adjacency list

    private int time = 0;

    public BridgesInGraph(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    // Add undirected edge
    public void addEdge(int v, int w) {
        adj.get(v).add(w);
        adj.get(w).add(v);
    }

    // A recursive function that finds bridges using DFS
    private void bridgeUtil(int u, boolean[] visited, int[] disc, int[] low, int[] parent) {
        visited[u] = true;

        disc[u] = low[u] = ++time;

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                parent[v] = u;
                bridgeUtil(v, visited, disc, low, parent);

                // Update low value
                low[u] = Math.min(low[u], low[v]);

                // Check if edge u-v is a bridge
                if (low[v] > disc[u]) {
                    System.out.println(u + " " + v);
                }
            } else if (v != parent[u]) {
                // Update low value for back edge
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }

    // Function to find and print all bridges
    public void bridge() {
        boolean[] visited = new boolean[V];
        int[] disc = new int[V];
        int[] low = new int[V];
        int[] parent = new int[V];

        Arrays.fill(parent, -1);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bridgeUtil(i, visited, disc, low, parent);
            }
        }
    }

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