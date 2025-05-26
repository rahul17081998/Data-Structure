/*
Leetcode Link: https://leetcode.com/problems/detonate-the-maximum-bombs/
problem statement:

You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. 
This area is in the shape of a circle with the center as the location of the bomb.
The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. 
xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, 
whereas ri denotes the radius of its range.
You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range.
These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated 
if you are allowed to detonate only one bomb.

Solution/Approach
We can represent bombs using a directed graph - when a bomb i can detonate bomb j, there is an edge from i to j. 
Note that the opposite may not be true.
We generate this graph (al), and, starting from each node, we run BFS (or DFS) and 
find out how many nodes we can reach.
*/

class Solution {
public:
    
    // bfs to find the maximum length adjacecy graph
    int bfs(int start, vector<vector<int>> neighbours)
    {
        queue<int> q;
        q.push(start);
        // create a visited array
        unordered_set<int> vis;
        vis.insert(start);// mark visited
        
        while(!q.empty())
        {
            int size=q.size();
            while(size-->0)
            {
                int bomb=q.front();
                q.pop();
                
                for(int neighbour: neighbours[bomb])
                {
                    if(vis.find(neighbour)==vis.end())
                    {
                        q.push(neighbour);
                        vis.insert(neighbour);
                    }
                }
            }
        }
        return vis.size();
    }
    
    // Adjacency graph building
    // example
    // 0 ->[2,1,4]
    // 1 ->[3,2]
    // 3 ->[1]
    vector<vector<int>> buildingNeighbour(vector<vector<int>>& bombs)
    {
        vector<vector<int>> graph;
        
        for(int i=0; i<bombs.size(); i++)
        {
            vector<int> neighbour;
            long x1=bombs[i][0];
            long y1=bombs[i][1];
            long r1=bombs[i][2];
            
            for(int j=0; j<bombs.size(); j++)
            {
                long x2=bombs[j][0];
                long y2=bombs[j][1];
                if(i!=j)
                {
                    if((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= r1*r1)
                        neighbour.push_back(j);
                }
            }
            graph.push_back(neighbour);
        }
        return graph;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        // build the graph 
        vector<vector<int>> neighbours = buildingNeighbour(bombs);
        int maxCount = 0;
        for(int start=0; start<bombs.size(); start++)
        {
            int count=bfs(start, neighbours);
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
