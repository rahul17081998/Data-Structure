/**
 * Problem Statement:
 * You are given an undirected, connected, and weighted graph with V vertices and E edges represented as an edge list.
 * Your task is to implement Prim's Algorithm to find the cost of the Minimum Spanning Tree (MST)
 * and print the edges that are part of this MST.
 *
 * Minimum Spanning Tree:
 * A Minimum Spanning Tree (MST) is a subset of the edges of a connected, undirected graph
 * that connects all the vertices together, without any cycles, and with the minimum possible total edge weight.
 *
 * What is Prim’s Algorithm?
 * - Prim’s Algorithm is a greedy algorithm used to find the MST.
 * - It starts with an arbitrary node and grows the MST one edge at a time by always choosing the edge
 *   with the smallest weight that connects a new unvisited node.
 * - The algorithm continues until all nodes are included in the MST.
 *
 * Approach:
 * 1. Convert the edge list to an adjacency list for efficient access.
 * 2. Use a PriorityQueue (min-heap) to pick the next edge with the smallest weight.
 * 3. Maintain a visited array to keep track of nodes already in the MST.
 * 4. Start from node 0 and add a dummy edge (from -1 to 0) to begin the algorithm.
 * 5. For each selected edge, if it leads to an unvisited node, add its neighboring edges to the queue.
 * 6. Add the chosen edge to the MST if it leads to an unvisited node.
 * 7. Print all the edges in the MST and its total weight.
 */

import java.util.*;

class Pair {
    int node;
    int weight;

    Pair(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}

class Edge {
    int from;
    int to;
    int weight;

    public Edge(int from, int to, int weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
}

public class PrimsAlgorithm {

    static void createMinimumSpanningTree(int[][] edges, int V) {
        // Step 1: Convert edge list to adjacency list
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj.get(u).add(new Pair(v, wt));
            adj.get(v).add(new Pair(u, wt));
        }

        // Step 2: Prim's Algorithm using Min Heap
        PriorityQueue<Edge> pq = new PriorityQueue<>((x, y) -> x.weight - y.weight);
        boolean[] isVisited = new boolean[V];
        pq.add(new Edge(-1, 0, 0)); // start with node 0

        int minMstCost = 0;
        List<Edge> mstEdges = new ArrayList<>();

        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            int node = e.to;
            int wt = e.weight;

            if (isVisited[node]) continue;

            minMstCost += wt;
            isVisited[node] = true;

            if (e.from != -1) {
                mstEdges.add(e); // add only real edges (skip the dummy start edge)
            }

            for (Pair neighbor : adj.get(node)) {
                if (!isVisited[neighbor.node]) {
                    pq.add(new Edge(node, neighbor.node, neighbor.weight));
                }
            }
        }

        // Step 3: Output the MST
        System.out.println("Edges in the MST:");
        for (Edge e : mstEdges) {
            System.out.println(e.from + " - " + e.to + " : " + e.weight);
        }
        System.out.println("Minimum cost to connect all vertices of MST: " + minMstCost);
    }

    public static void main(String[] args) {
        int V = 6;
        // Format: {from, to, weight}
        int[][] edges = {
                {0, 1, 3},
                {0, 3, 1},
                {1, 2, 1},
                {1, 3, 3},
                {2, 3, 1},
                {2, 4, 6},
                {3, 4, 5},
                {4, 5, 2}
        };
        createMinimumSpanningTree(edges, V);
    }
}