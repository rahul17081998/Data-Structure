/*
Problem Statement:
Chef found a directed graph with N vertices and M edges. We need to find the minimum number of edges to reverse so that there is at least one path from vertex 1 to vertex N.

Approach:
This problem can be solved efficiently using 0-1 BFS. We treat edges that are originally directed from u to v with weight 0 (no reversal needed), and edges in the reverse direction with weight 1 (indicating reversal needed). Using a deque, we perform a BFS where edges with weight 0 are pushed to the front and edges with weight 1 are pushed to the back. This ensures the shortest path in terms of edge reversals is found.

The answer is the minimum number of edges to reverse to get from vertex 1 to vertex N, or -1 if no such path exists.
*/

import java.util.*;

public class MinimumEdgeReversals {
    static class Pair {
        int vertex;
        int weight;
        Pair(int v, int w) {
            vertex = v;
            weight = w;
        }
    }

    static int n, m;
    static List<List<Pair>> graph;
    static final int INF = (int)1e9 + 10;

    public static int zeroOneBFS() {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);
        dist[1] = 0;

        ArrayDeque<Integer> deque = new ArrayDeque<>();
        deque.addFirst(1);

        while (!deque.isEmpty()) {
            int curr = deque.pollFirst();

            for (Pair edge : graph.get(curr)) {
                int next = edge.vertex;
                int wt = edge.weight;
                if (dist[next] > dist[curr] + wt) {
                    dist[next] = dist[curr] + wt;
                    if (wt == 0) {
                        deque.addFirst(next);
                    } else {
                        deque.addLast(next);
                    }
                }
            }
        }

        return dist[n] == INF ? -1 : dist[n];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (x == y) continue; // avoid self loop

            // edge from x to y with weight 0 (no reversal)
            graph.get(x).add(new Pair(y, 0));
            // reverse edge from y to x with weight 1 (reversal needed)
            graph.get(y).add(new Pair(x, 1));
        }

        System.out.println(zeroOneBFS());
        sc.close();
    }
}
