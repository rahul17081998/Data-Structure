/*
Shortest Path with Alternating Colors
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> dist(n, -1);
        vector<pair<int,int>> adj[n+1];

        for(auto vec: redEdges){
            adj[vec[0]].push_back({vec[1],1}); // source --> [dst, egdeColour], [dst, edgeColor]
        }
        for(auto vec: blueEdges){
            adj[vec[0]].push_back({vec[1],2}); // source --> [dst, egdeColour], [dst, edgeColor]
        }

        queue<vector<int>> q;
        q.push({0, 0, -1}); // <current node, distance from 0 to current node, edgeColor used>

        while(!q.empty()){
            auto currVec = q.front();
            q.pop();

            int currNode = currVec[0], edgeColor=currVec[2];
            if(dist[currNode]==-1){ // node not visited till now
                dist[currNode] = currVec[1];
            } 

            for(auto &childPair: adj[currNode]){
                int childNode = childPair.first;
                int edgeColorOfChild = childPair.second;
                // check if child node is not visited and its color is not same as its parent node edge
                // edgeColor==-1 --> means node 0 have no color
                if(childNode != -1 && (edgeColor==-1 || edgeColor!=edgeColorOfChild)){
                    q.push({childNode, currVec[1]+1, edgeColorOfChild});
                    childPair.first = -1; // mark node is visited
                }
            }
        }
        return dist;
    }
};
