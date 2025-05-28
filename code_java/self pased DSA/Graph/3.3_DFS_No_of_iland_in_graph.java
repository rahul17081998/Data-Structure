import java.util.*;

/*
 Approach:
 This program counts the number of disconnected components ("islands") in an undirected graph using DFS.
 - Represent the graph using an adjacency list.
 - Use a visited array to track visited nodes.
 - For each unvisited node, start a DFS, marking all reachable nodes.
 - Each DFS call from an unvisited node represents a new connected component.
 - Count these DFS initiations to determine the number of islands.
*/
public class DFSIslandCount {

    // Add an edge in the graph using adjacency list
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // DFS recursive function
    static void DFSrec(List<List<Integer>> adj, int s, boolean[] visited) {
        visited[s] = true;
        for (int u : adj.get(s)) {
            if (!visited[u]) {
                DFSrec(adj, u, visited);
            }
        }
    }

    // DFS for disconnected graph (counting connected components)
    static int DFS(List<List<Integer>> adj, int v) {
        boolean[] visited = new boolean[v];
        int count = 0;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                count++;
                DFSrec(adj, i, visited);
            }
        }
        return count;
    }

    // Print the graph
    static void printGraph(List<List<Integer>> adj) {
        for (int i = 0; i < adj.size(); i++) {
            System.out.print(i + " : ");
            for (int x : adj.get(i)) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int v = 2;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }

        addEdge(adj, 0, 0);
        addEdge(adj, 1, 1);
        // addEdge(adj, 1, 2);
        // addEdge(adj, 1, 3);
        // addEdge(adj, 2, 3);
        // addEdge(adj, 4, 5);
        // addEdge(adj, 4, 6);
        // addEdge(adj, 5, 6);

        // printGraph(adj);
        System.out.println("\nNo of islands in graph --> " + DFS(adj, v));
    }
}