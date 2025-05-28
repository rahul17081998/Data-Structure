/*
Approach: Check if a graph is Bipartite using BFS coloring
-----------------------------------------------------------
- Initialize all vertices with color -1 (uncolored).
- For each uncolored vertex, perform BFS:
  - Color the source vertex with color 1.
  - For each adjacent vertex:
    - If uncolored, color it with the opposite color.
    - If already colored with the same color as the current vertex, graph is NOT bipartite.
- If no conflicts, graph is bipartite.
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