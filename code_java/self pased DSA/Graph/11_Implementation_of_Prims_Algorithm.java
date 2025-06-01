/**
 * Problem Statement:
 * You are given an undirected, connected, and weighted graph with V vertices and E edges represented as an edge list.
 * Your task is to implement Prim's Algorithm to find the cost of the Minimum Spanning Tree (MST).
 *
 * About Prim's Algorithm:
 * Prim's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph.
 * The MST is a subset of edges that connects all vertices in the graph with the minimum possible total edge weight and without any cycles.
 * Prim’s Algorithm works by starting from an arbitrary vertex and expanding the MST one vertex at a time by choosing the smallest edge
 * that connects a new vertex to the growing MST.
 *
 * Example:
 * Input:
 * V = 5
 * edges = {
 *   {0, 1, 2},
 *   {0, 2, 1},
 *   {1, 2, 1},
 *   {2, 3, 2},
 *   {3, 4, 1},
 *   {4, 2, 2}
 * }
 *
 * Output:
 * Minimum cost to connect all vertices of MST: 5
 *
 * Approach for Implementation:
 * 1. Convert the edge list into an adjacency list for efficient graph traversal.
 * 2. Use a PriorityQueue (min-heap) to always pick the next edge with the minimum weight.
 * 3. Maintain a visited array to track which nodes have already been included in the MST.
 * 4. Start from an arbitrary node (commonly node 0) and push its adjacent edges into the priority queue.
 * 5. At each step, pick the smallest weight edge that connects a new node to the growing MST.
 * 6. Repeat until all nodes are visited and included in the MST.
 */
import java.util.*;

class Pair {
    int node;
    int distance;

    Pair(int node, int distance) {
        this.node = node;
        this.distance = distance;
    }
}

public class PrimsAlgorithm {

    static void createMinimumSpanningTree(int[][] edges, int V) {
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());

        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj.get(u).add(new Pair(v, wt));
            adj.get(v).add(new Pair(u, wt));
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> x.distance - y.distance);
        boolean[] isVisited = new boolean[V];
        pq.add(new Pair(0, 0));

        int sum = 0;
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int node = p.node;
            int wt = p.distance;

            if (isVisited[node]) continue;

            sum += wt;
            isVisited[node] = true;

            for (Pair newp : adj.get(node)) {
                int nNode = newp.node;
                int nWt = newp.distance;
                if (!isVisited[nNode]) {
                    pq.add(new Pair(nNode, nWt));
                }
            }
        }
        System.out.println("Minimum cost to connect all vertices of MST: " + sum);
    }

    public static void main(String[] args) {
        int V = 5;
        int[][] edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
        createMinimumSpanningTree(edges, V);
    }
}}