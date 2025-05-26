// revision
#include<bits/stdc++.h>
using namespace std;

struct node{
    int u, v, wt;
    node(int first, int second, int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

bool cmp(node a, node b){
    return a.wt<b.wt;
}

int findPar(int x, vector<int> &parent){
    if(parent[x]==x)
        return x;
    else
        return parent[x] = findPar(parent[x], parent);
}

void unionn(int x, int y, vector<int> &parent, vector<int> &rank){
    // u=findpar(u,parent);
    // v=findpar(v,parent);

    // if(rank[u]<rank[v]){
    //     parent[u]=v;
    // }
    // else if(rank[u]>rank[v]){
    //     parent[v]=u;
    // }
    // else{
    //     parent[v]=u;
    //     rank[u]++;
    // }
    int x_rep = findPar(x, parent);
    int y_rep = findPar(y, parent);

    if(rank[x_rep]<rank[y_rep]) parent[x_rep]=y_rep; // y parent bna x ka
    else if(rank[x_rep] > rank[y_rep]) parent[y_rep]=x_rep; // x parent bna y ka
    else {
        parent[x_rep]=y_rep; // y ko parent bnao
        rank[y_rep]++; // rank increase kro y ka
    } 
}
int main(){
    // input
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

    // sort the edges on the basis of weight
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(N);
    vector<int> rank(N, 0);
    // initialize the parent array
    for(int i=0; i<N; i++){
        parent[i]=i;
    }

    // find the parent of each edges if same then skip 
    // if different include into 
    int cost=0;
    vector<pair<int,int> > mst;

    for(auto it: edges){
        if(findPar(it.u, parent)!=findPar(it.v, parent))
        {
            // include the edge into mst
            mst.push_back(make_pair(it.u, it.v));
            // include weight
            cost += it.wt;
            // make union
            unionn(it.v, it.u, parent, rank);
        }
    }
    cout<<"cost: "<<cost<<endl;

    return 0;
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