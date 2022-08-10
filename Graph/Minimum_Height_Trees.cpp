/*
The basic idea is "keep deleting leaves layer-by-layer, until reach the root."
Specifically, first find all the leaves, then remove them. After removing, some nodes will become new leaves. So we can continue remove them. Eventually, there is only 1 or 2 nodes left. If there is only one node left, it is the root. If there are 2 nodes, either of them could be a possible root.
Time Complexity: Since each node will be removed at most once, the complexity is O(n).
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // make graph
        vector<int>ans;
        // base cases
        if(n<1) return ans;
        if(n==1)
        {
            ans.push_back(0);
            return ans;
        }
        
        vector<int> adj[n];
        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        // calculate in-degree of nodes
        vector<int>degree(n,0);
        for (int i = 0; i < n; i++)
        {
            for(int u:adj[i])
                degree[u]++;
        }
        
       // create a queue
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            // check if node has degree 0 than push into map
            if(degree[i]==1)
                q.push(i);
        }
        
        int count=n;
        while(count> 2)
        {
            int size = q.size();
            count=count-size;
            while(size-->0)
            {
                int node = q.front();
                q.pop();

                for(int child : adj[node])
                {
                    degree[child]--; // decrease by one
                    if(degree[child]==1)
                        q.push(child); 
                }
            }    
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
