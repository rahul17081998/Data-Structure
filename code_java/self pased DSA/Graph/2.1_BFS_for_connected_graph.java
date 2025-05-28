/*
 Approach:
 Perform Breadth-First Search (BFS) on a connected undirected graph.
 - Use a queue to explore nodes level by level.
 - Track visited nodes using a boolean array to avoid revisiting.
 - Start from the given source vertex and explore all reachable nodes.
*/
import java.util.*;

public class GraphBFS {
    // Add an edge in the graph
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // BFS traversal
    static void BFS(List<List<Integer>> adj, int v, int s) {
        boolean[] visited = new boolean[v];
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

    // Print the adjacency list
    static void printGraph(List<List<Integer>> adj, int v) {
        for (int i = 0; i < v; i++) {
            for (int x : adj.get(i)) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int v = 4;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }

        addEdge(adj, 0, 1);
        addEdge(adj, 0, 2);
        addEdge(adj, 1, 2);
        addEdge(adj, 2, 3);

        printGraph(adj, v);
        int s = 3; // source
        System.out.print("source vertex " + s + " visited: ");
        BFS(adj, v, s);
    }
}