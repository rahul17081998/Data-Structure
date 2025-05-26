// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define INT_MAX 999999 

using namespace std;

int tsp(int mask, int pos, vector<vector<int> > &dist, int VISITED_ALL, vector<vector<int> > &dp)
{
    if(mask == VISITED_ALL)
        return dist[pos][0];
    
    
    int n = dist.size();
    
    if(dp[mask][pos]!=-1) return dp[mask][pos];
    // try to goto an unvisited city
    int ans = INT_MAX;
    for(int city=0; city<n; city++){
        if((mask & (1<<city))==0){ // current city is not visited
            int newAns = dist[pos][city] + tsp((mask|(1<<city)), city, dist, VISITED_ALL, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int solve(vector<vector<int> > &grid)
{
    // return 1;
    int n = grid.size();
    int VISITED_ALL = (1<<n)-1; // 11111
    
    int x = pow(2,n);
    vector<vector<int> > dp(x, vector<int>(n, -1));
    
    
    return tsp(1, 0, grid, VISITED_ALL, dp);
    
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<vector<int> > grid(N, vector<int>(N,0));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>> grid[i][j];
            }
        }
        // cout<<endl;
        cout<<solve(grid)<<endl;
        
        
        
    }

    
    return 0;
}


/*
2
2
0 111
112 0
3
0 1000 5000
5000 0 1000
1000  5000  0

*/