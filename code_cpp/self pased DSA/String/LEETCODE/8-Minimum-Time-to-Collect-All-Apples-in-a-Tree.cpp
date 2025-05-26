class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Create an adjacency list representation of the tree
        vector<vector<int>> adj(n); 
        for(auto edge: edges){
            // Get the indices of the nodes connected by the current edge
            int u = edge[0], v = edge[1];
            // Add each node to the adjacency list of the other
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // Create a vector to keep track of visited nodes
        vector<int> vis(n, 0);
        // Call the dfs function starting from the root node (index 0)
        return dfs(adj, vis, hasApple, 0);
    }

private:
    int dfs(vector<vector<int>> &adj, vector<int> &vis, vector<bool> &hasApple, int index){
        // Initialize variable to keep track of time required to collect apples
        int appleCollTime=0;
        // Mark the current node as visited
        vis[index]=1;

        for(int i: adj[index]){
            // If the current node has not been visited
            if(!vis[i]){
                // Recursively call the dfs function for this node
                appleCollTime += dfs(adj, vis, hasApple, i);
            }
        }
        // Mark the current node as not visited
        vis[index]=0;
        // if we are at root node return appleCollTime
        if(index==0) return appleCollTime;
        // If current node has an apple or it's children has apples add 2 to appleCollTime
        if(hasApple[index] || appleCollTime>0)
            appleCollTime += 2;

        return appleCollTime;
    }
};
