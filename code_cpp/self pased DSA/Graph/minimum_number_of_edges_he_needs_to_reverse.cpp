/*
Problem Statement/ Chef and Reversing/ CodeChef
Chef found a directed graph with N vertices and M edges in his kitchen!
What is the minimum number of edges he needs to reverse in order to have at least 
one path from vertex 1 to vertex N, where the vertices are numbered from 1 to N.

example test case
i/p:

    7 7
    1 2 
    3 2
    3 4
    7 4
    6 2
    5 6
    7 5

o/p:
    2


input formate:
Each test file contains only one test case.

The first line of the input contains two space separated integers N and M, 
denoting the number of vertices and the number of edges in the graph respectively. 
The ith line of the next M lines contains two space separated integers Xi and Yi, 
denoting that the ith edge connects vertices from Xi to Yi.
*/

// This problem is application of 0-1 BFS
// you can also use Dijkstra algorithm here works perfectelly fine but take more time than 0-1 BFS
#include <bits/stdc++.h>
using namespace std;
const int N=1e5 + 10;
const int INF=1e9 + 10;

vector<pair<int, int>> g[N];
vector<int> level(N, INF);
int n, m;


int bfs()
{
    // create a deque
    deque<int> dq;
    dq.push_back(1); // first node is the starting node
    level[1]=0;
    
    while(!dq.empty())
    {
        int currNode = dq.front();
        dq.pop_front();
        
        // find all the child of current node
        for(auto child: g[currNode])
        {
            int child_n=child.first;
            int wt=child.second;
            if(level[child_n] > level[currNode]+wt)
            {
                level[child_n] = level[currNode]+wt;
                if(wt==1)
                    dq.push_back(child_n);
                else
                    dq.push_back(child_n);
            }
        }
    }
    if(level[n]==INF)
        return -1;
    return level[n];
}

int main() {
	// your code goes here
	// take input from user as vertex and edges
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
	    int x, y;
	    cin>>x>>y;
	    // create a directed graph
	    if(x==y) continue; // avoid self loop
	    g[x].push_back({y, 0}); // x-->y with 0 weight it is given 
	    g[y].push_back({x, 1}); // it is not given but we created
	}
	// print output
	cout<<bfs()<<endl;
	return 0;
}
