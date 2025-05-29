/*
Problem: Shortest Path with Alternating Colors
Given a directed graph with red and blue edges, find the shortest path from node 0 to every other node such that the edge colors alternate along the path. Return -1 if a node is unreachable.

Approach:
- Build an adjacency list for both red and blue edges, marking edge colors.
- Use BFS starting from node 0, tracking both the current node and the color of the last edge used.
- For each node, only proceed if the next edge color is different from the previous one.
- Mark nodes as visited per color to avoid revisiting with the same color.
- Return the shortest distances for all nodes.
*/

import java.util.*;

public class ShortestPathWithAlternatingColors {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        List<int[]>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int[] edge : redEdges) adj[edge[0]].add(new int[]{edge[1], 1}); // 1 = red
        for (int[] edge : blueEdges) adj[edge[0]].add(new int[]{edge[1], 2}); // 2 = blue
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        boolean[][] visited = new boolean[n][3]; // visited[node][color]
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, 0, -1}); // node, distance, lastColor
        visited[0][0] = true;
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int node = curr[0], d = curr[1], lastColor = curr[2];
            if (dist[node] == -1) dist[node] = d;
            for (int[] next : adj[node]) {
                int nextNode = next[0], color = next[1];
                if (!visited[nextNode][color] && color != lastColor) {
                    visited[nextNode][color] = true;
                    q.offer(new int[]{nextNode, d + 1, color});
                }
            }
        }
        return dist;
    }
} 