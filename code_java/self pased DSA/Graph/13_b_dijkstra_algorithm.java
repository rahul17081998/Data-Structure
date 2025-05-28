import java.util.*;
/*
 Approach:
 Dijkstra's Algorithm to find the shortest distance from a source vertex to all other vertices in a weighted graph.
 - Initialize distances to all vertices as infinity, except the source which is zero.
 - Use a priority queue (min-heap) to greedily pick the vertex with the smallest tentative distance.
 - For each picked vertex, relax all its adjacent edges:
   - Update the distance if a shorter path is found.
   - Add the adjacent vertex with the updated distance into the priority queue.
 - Repeat until all vertices are processed.
 - The algorithm handles graphs with non-negative edge weights.
*/

public class Solution {

    // Function to find the shortest distance of all vertices from source S
    public int[] dijkstra(int V, List<List<int[]>> adj, int S) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[S] = 0;
        pq.offer(new int[] {0, S}); // {distance, node}

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int node = top[1];
            int currDist = top[0];

            if (currDist > dist[node]) continue; // Ignore if we already have a shorter distance

            for (int[] neighbour : adj.get(node)) {
                int v = neighbour[0];
                int weight = neighbour[1];

                if (dist[v] > dist[node] + weight) {
                    dist[v] = dist[node] + weight;
                    pq.offer(new int[] {dist[v], v});
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int V = sc.nextInt();
        int E = sc.nextInt();

        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();

            adj.get(u).add(new int[]{v, w});
            adj.get(v).add(new int[]{u, w});
        }

        int S = sc.nextInt();

        Solution sol = new Solution();
        int[] res = sol.dijkstra(V, adj, S);

        for (int d : res) {
            System.out.print(d + " ");
        }
        System.out.println();

        sc.close();
    }
}