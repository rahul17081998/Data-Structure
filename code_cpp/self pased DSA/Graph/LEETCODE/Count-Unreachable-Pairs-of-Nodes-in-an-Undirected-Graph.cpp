/*
You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array 
edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
Return the number of pairs of different nodes that are unreachable from each other.

Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.*/

class Solution {
public:
    int dfs(vector<vector<int>> &adj, vector<int> &vis, int src, int n){
        vis[src]=1;
        int ans=1;
        for(auto node: adj[src]){
            if(vis[node]==0){
                ans += dfs(adj, vis, node, n);
            }
        }
        return ans;
    }
    // main
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }


        vector<int> vis(n, 0);
        vector<int> temp;

        for(int i=0; i<n; i++){
            if(vis[i]==0){
                // int count=1;
                // dfs(adj, vis, i, n, count)
                int count = dfs(adj, vis, i, n);
                temp.push_back(count);
            }
        }
        
        long long sum=0;
        long long t=0;
        for(int i=0; i<temp.size(); i++){
            t += temp[i];
            sum += (n-t)*temp[i];
        }


        return sum;
    }
};