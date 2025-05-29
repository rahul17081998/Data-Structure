/*
Problem: Count Unreachable Pairs of Nodes in an Undirected Graph
Given an undirected graph with n nodes and a list of edges, return the number of pairs of nodes that are unreachable from each other.

Approach:
- Build the adjacency list for the graph.
- Use DFS to find the size of each connected component.
- For each component, count the number of unreachable pairs as the product of the size of the component and the number of nodes not in the component.
- Sum up the results for all components.
*/

import java.util.*;

public class CountUnreachablePairsOfNodesInAnUndirectedGraph {
    private int dfs(List<List<Integer>> adj, boolean[] vis, int src) {
        vis[src] = true;
        int ans = 1;
        for (int node : adj.get(src)) {
            if (!vis[node]) {
                ans += dfs(adj, vis, node);
            }
        }
        return ans;
    }

    public long countPairs(int n, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        boolean[] vis = new boolean[n];
        List<Integer> componentSizes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int count = dfs(adj, vis, i);
                componentSizes.add(count);
            }
        }
        long sum = 0, t = 0;
        for (int size : componentSizes) {
            t += size;
            sum += (n - t) * (long) size;
        }
        return sum;
    }
} 