/*
 Approach:
 To perform BFS on a disconnected undirected graph:
 - Use a visited array to track nodes that have been explored.
 - Loop through all vertices; if a vertex hasn't been visited, start a BFS from it.
 - This ensures all disconnected components are covered.
*/
import java.util.*;

public class DisconnectedGraphBFS {

    // Add an edge in the graph
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // BFS for a connected component
    static void BFS(List<List<Integer>> adj, int s, boolean[] visited) {
        Queue<Integer> q = new LinkedList<>();
        visited[s] = true;
        q.add(s);

        while (!q.isEmpty()) {
            int u = q.poll();
            System.out.print(u + " ");
            for (int i : adj.get(u)) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
    }

    // BFS for disconnected graph
    static void BFSDis(List<List<Integer>> adj, int v) {
        boolean[] visited = new boolean[v];
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                BFS(adj, i, visited);
            }
        }
    }

    // Print the graph
    static void printGraph(List<List<Integer>> adj, int v) {
        for (int i = 0; i < v; i++) {
            for (int x : adj.get(i)) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int v = 7;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }

        addEdge(adj, 0, 1);
        addEdge(adj, 0, 2);
        addEdge(adj, 1, 3);
        addEdge(adj, 2, 3);
        addEdge(adj, 4, 5);
        addEdge(adj, 4, 6);
        addEdge(adj, 5, 6);

        BFSDis(adj, v);
    }
}