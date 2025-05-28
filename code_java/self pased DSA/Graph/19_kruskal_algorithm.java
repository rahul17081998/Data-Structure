/*
Approach: Kruskal's Algorithm for Minimum Spanning Tree (MST)
--------------------------------------------------------------------
Kruskal's algorithm sorts all edges by weight and picks the smallest edge that does not form a cycle, using Union-Find (Disjoint Set Union) for efficient cycle detection. Repeat until MST is formed.
*/

/*
Approach:
Kruskal's Algorithm is used to find the Minimum Spanning Tree (MST) of a connected weighted graph.
- Sort all edges in non-decreasing order of their weight.
- Initialize a Union-Find (Disjoint Set) data structure to detect cycles efficiently.
- Iterate through sorted edges, and for each edge:
    - Check if including this edge forms a cycle by verifying if both vertices belong to different sets.
    - If no cycle is formed, include this edge in MST and union the sets.
- Continue until MST includes (N-1) edges.
- The sum of weights of the included edges is the cost of MST.
*/

import java.util.*;

// Class to represent an edge in the graph
class Edge implements Comparable<Edge> {
    int u, v, wt;
    Edge(int u, int v, int wt) {
        this.u = u;
        this.v = v;
        this.wt = wt;
    }
    // For sorting edges by weight
    public int compareTo(Edge other) {
        return Integer.compare(this.wt, other.wt);
    }
}

public class KruskalAlgorithm {
    // Find parent with path compression
    static int findParent(int x, int[] parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x], parent);
    }

    // Union by rank
    static void union(int x, int y, int[] parent, int[] rank) {
        int xRep = findParent(x, parent);
        int yRep = findParent(y, parent);
        if (xRep == yRep) return;
        if (rank[xRep] < rank[yRep]) {
            parent[xRep] = yRep;
        } else if (rank[xRep] > rank[yRep]) {
            parent[yRep] = xRep;
        } else {
            parent[xRep] = yRep;
            rank[yRep]++;
        }
    }

    public static void main(String[] args) {
        // Number of vertices
        int N = 5;
        // List of all edges (u, v, wt)
        List<Edge> edges = new ArrayList<>();
        edges.add(new Edge(0,1,2));
        edges.add(new Edge(0,3,6));
        edges.add(new Edge(1,0,2));
        edges.add(new Edge(1,2,3));
        edges.add(new Edge(1,3,8));
        edges.add(new Edge(1,4,5));
        edges.add(new Edge(2,1,3));
        edges.add(new Edge(2,4,7));
        edges.add(new Edge(3,0,6));
        edges.add(new Edge(3,1,8));
        edges.add(new Edge(4,1,5));
        edges.add(new Edge(4,2,7));

        // Sort edges by weight
        Collections.sort(edges);

        int[] parent = new int[N];
        int[] rank = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int cost = 0;
        List<Edge> mst = new ArrayList<>();
        for (Edge e : edges) {
            int parU = findParent(e.u, parent);
            int parV = findParent(e.v, parent);
            if (parU != parV) {
                mst.add(e);
                cost += e.wt;
                union(parU, parV, parent, rank);
            }
        }

        // Print MST edges and total cost
        System.out.println("Edges in the Minimum Spanning Tree:");
        for (Edge e : mst) {
            System.out.println(e.u + " - " + e.v + " : " + e.wt);
        }
        System.out.println("Total cost of MST: " + cost);
    }
}






//***//

/*
// code not complete
#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

bool comp(node a, node b){
    return (a.wt < b.wt);
}

int findpar(int u, vector<int> &parent)
{
    if(u==parent[u]) return u;
    else
        return parent[u]=findpar(parent[u],parent);


}

void unionn(int u, int v,vector<int> &parent, vector<int> &rank)
{
    u=findpar(u,parent);
    v=findpar(v,parent);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int main(){
    
    int N=5,m=6;
	vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
    int cost = 0;
	vector<pair<int,int> > mst; 
    vector<int> rank(N, 0);
	for(auto it : edges) {
	    if(findpar(it.v, parent) != findpar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back(make_pair(it.u, it.v)); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
    cout<<cost<<endl;
    for(auto it:mst){
        cout<<it.first<<" - "<<it.second<<endl;
    }
    return 0;
}*/