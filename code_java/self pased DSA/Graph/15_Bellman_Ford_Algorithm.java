import java.util.*;
/*
 Approach:
 Bellman-Ford algorithm finds the shortest path from a single source to all vertices in a weighted graph, even if edges have negative weights.
 - Initialize distances from the source to all vertices as infinite except source itself (distance 0).
 - Relax all edges N-1 times, where N is the number of vertices.
 - Relaxation updates the distance to a vertex if a shorter path is found via an edge.
 - After N-1 relaxations, check for negative weight cycles by verifying if any edge can still be relaxed.
 - If a negative cycle exists, report it; otherwise, print the shortest distances.
*/

class Edge {
    int u, v, wt;
    Edge(int u, int v, int wt) {
        this.u = u;
        this.v = v;
        this.wt = wt;
    }
}

public class BellmanFordAlgorithm {

    public static void main(String[] args) {
        int N = 6; // Number of nodes
        List<Edge> edges = new ArrayList<>();
        edges.add(new Edge(0, 1, 5));
        edges.add(new Edge(1, 2, -2));
        edges.add(new Edge(1, 5, -3));
        edges.add(new Edge(2, 4, 3));
        edges.add(new Edge(3, 2, 6));
        edges.add(new Edge(3, 4, -2));
        edges.add(new Edge(5, 3, 1));

        int src = 0; // source
        int INF = 1_000_000;
        int[] dist = new int[N];
        Arrays.fill(dist, INF);
        dist[src] = 0;

        // Relax edges N-1 times
        for (int i = 1; i <= N - 1; i++) {
            for (Edge edge : edges) {
                if (dist[edge.u] != INF && dist[edge.u] + edge.wt < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.wt;
                }
            }
        }

        // Check for negative weight cycle
        boolean negativeCycle = false;
        for (Edge edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.wt < dist[edge.v]) {
                System.out.println("Negative cycle.");
                negativeCycle = true;
                break;
            }
        }

        // If no negative cycle, print distances
        if (!negativeCycle) {
            for (int i = 0; i < N; i++) {
                System.out.print(dist[i] + " ");
            }
            System.out.println();
        }
    }
}