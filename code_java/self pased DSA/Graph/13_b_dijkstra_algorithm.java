import java.util.*;

/**
 * Problem Statement:
 * ------------------
 * Given a weighted, undirected graph with V vertices and E edges,
 * find the shortest distance from a given source vertex to all other vertices
 * using Dijkstra's Algorithm.
 *
 * Constraints:
 * ------------
 * - The graph contains non-negative edge weights.
 * - The graph may contain cycles.
 * - The graph is connected (every node is reachable from the source).
 *
 * What is Dijkstra’s Algorithm?
 * -----------------------------
 * Dijkstra's Algorithm is a classic greedy algorithm used to compute the shortest
 * paths from a single source vertex to all other vertices in a weighted graph.
 * It always selects the next vertex with the smallest tentative distance,
 * and relaxes all its adjacent vertices.
 *
 * It works with:
 * - Undirected or directed graphs.
 * - Only non-negative edge weights.
 *
 * Time Complexity:
 * ----------------
 * - Using a min-heap (priority queue): O((V + E) log V)
 *
 * Approach:
 * ---------
 * 1. Convert the edge list into an adjacency list to represent the graph.
 * 2. Initialize a distance array `dist[]` where each value is set to infinity
 *    (except the source node which is set to 0).
 * 3. Use a PriorityQueue (min-heap) to always process the node with the current
 *    shortest distance.
 * 4. For each node processed, iterate over its neighbors:
 *    - If the distance to a neighbor through the current node is smaller, update it.
 *    - Add the updated neighbor to the priority queue.
 * 5. Repeat until the queue is empty.
 * 6. Output the shortest distance from the source to each vertex.
 */

class Pair {
    int node;
    int wt;

    public Pair(int node, int wt) {
        this.node = node;
        this.wt = wt;
    }
}

public class DijkstraAlgorithm {

    /**
     * Function to compute shortest distances from a source node using Dijkstra's Algorithm.
     *
     * @param edges 2D array where each element is {u, v, weight} representing an edge
     * @param source the starting vertex for shortest path calculation
     * @param V number of vertices in the graph
     */
    public static void dijkstra(int[][] edges, int source, int V) {
        // Step 1: Convert edge list to adjacency list
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj.get(u).add(new Pair(v, wt));
            adj.get(v).add(new Pair(u, wt)); // since the graph is undirected
        }

        // Step 2: Initialize distance array and priority queue
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.wt - b.wt);
        pq.add(new Pair(source, 0));

        // Step 3: Dijkstra’s main loop
        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int u = curr.node;
            int d = curr.wt;

            // Optional optimization to skip stale entries
            if (d > dist[u]) continue;

            // Relax all adjacent edges
            for (Pair neighbor : adj.get(u)) {
                int v = neighbor.node;
                int wt = neighbor.wt;

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.add(new Pair(v, dist[v]));
                }
            }
        }

        // Step 4: Output distances
        System.out.println("Shortest distances from source node " + source + ":");
        for (int i = 0; i < V; i++) {
            System.out.println("To node " + i + " : " + dist[i]);
        }
    }

    /**
     * Main method to run the Dijkstra algorithm with example input.
     */
    public static void main(String[] args) {
        int V = 6;
        int source = 0;

        // Each element: {from, to, weight}
        int[][] edges = {
                {0, 1, 4},
                {0, 2, 1},
                {2, 1, 2},
                {1, 3, 1},
                {2, 3, 5},
                {3, 4, 3},
                {4, 5, 1}
        };

        dijkstra(edges, source, V);
    }
}