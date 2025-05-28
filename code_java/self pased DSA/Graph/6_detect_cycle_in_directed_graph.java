/*
 Approach:
 Detect cycle in a directed graph using DFS with recursion stack.
 - Use two boolean arrays: 'visited' to mark visited nodes, and 'recStack' to track nodes in the current recursion stack.
 - For each unvisited node, perform DFS:
    - Mark the node as visited and add it to recursion stack.
    - For every adjacent node:
       - If not visited, recursively DFS it.
       - If already in recursion stack, a cycle is detected.
    - Remove the node from recursion stack after exploring neighbors.
 - If any cycle detected during DFS, return true; else false.
*/

import java.util.*;

public class DetectCycleInDirectedGraph {

    // Add an edge in graph using adjacency list
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
    }

    // Recursive DFS to detect cycle
    static boolean DFSRec(List<List<Integer>> adj, int s, boolean[] visited, boolean[] recStack) {
        visited[s] = true;
        recStack[s] = true;

        for (int u : adj.get(s)) {
            if (!visited[u] && DFSRec(adj, u, visited, recStack))
                return true;
            else if (recStack[u])
                return true;
        }

        recStack[s] = false;
        return false;
    }

    // Check if cycle exists in the graph
    static boolean isCycle(List<List<Integer>> adj, int v) {
        boolean[] visited = new boolean[v];
        boolean[] recStack = new boolean[v];

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (DFSRec(adj, i, visited, recStack))
                    return true;
            }
        }
        return false;
    }

    // Print graph
    static void printGraph(List<List<Integer>> adj, int v) {
        System.out.println("S :\t D\n");
        for (int i = 0; i < v; i++) {
            System.out.print(i + " : \t");
            for (int x : adj.get(i))
                System.out.print(x + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int v = 6;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }

        addEdge(adj, 0, 1);
        addEdge(adj, 2, 1);
        addEdge(adj, 2, 3);
        addEdge(adj, 3, 4);
        addEdge(adj, 4, 5);
        addEdge(adj, 5, 3);

        printGraph(adj, v);

        System.out.println("\nIs cycle detected: " + isCycle(adj, v));
    }
}