/*
 Approach:
 This program counts the number of islands (connected components) in an undirected graph using BFS.
 - Each unvisited node starts a new BFS traversal, representing a new island.
 - BFS marks all reachable nodes from the current node as visited.
 - The total number of BFS calls equals the number of islands in the graph.
*/
import java.util.*;

public class IslandCount {

    // Add an edge in graph using list
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // BFS
    static void BFS(List<List<Integer>> adj, int s, boolean[] visited) {
        Queue<Integer> q = new LinkedList<>();
        visited[s] = true;
        q.add(s);

        while (!q.isEmpty()) {
            int u = q.poll();
            for (int i : adj.get(u)) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
    }

    // BFS for disconnected graph
    static int BFSDis(List<List<Integer>> adj, int v) {
        boolean[] visited = new boolean[v];
        int count = 0;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                BFS(adj, i, visited);
                count++;
            }
        }
        return count;
    }

    // Print graph
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
        // addEdge(adj, 1, 2);
        addEdge(adj, 1, 3);
        addEdge(adj, 2, 3);
        addEdge(adj, 4, 5);
        addEdge(adj, 4, 6);
        addEdge(adj, 5, 6);

        // System.out.println("print adjacency list");
        // printGraph(adj, v);

        System.out.println("\nNo of islands --> " + BFSDis(adj, v));
    }
}