import java.util.Arrays;
/*
 Approach:
 This implementation of Dijkstra's algorithm finds the shortest path from a source vertex
 to all other vertices in a weighted graph represented by an adjacency matrix.

 - Initialize distances with infinity except the source vertex which is set to 0.
 - Use a boolean array to keep track of vertices for which the shortest distance is finalized.
 - Repeatedly pick the unvisited vertex with the smallest tentative distance.
 - Update the distances of its adjacent vertices if a shorter path is found through the picked vertex.
 - Continue until all vertices have been finalized.
 - This implementation has O(V^2) time complexity due to scanning all vertices to find the minimum distance.
*/
public class DijkstraAlgorithm {

    static final int V = 4;

    static int[] dijkstra(int[][] graph, int src) {
        int[] dist = new int[V];
        boolean[] fin = new boolean[V];

        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int mini = Integer.MAX_VALUE, u = -1;

            // Pick vertex u not finalized with minimum dist[u]
            for (int i = 0; i < V; i++) {
                if (!fin[i] && dist[i] < mini) {
                    mini = dist[i];
                    u = i;
                }
            }

            fin[u] = true;

            // Update dist[v] if new shorter path found through u
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && !fin[v] && dist[u] != Integer.MAX_VALUE
                        && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int[][] graph = {
            {0, 50, 100, 0},
            {50, 0, 30, 200},
            {100, 30, 0, 20},
            {0, 200, 20, 0}
        };

        int src = 0;
        int[] dist = dijkstra(graph, src);

        for (int d : dist) {
            System.out.print(d + " ");
        }
        System.out.println();
    }
}