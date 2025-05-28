/*
 Approach:
 This program finds the shortest path from a source node to all other nodes in an unweighted undirected graph using BFS.
 - Use a queue to perform level-order traversal starting from the source.
 - Initialize all distances to infinity, then update distances as levels are visited.
 - Since all edges have equal weight (1), BFS guarantees the shortest path in terms of number of edges.
*/
import java.util.*;

public class ShortestPathUnweightedGraph {

    // Add an edge in graph using adjacency list (undirected)
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // Shortest path from source using BFS
    static void shortestPath(List<List<Integer>> adj, int s, int v) {
        int[] dist = new int[v];
        boolean[] visited = new boolean[v];

        Arrays.fill(dist, Integer.MAX_VALUE);
        Arrays.fill(visited, false);

        dist[s] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(s);
        visited[s] = true;

        while (!q.isEmpty()) {
            int u = q.poll();
            for (int neighbor : adj.get(u)) {
                if (!visited[neighbor]) {
                    dist[neighbor] = dist[u] + 1;
                    visited[neighbor] = true;
                    q.offer(neighbor);
                }
            }
        }

        // Print distances
        for (int i = 0; i < v; i++) {
            System.out.print(dist[i] + " ");
        }
        System.out.println();
    }

    // Alternative BFS shortest path method (TUF method)
    static void BFS_shortest_dist(int src, List<List<Integer>> adj, int V) {
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);

        Queue<Integer> q = new LinkedList<>();
        q.offer(src);
        dist[src] = 0;

        while (!q.isEmpty()) {
            int node = q.poll();

            for (int neighbor : adj.get(node)) {
                if (dist[node] + 1 < dist[neighbor]) {
                    dist[neighbor] = dist[node] + 1;
                    q.offer(neighbor);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            System.out.print(dist[i] + " ");
        }
        System.out.println();
    }

    // Print the graph adjacency list
    static void printGraph(List<List<Integer>> adj, int v) {
        for (int i = 0; i < v; i++) {
            System.out.print(i + ": ");
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
        addEdge(adj, 1, 3);
        addEdge(adj, 2, 3);

        // Uncomment to print adjacency list
        // printGraph(adj, v);

        int src = 0;
        System.out.print("Shortest path from source " + src + " is: ");
        shortestPath(adj, src, v);

        System.out.print("Shortest path from source " + src + " is: ");
        BFS_shortest_dist(src, adj, v);
    }
}