//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int> > adj[], int S)
    {
        // Code here
        // revision
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
        vector<int> dist(V, INT_MAX);
        pq.push({0, S}); // dist to reach from source node and source node
        
        dist[S]=0; // source to source distance
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            pq.pop();
            
            // traverse its neighbour
            for(auto neighbour: adj[node])
            {
                int v=neighbour[0];
                int weight=neighbour[1];
                
                if(dist[v]> dist[node] + weight)
                {
                    dist[v] = dist[node] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    
        int V, E;
        cin >> V >> E;
        vector<vector<int> > adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    

    return 0;
}

/*
4 5
0 1 9
0 2 1
0 3 1
1 3 3
2 3 2
0



Input:
V = 2, E = 1
u = 0, v = 1, w = 9
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
*/