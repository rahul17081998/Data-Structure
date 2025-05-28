/*
 Approach:
 To perform DFS on a disconnected undirected graph:
 - Use a visited array to keep track of visited vertices.
 - Loop through all vertices; if a vertex hasn't been visited, start DFS from it.
 - This ensures all disconnected components are explored.
*/
import java.util.*;

public class DisconnectedDFS {

    // Add an edge in the graph
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

    // DFS for disconnected graph
    static void DFS(List<List<Integer>> adj, int v) {
        boolean[] visited = new boolean[v];
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                DFSrec(adj, i, visited);
            }
        }
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
        addEdge(adj, 0, 2);
        addEdge(adj, 1, 3);
        addEdge(adj, 2, 3);
        addEdge(adj, 4, 5);
        addEdge(adj, 4, 6);
        addEdge(adj, 5, 6);

        // printGraph(adj, v);
        DFS(adj, v);
    }
}