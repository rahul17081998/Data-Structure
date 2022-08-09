/*
Date: 9/Aug/2022
Leetcode Link: https://leetcode.com/contest/weekly-contest-304/problems/longest-cycle-in-a-graph/


*/
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans=-1; // if no cycle found
        int n=edges.size();
        // mapping
        // distance, cycleIdentifier(sourceId)
        
        vector<vector<int>> cycleTracker(n, vector<int>(2, -1)); // mark as not visited[-1]-->n*2
        /*
        currentNode
        0:[-1,-1]
        1:[-1,-1]
         */  
        // each node consider as source and calculate maximum cycle length
        for(int i=0; i<n; i++)
        {
            int dist=0; // initialize default distance as 0;
            int currNode=i; // starting index
            
            while(currNode!=-1)
            {
                int distFromSource=cycleTracker[currNode][0];
                int cycleIdentifier=cycleTracker[currNode][1];
                
                // check if not visited
                if(distFromSource==-1)
                {
                    // cycleTracker[j]={dist++, i};
                    // update the distance from source 
                    cycleTracker[currNode][0]=dist;
                    // update its parent/ source id
                    cycleTracker[currNode][1]=i; // source node
                    dist++;
                    
                }
                else{
                    if(cycleIdentifier==i) // you found cycle
                        ans = max(ans, dist-distFromSource);
                    break;
                }
                // update j
                currNode=edges[currNode];
            }
        }
            
        return ans;
    }
};
