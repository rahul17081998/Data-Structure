class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();
        // create two distance array which will
        // store the distance from node1 and node2 into dist1 and dist2 array
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        
        dist1[node1]=0;
        dist2[node2]=0;
        
        int i=node1;
        int dist=0;
        
        // apply dfs for node1
        while(true)
        {
            dist1[i]=dist;
            dist++;
            // new adjacent node
            i=edges[i];
            // check if current node has no outgoing node or already visited[cycle detected]
            if(i==-1 || dist1[i]!=-1)
                break;
        }
        
        i=node2;
        dist=0;
        while(true)
        {
            dist2[i]=dist;
            dist++;
            // new adjacent node
            i=edges[i];
             // check if current node has no outgoing node or already visited[cycle detected]
            if(i==-1 || dist2[i]!=-1)
                break;
        }
        
        
        int ans=-1; // return node
        int min_dist=INT_MAX;
        
         // find LCA
        for(int i=0; i<n; i++)
        {
            if(dist1[i]==-1 || dist2[i]==-1)
                continue;
            // find maximum distance to reach from any node
            int temp=max(dist1[i], dist2[i]);
            if(min_dist > temp)
            {
                min_dist=temp;
                ans=i;
            }
        }
        return ans;
        
    }
};
