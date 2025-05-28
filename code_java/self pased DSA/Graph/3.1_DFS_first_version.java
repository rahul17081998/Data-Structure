/*
 Approach:
 Perform Depth-First Search (DFS) traversal on a connected undirected graph.
 - Recursively visit each node starting from the given source vertex.
 - Mark nodes as visited to avoid revisiting.
 - Explore as far as possible along each branch before backtracking.
*/
import java.util.*;

public class DFSExample {

    // Add an edge in graph using list
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // DFS recursive function
    static void DFSrec(List<List<Integer>> adj, int s, boolean[] visited) {
        visited[s] = true;
        System.out.print(s + " ");
        for (int u : adj.get(s)) {
            if (!visited[u]) {
                DFSrec(adj, u, visited);
            }
        }
    }

    // DFS wrapper
    static void DFS(List<List<Integer>> adj, int v, int s) {
        boolean[] visited = new boolean[v];
        DFSrec(adj, s, visited);
    }

    // Print the graph
    static void printGraph(List<List<Integer>> adj, int v) {
        for (int i = 0; i < v; i++) {
            System.out.print(i + " : ");
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
        addEdge(adj, 1, 2);
        addEdge(adj, 2, 3);
        addEdge(adj, 0, 4);
        addEdge(adj, 4, 5);
        addEdge(adj, 4, 6);

        printGraph(adj, v);

        int s = 1; // source
        System.out.println();
        DFS(adj, v, s);
    }
}