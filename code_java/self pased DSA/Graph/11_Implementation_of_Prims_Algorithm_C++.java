import java.util.Arrays;
/*
 Approach:
 Implementation of Prim's Algorithm to find the Minimum Spanning Tree (MST) of a connected, weighted undirected graph.
 - Start from an arbitrary vertex (here, vertex 0).
 - Maintain a key array to track the minimum weight edge to include a vertex in MST.
 - Maintain a set (mSet) to track vertices included in MST.
 - In each iteration, pick the vertex not yet included with the smallest key value.
 - Update the key values of adjacent vertices if a smaller edge is found.
 - Repeat until all vertices are included.
 - The sum of the key values of the included vertices gives the MST cost.
*/
public class PrimsAlgorithm {

    static final int V = 4;

    // Function to find the MST sum using Prim's Algorithm
    static int primMST(int[][] graph) {
        int[] key = new int[V];      // Key values used to pick minimum weight edge
        boolean[] mSet = new boolean[V];  // To represent set of vertices included in MST

        Arrays.fill(key, Integer.MAX_VALUE);
        key[0] = 0;  // Start from first vertex
        int res = 0;

        for (int count = 0; count < V; count++) {
            int u = -1;

            // Pick the minimum key vertex from the set of vertices not yet included in MST
            for (int i = 0; i < V; i++) {
                if (!mSet[i] && (u == -1 || key[i] < key[u])) {
                    u = i;
                }
            }

            mSet[u] = true;
            res += key[u];

            // Update key values of adjacent vertices of picked vertex
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && !mSet[v] && graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[][] graph = {
            {0, 5, 8, 0},
            {5, 0, 10, 15},
            {8, 10, 0, 20},
            {0, 15, 20, 0}
        };

        System.out.println("Minimum cost to connect all vertices: " + primMST(graph));
    }
}