import java.util.*;
/*
 Approach:
 Prim's Algorithm to find the Minimum Spanning Tree (MST) of a weighted undirected graph.
 - Initialize all keys as infinite and mstSet[] as false to track included vertices.
 - Start from vertex 0, set its key to 0 to pick it first.
 - Repeatedly pick the vertex with the minimum key value that is not yet included in MST.
 - Include this vertex in MST and update the key values of its adjacent vertices.
 - The parent[] array stores the MST edges.
 - Finally, print the MST edges.
*/
public class PrimsAlgorithm {

    static class Pair {
        int vertex;
        int weight;
        Pair(int v, int w) {
            vertex = v;
            weight = w;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // Number of vertices
        int m = sc.nextInt(); // Number of edges

        // Adjacency list representation: array of lists of pairs (neighbor, weight)
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int wt = sc.nextInt();
            adj.get(a).add(new Pair(b, wt));
            adj.get(b).add(new Pair(a, wt));
        }

        int[] parent = new int[N];
        int[] key = new int[N];
        boolean[] mstSet = new boolean[N];

        Arrays.fill(key, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);

        key[0] = 0;  // Start from vertex 0

        for (int count = 0; count < N - 1; count++) {
            int mini = Integer.MAX_VALUE;
            int u = -1;

            // Pick vertex u not in mstSet with minimum key value
            for (int v = 0; v < N; v++) {
                if (!mstSet[v] && key[v] < mini) {
                    mini = key[v];
                    u = v;
                }
            }

            mstSet[u] = true;

            // Update keys of adjacent vertices of u
            for (Pair it : adj.get(u)) {
                int v = it.vertex;
                int weight = it.weight;

                if (!mstSet[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }

        // Print MST edges
        for (int i = 1; i < N; i++) {
            System.out.println(parent[i] + " - " + i);
        }

        sc.close();
    }
}