/*
 Approach:
 Topological sorting of a Directed Acyclic Graph (DAG) using Kahn's Algorithm (BFS-based).
 - Calculate in-degree (number of incoming edges) for every vertex.
 - Initialize a queue and enqueue all vertices with in-degree 0.
 - While the queue is not empty:
    - Dequeue a vertex and add it to the topological order.
    - For each adjacent vertex, reduce its in-degree by 1.
    - If in-degree of adjacent vertex becomes 0, enqueue it.
 - This process ensures nodes are processed only after their dependencies.
*/

import java.util.*;

public class TopologicalSortBFS {

    // Add an edge in graph using adjacency list (directed)
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
    }

    // Topological Sorting using BFS (Kahn's Algorithm)
    static void topologicalSorting(List<List<Integer>> adj, int V) {
        int[] inDegree = new int[V];

        // Calculate in-degree of nodes
        for (int i = 0; i < V; i++) {
            for (int u : adj.get(i)) {
                inDegree[u]++;
            }
        }

        Queue<Integer> queue = new LinkedList<>();

        // Insert nodes into queue if in-degree is 0
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }

        while (!queue.isEmpty()) {
            int u = queue.poll();
            System.out.print(u + " ");

            // Decrease in-degree by 1 for all adjacent of u
            for (int v : adj.get(u)) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queue.add(v);
                }
            }
        }
    }

    // Print graph adjacency list
    static void printGraph(List<List<Integer>> adj, int V) {
        System.out.println("S :\t D\n");
        for (int i = 0; i < V; i++) {
            System.out.print(i + " : \t");
            for (int x : adj.get(i)) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int V = 5;
        List<List<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        addEdge(adj, 0, 2);
        addEdge(adj, 0, 3);
        addEdge(adj, 2, 3);
        addEdge(adj, 1, 3);
        addEdge(adj, 1, 4);

        // printGraph(adj, V);

        System.out.println("Topological sorting of the graph");
        topologicalSorting(adj, V);
        System.out.println();
    }
}