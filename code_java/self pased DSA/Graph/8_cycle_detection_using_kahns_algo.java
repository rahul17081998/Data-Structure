import java.util.*;
/*
 Approach:
 Detect cycle in a directed graph using Kahn's Algorithm (Topological Sort).
 - Calculate the in-degree (number of incoming edges) for each vertex.
 - Initialize a queue with all vertices having in-degree zero.
 - Remove vertices from the queue and reduce the in-degree of their adjacent vertices.
 - If any adjacent vertex’s in-degree becomes zero, add it to the queue.
 - Keep count of the number of vertices processed.
 - If the count is less than the total number of vertices, it means there is a cycle in the graph.
*/

public class CycleDetectionKahnsAlgo {

    // Add an edge in graph using adjacency list (directed)
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
    }

    // Detect cycle in directed graph using Kahn's Algorithm
    static boolean isCycle(List<List<Integer>> adj, int V) {
        int[] inDegree = new int[V];

        // Calculate in-degree of nodes
        for (int i = 0; i < V; i++) {
            for (int u : adj.get(i)) {
                inDegree[u]++;
            }
        }

        Queue<Integer> queue = new LinkedList<>();

        // Initially insert nodes into queue if in-degree is 0
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }

        int count = 0;

        while (!queue.isEmpty()) {
            int u = queue.poll();

            for (int v : adj.get(u)) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queue.add(v);
                }
            }

            count++;
        }

        // If count of visited nodes is not equal to total nodes, cycle is present
        return count != V;
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

        addEdge(adj, 0, 1);
        addEdge(adj, 4, 1);
        addEdge(adj, 3, 1);
        addEdge(adj, 3, 2);
        addEdge(adj, 2, 3);

        // printGraph(adj, V);

        System.out.print("Is cycle present: ");
        System.out.println(isCycle(adj, V));
    }
}