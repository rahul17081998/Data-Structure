/*
 * What is a Bipartite Graph?
 * ---------------------------
 * A graph is called bipartite if we can split its set of vertices into two
 * disjoint subsets such that every edge connects a vertex from one subset
 * to a vertex from the other subset. In other words, no two vertices within
 * the same subset are adjacent.
 *
 * Why check for Bipartiteness?
 * -----------------------------
 * Bipartite graphs are important in many applications like matching problems,
 * scheduling, and coloring problems.
 *
 * How to Check if a Graph is Bipartite?
 * -------------------------------------
 * We use a graph coloring approach with two colors (say 0 and 1):
 * - Initialize all vertices as uncolored (-1).
 * - For each uncolored vertex, perform a BFS traversal:
 *     - Assign a color (0) to the source vertex.
 *     - For each adjacent vertex:
 *         - If uncolored, assign the opposite color.
 *         - If already colored with the same color as the current vertex,
 *           then the graph is NOT bipartite.
 * - If no conflicts are found, the graph is bipartite.
 *
 * Time Complexity:
 * ----------------
 * The BFS traversal visits each vertex and edge once.
 * - V = number of vertices
 * - E = number of edges
 * Time Complexity = O(V + E)
 *
 * Space Complexity:
 * -----------------
 * - O(V) for color array and queue
 * - O(V + E) for adjacency list representation
 */

import java.util.*;

public class BipartiteGraphCheck {

    // Add an undirected edge to the graph
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // BFS to check bipartite starting from src
    static boolean bipartiteBFS(int src, List<List<Integer>> adj, int[] color) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(src);
        color[src] = 1;  // Color the source with 1

        while (!queue.isEmpty()) {
            int node = queue.poll();

            for (int neighbor : adj.get(node)) {
                if (color[neighbor] == -1) {
                    // Assign opposite color to neighbor
                    color[neighbor] = 1 - color[node];
                    queue.offer(neighbor);
                } else if (color[neighbor] == color[node]) {
                    // Same color adjacent found => not bipartite
                    return false;
                }
            }
        }
        return true;
    }

    // Check if the graph is bipartite
    static boolean isBipartite(int V, List<List<Integer>> adj) {
        int[] color = new int[V];
        Arrays.fill(color, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bipartiteBFS(i, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int V = 9;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Adding edges
        addEdge(adj, 8, 7);
        addEdge(adj, 0, 1);
        addEdge(adj, 1, 2);
        addEdge(adj, 2, 3);
        addEdge(adj, 3, 4);
        addEdge(adj, 4, 6);
        addEdge(adj, 6, 7);
        addEdge(adj, 1, 7);
        addEdge(adj, 4, 5);

        System.out.println("Is Graph Bipartite? " + isBipartite(V, adj));
    }
}