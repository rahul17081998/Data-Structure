#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

void dfs(int i, int par, vector<bool>&visited, vector<vector<int> > &adj)
{
    if(visited[i] == true)
    {
        visited[par] = true;
        return;
    }
    for(int j : adj[i])
    {
        dfs(j,i,visited,adj);
    }
}


void solve(){
    int n, p, projects, temp;
    cin >> n >> p;
    vector<vector<int> > adj(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> temp;
        adj[i].push_back(temp);
    }

    vector<bool>visited(n+1,false);
    visited[0] = true;
    
    for(int i=0; i<p; i++)
    {
        cin >> projects;
        dfs(projects,projects,visited,adj);
    }

    for(int i=1; i<=n; i++)
    {
        if(visited[i] == false)
            cout << i << " ";
    }
}


/********/
// rev
void dfs1(int i, int par, vector<bool > &vis, vector<vector<int> > &adj){
    if(vis[i]){
        vis[par]=true;
        return;
    }
    for(auto child: adj[i]){
        dfs1(child, i, vis, adj);
    }
}

void solve2(vector<int> a, vector<int> projects, int n)
{
    // adjacency matrix
    vector<vector<int> > adj(n+1);
    for(int i=1; i<=n; i++){ 
        adj[i].push_back(a[i-1]);
    }
    vector<bool> vis(n+1, false);
    vis[0]=true;

    for(int i=0; i<projects.size(); i++){
        dfs1(projects[i], projects[i], vis, adj);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i])
            cout<<i<<" ";
    }
}
int main()
{    
    // std::ios::sync_with_stdio(false);
    // int T=1; 
    // // cin >> T;
    // while(T--){
    //     solve();
    // }

    int N=8;
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    a.push_back(4);
    a.push_back(4);
    vector<int> projects;
    projects.push_back(8);
    projects.push_back(4);
    projects.push_back(6);
    projects.push_back(5);

    solve2(a, projects, N);
    return 0;
}



/*
8 4
0 1 1 2 3 3 4 4
8 4 6 5

*/