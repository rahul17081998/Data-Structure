


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int> >& grid, int n, int m, int r, int c1, int c2, vector<vector<vector<int> > > &dp)
    {
        // check if we are out of boundry
        if(r<0 || r>=n || c1<0 || c1>=m || c2<0 || c2>=m)
            return 0;
        
        if(dp[r][c1][c2]!=-1)
            return dp[r][c1][c2];
        
        int maxcherry=0;
        // there are 9 possible case traverse all
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                int nc1=c1+i;
                int nc2=c2+j;
                maxcherry = max(dfs(grid, n, m, r+1, nc1, nc2, dp), maxcherry);
            }
        }
        
        // collect the cherry
        int currCerry=0;
        if(c1==c2) // both reach in same cell take only once
            currCerry = grid[r][c1];
        else // both reach in different cell take cherries from both cell
            currCerry = grid[r][c1] + grid[r][c2];
        
        dp[r][c1][c2] = currCerry + maxcherry; // combine them
        return dp[r][c1][c2];
    }
    
    int cherryPickup(vector<vector<int> >& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(m, vector<int>(m, -1)));
        return dfs(grid, n, m, 0, 0, m-1, dp);
        
        
    }
};
   
int main(){
    vector<vector<int> > grid;
    // input generation
    vector<int> level;
    // Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
    // Output: 5

    level.push_back(3);
    level.push_back(1);
    level.push_back(1);
    grid.push_back(level);
    level.clear();
    
    level.push_back(2);
    level.push_back(5);
    level.push_back(1);
    grid.push_back(level);
    level.clear();
    
    level.push_back(1);
    level.push_back(5);
    level.push_back(5);
    grid.push_back(level);
    level.clear();
    
    level.push_back(2);
    level.push_back(1);
    level.push_back(1);
    grid.push_back(level);
    level.clear();
    
    Solution ob;
    cout<<ob.cherryPickup(grid)<<endl;

    // Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
    // Output: 24
    return 0;
}