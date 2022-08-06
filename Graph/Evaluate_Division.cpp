/*
Problem Link: https://leetcode.com/problems/evaluate-division/
You are given an array of variable pairs equations and an array of real numbers values, 
where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query 
where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
*/


class Solution {
    unordered_map<string, vector<pair<string, double>>> adjlist;
    unordered_map<string, bool> vis;
    double queryAns;
public:
    bool DFS(string start, string end, double pMultiplier)
    {
        // check if you reach at end node and 
        // also check that node should be present into the graph
        if(start==end && adjlist.find(start)!=adjlist.end())
        {
            queryAns = pMultiplier;
            return true;
        }
        
        // u --> v [weight]
        bool tempans=false; // take a temprary answer marker that will indicate wether
        // they got end node or not into the graph on that path
        vis[start]=true; // mark visited true
        
        for(int i=0; i<adjlist[start].size(); i++)
        {
            string v=adjlist[start][i].first;
            double weight = adjlist[start][i].second;
            if(!vis[v]){
                tempans = DFS(v, end, pMultiplier*weight);
                if(tempans)
                    break;
            }
        }
        
        vis[start]=false;
        return tempans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int m = queries.size();
        
        // traverse through all equatios and form graphh
        for(int i=0; i<n; i++)
        {
            adjlist[equations[i][0]].push_back({equations[i][1], values[i]});
            adjlist[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            // initialize the visited vector
            vis[equations[i][0]]=false;
            vis[equations[i][1]]=false;
        }
        
        vector<double> ans;
        
        // iterate one by one through all the query and calculate quation value if possible
        for(int i=0; i<m; i++)
        {
            queryAns=1;
            bool pathFound = DFS(queries[i][0], queries[i][1], 1);
            if(pathFound==true)
                ans.push_back(queryAns);
            else
                ans.push_back(-1);
        }
        return ans;
        
    }
};
