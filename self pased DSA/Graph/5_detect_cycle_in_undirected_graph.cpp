#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Add an edge in graph using list 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// Detect cycle in undirected graph
bool DFSRec(vector<int>adj[],int s,vector<int> &vis,int parent)
{
    vis[s]=1;
    for(int u:adj[s])
    {
        if(!vis[u])
        {
            if(DFSRec(adj,u,vis,s)==true)
                return true;
        }
        else if(u!=parent)
            return true;
        // else // parent then ignore
    }

    return false;
}
bool isCycle(vector<int>adj[],int v)
{
   
    vector<int> vis(v, 0);
   
    for (int i = 0; i < v; i++)
        if(!vis[i])
            if(DFSRec(adj, i, vis, -1)==true)
                return true; // cycle detected
        
    
    return false; // cycle not found
    
    
}
// print graph
void printGraph(vector<int> adj[],int v)
{
    for (int i = 0; i < v; i++)
    {
        for(int x:adj[i])
            cout<<x<<" ";
        cout<<"\n";
    }
    
}

int main(){
    int v=5;
    vector<int> adj[v];
    // cycle is present for below input
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);

    // cycle is not present for below input
    // addEdge(adj,0,1);
    // addEdge(adj,1,4);
    // addEdge(adj,1,2);
    // addEdge(adj,2,3);
    // printGraph(adj,v);
   
    cout<<"\nIs cycle detected: "<<isCycle(adj,v)<<endl;
    
    return 0;
}