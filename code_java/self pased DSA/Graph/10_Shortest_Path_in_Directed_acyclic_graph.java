import java.util.*;
/*
 Approach:
 Find the shortest path in a Directed Acyclic Graph (DAG) using topological sorting.
 - Perform a topological sort of the graph using DFS.
 - Initialize distances from the source to all vertices as infinity, except the source itself which is zero.
 - Process vertices in topological order:
    - For each vertex, relax all edges going out from it, updating the shortest distances.
 - This works efficiently for DAGs since there are no cycles, and each vertex is processed once in topological order.
*/
public class ShortestPathInDAG {

    static class Edge {
        int to, weight;
        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    // Add directed edge u->v with given weight
    static void addEdge(List<List<Edge>> adj, int u, int v, int weight) {
        adj.get(u).add(new Edge(v, weight));
    }

    // Perform topological sort using DFS
    static void topologicalSort(int u, boolean[] visited, Deque<Integer> stack, List<List<Edge>> adj) {
        visited[u] = true;
        for (Edge edge : adj.get(u)) {
            if (!visited[edge.to]) {
                topologicalSort(edge.to, visited, stack, adj);
            }
        }
        stack.push(u);
    }

    // Find shortest paths from source to all vertices in DAG
    static void shortestPath(int src, List<List<Edge>> adj, int V) {
        boolean[] visited = new boolean[V];
        Deque<Integer> stack = new ArrayDeque<>();

        // Topological sort all vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSort(i, visited, stack, adj);
            }
        }

        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        // Process vertices in topological order
        while (!stack.isEmpty()) {
            int u = stack.pop();

            if (dist[u] != Integer.MAX_VALUE) {
                for (Edge edge : adj.get(u)) {
                    if (dist[edge.to] > dist[u] + edge.weight) {
                        dist[edge.to] = dist[u] + edge.weight;
                    }
                }
            }
        }

        // Print shortest distances
        System.out.println("Vertex\tDistance from Source " + src);
        for (int i = 0; i < V; i++) {
            if (dist[i] == Integer.MAX_VALUE)
                System.out.println(i + "\t\t" + "INF");
            else
                System.out.println(i + "\t\t" + dist[i]);
        }
    }

    public static void main(String[] args) {
        int V = 6;
        List<List<Edge>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        addEdge(adj, 0, 1, 5);
        addEdge(adj, 0, 2, 3);
        addEdge(adj, 1, 3, 6);
        addEdge(adj, 1, 2, 2);
        addEdge(adj, 2, 4, 4);
        addEdge(adj, 2, 5, 2);
        addEdge(adj, 2, 3, 7);
        addEdge(adj, 3, 4, -1);
        addEdge(adj, 4, 5, -2);

        int source = 1;
        shortestPath(source, adj, V);
    }
}