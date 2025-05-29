/*
Problem: Longest Path With Different Adjacent Characters
Given a tree (an undirected, connected, acyclic graph) with n nodes labeled from 0 to n-1 and a string s, where s[i] is the character assigned to node i. Find the length of the longest path such that no two adjacent nodes on the path have the same character.

Approach:
- Build the adjacency list for the tree from the parent array.
- Use DFS to traverse the tree, keeping track of the two longest valid child paths for each node (where adjacent characters differ).
- At each node, update the result with the sum of the two longest valid child paths plus one (for the current node).
- Return the maximum path length found.
*/

import java.util.*;

public class LongestPathWithDifferentAdjacentCharacters {
    private int result;

    private int dfs(List<List<Integer>> adj, int curr, int parent, String s) {
        int longest = 0;
        int secLongest = 0;
        for (int child : adj.get(curr)) {
            if (child == parent) continue;
            int childLongest = dfs(adj, child, curr, s);
            if (s.charAt(child) == s.charAt(curr)) continue;
            if (childLongest > secLongest) secLongest = childLongest;
            if (secLongest > longest) {
                int temp = longest;
                longest = secLongest;
                secLongest = temp;
            }
        }
        int koi_ek_accha = Math.max(secLongest, longest) + 1;
        int only_root_accha = 1;
        int neeche_hi_mil_gye_answer = 1 + secLongest + longest;
        result = Math.max(result, Math.max(Math.max(koi_ek_accha, only_root_accha), neeche_hi_mil_gye_answer));
        return Math.max(koi_ek_accha, only_root_accha);
    }

    public int longestPath(int[] parent, String s) {
        int n = parent.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int i = 1; i < n; i++) {
            adj.get(i).add(parent[i]);
            adj.get(parent[i]).add(i);
        }
        result = 0;
        dfs(adj, 0, -1, s);
        return result;
    }
} 