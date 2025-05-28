import java.util.*;
/*
 Approach:
 Perform Topological Sorting on a Directed Acyclic Graph (DAG) using DFS.
 - Visit each unvisited node and recursively explore its neighbors.
 - After visiting all neighbors of a node, push the node onto a stack.
 - Once all nodes are processed, popping from the stack gives the topological order.
 - This ensures nodes appear before all nodes they point to.
*/

public class TopologicalSortDFS {

    // Add an edge in graph (directed)
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
    }

    // DFS utility to perform topological sort
    static void DFS(List<List<Integer>> adj, int u, boolean[] visited, Deque<Integer> stack) {
        visited[u] = true;

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                DFS(adj, v, visited, stack);
            }
        }

        // Push current vertex to stack after visiting all adjacent vertices
        stack.push(u);
    }

    // Function to perform topological sorting using DFS
    static void topologicalSorting(List<List<Integer>> adj, int V) {
        boolean[] visited = new boolean[V];
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited, stack);
            }
        }

        // Print contents of the stack
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }

    public static void main(String[] args) {
        int V = 5;
        List<List<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        addEdge(adj, 0, 1);
        addEdge(adj, 1, 3);
        addEdge(adj, 3, 4);
        addEdge(adj, 2, 3);
        addEdge(adj, 3, 4);

        System.out.println("Topological sorting of the graph");
        topologicalSorting(adj, V);
    }
}