/*
 Approach:
 Detect cycle in an undirected graph using DFS.
 - Start DFS from each unvisited node.
 - For every adjacent node:
   - If it is unvisited, recursively DFS it.
   - If it is visited and not the parent of the current node, a cycle is detected.
 - Repeat for all components of the graph.
*/
import java.util.*;

public class DetectCycleUndirectedGraph {

    // Add an edge in graph using list
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // Detect cycle in undirected graph
    static boolean DFSRec(List<List<Integer>> adj, int s, int[] vis, int parent) {
        vis[s] = 1;
        for (int u : adj.get(s)) {
            if (vis[u] == 0) {
                if (DFSRec(adj, u, vis, s)) {
                    return true;
                }
            } else if (u != parent) {
                return true;
            }
            // else parent then ignore
        }
        return false;
    }

    static boolean isCycle(List<List<Integer>> adj, int v) {
        int[] vis = new int[v];
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                if (DFSRec(adj, i, vis, -1)) {
                    return true; // cycle detected
                }
            }
        }
        return false; // cycle not found
    }

    // print graph
    static void printGraph(List<List<Integer>> adj, int v) {
        for (int i = 0; i < v; i++) {
            for (int x : adj.get(i)) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int v = 5;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }
        // cycle is present for below input
        addEdge(adj, 0, 1);
        addEdge(adj, 0, 2);
        addEdge(adj, 1, 2);
        addEdge(adj, 1, 3);
        addEdge(adj, 2, 3);
        addEdge(adj, 2, 4);

        // cycle is not present for below input
        // addEdge(adj, 0, 1);
        // addEdge(adj, 1, 4);
        // addEdge(adj, 1, 2);
        // addEdge(adj, 2, 3);
        // printGraph(adj, v);

        System.out.println("\nIs cycle detected: " + isCycle(adj, v));
    }
}