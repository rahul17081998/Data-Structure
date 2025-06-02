import java.util.*;

/**
 * Kruskal's Algorithm – Minimum Spanning Tree (MST)
 * -------------------------------------------------
 *
 * Problem Statement:
 * ------------------
 * Given a connected, undirected, and weighted graph, find the Minimum Spanning Tree (MST).
 * An MST connects all vertices with the minimum total edge weight and no cycles.
 *
 * What is Kruskal's Algorithm?
 * ----------------------------
 * Kruskal’s Algorithm is a greedy algorithm that builds the MST by always choosing the
 * next lightest edge that doesn’t form a cycle. It uses **Disjoint Set Union (Union-Find)**
 * to detect cycles efficiently.
 *
 * Time Complexity: O(E log E + E α(N)) ≈ O(E log E)
 * - E log E: sorting the edges
 * - E α(N): amortized time for Union-Find operations (α is the inverse Ackermann function)
 *
 * Benefits:
 * ---------
 * ✅ Easy to implement
 * ✅ Efficient for sparse graphs
 * ✅ Can be stopped early when MST has (V - 1) edges
 *
 * Approach:
 * ---------
 * 1. Sort all edges by increasing weight.
 * 2. Initialize a Disjoint Set (Union-Find) for all vertices.
 * 3. Iterate over each edge (u, v, wt):
 *    - If u and v belong to different components (no cycle), include the edge in the MST.
 *    - Union their sets.
 * 4. Stop when MST has (V - 1) edges.
 * 5. Sum of weights of the included edges gives the total MST cost.
 */

class Edge implements Comparable<Edge> {
    int u, v, wt;

    Edge(int u, int v, int wt) {
        this.u = u;
        this.v = v;
        this.wt = wt;
    }

    public int compareTo(Edge other) {
        return Integer.compare(this.wt, other.wt);
    }
}

public class KruskalAlgorithm {

    // Disjoint Set: Find representative (root) with path compression
    static int findParent(int x, int[] parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }

    // Disjoint Set: Union by rank
    static void union(int x, int y, int[] parent, int[] rank) {
        int xRoot = findParent(x, parent);
        int yRoot = findParent(y, parent);

        if (xRoot == yRoot) return;

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[xRoot] = yRoot;
            rank[yRoot]++;
        }
    }

    // Function to perform Kruskal's Algorithm
    static void kruskalMST(int V, List<Edge> edges) {
        Collections.sort(edges); // Step 1: Sort edges by weight

        int[] parent = new int[V];
        int[] rank = new int[V];

        // Step 2: Initialize Union-Find structure
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int cost = 0;
        List<Edge> mst = new ArrayList<>();

        // Step 3: Iterate through sorted edges
        for (Edge e : edges) {
            int uRep = findParent(e.u, parent);
            int vRep = findParent(e.v, parent);

            if (uRep != vRep) {
                mst.add(e);
                cost += e.wt;
                union(uRep, vRep, parent, rank);
            }
        }

        // Step 4: Output the MST
        System.out.println("Edges in the Minimum Spanning Tree:");
        for (Edge e : mst) {
            System.out.println(e.u + " - " + e.v + " : " + e.wt);
        }
        System.out.println("Total cost of MST: " + cost);
    }

    public static void main(String[] args) {
        int V = 5;
        List<Edge> edges = Arrays.asList(
                new Edge(0, 1, 2),
                new Edge(0, 3, 6),
                new Edge(1, 2, 3),
                new Edge(1, 3, 8),
                new Edge(1, 4, 5),
                new Edge(2, 4, 7)
        );

        kruskalMST(V, edges);
    }
}