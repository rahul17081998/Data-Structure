#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: 
    // time complexity = O(n + k*3^k) // k is the no of cell which have golds (greater than 0 value)
    // space = O(k)
    void dfs(vector<vector<int> >& grid, int &sum, int &maxi, int x, int y)
    {
        // check boundry
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==0)
            return;
        
        sum += grid[x][y];
        int temp=grid[x][y]; // it will used to backtrack and unmarking 
        // mark visited
        grid[x][y]=0;
        // store maximum sum, if you find 
        maxi = max(maxi, sum);
        // traverse in all 4 direction
        dfs(grid, sum, maxi, x+1, y);
        dfs(grid, sum, maxi, x, y+1);
        dfs(grid, sum, maxi, x-1, y);
        dfs(grid, sum, maxi, x, y-1);
        
        // unmark the cell so that others can use again
        grid[x][y]=temp;
        sum -= grid[x][y]; // back tracking
    }
    
    // Method 2: smart way to do DFS
    // helper function
    int maximum(int a, int b, int c, int d)
    {
        int arr[4]={a, b, c, d};
        int maxi=INT_MIN;
        for(int i=0; i<4; i++) maxi = max(maxi, arr[i]);
        return maxi;
    }
    // dfs 
    int DFS(vector<vector<int> > &grid, int x, int y)
    {
        // check boundry failed case or cell is visited already or cell is 0
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]<=0)
            return 0;
        
        grid[x][y] = -grid[x][y]; // mark current cell has visited
        // auto res = max({DFS(grid, x, y+1), DFS(grid, x+1, y), DFS(grid, x, y-1), DFS(grid, x-1, y)}); this is work good in leetcode
        auto res = maximum(DFS(grid, x, y+1), DFS(grid, x+1, y), DFS(grid, x, y-1), DFS(grid, x-1, y));
        grid[x][y] = -grid[x][y]; // unmark current cell has visited
        return grid[x][y] + res;
    }
    // Main function
    int getMaximumGold(vector<vector<int> >& grid) {
        // use dfs mathod to find sum
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        // Method 2: dfs and smart way to mark visited node 
        int maxGold=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                maxGold = max( maxGold, DFS(grid, i, j) );
            }
        }
        
        return maxGold;
        
        /*
        // Method 1: dfs
        int maxGold=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]!=0)
                {
                    int sum=0;
                    int maxi=0;
                    // we will modify grid to 0 mark visited
                    dfs(grid, sum, maxi, i, j);
                    maxGold = max(maxGold, maxi);
                }
            }
        }
        
        return maxGold;
        */
        
    }
};

int main(){
    // input
    vector<vector<int> > grid;
    
    /*
    Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
    Output: 24
    
    Explanation:
    [[0,6,0],
    [5,8,7],
    [0,9,0]]
    Path to get the maximum gold, 9 -> 8 -> 7.
    */

    // fill the input
    vector<int> level;

    level.push_back(0);
    level.push_back(6);
    level.push_back(0);
    grid.push_back(level);
    level.clear();
    
    level.push_back(5);
    level.push_back(8);
    level.push_back(7);
    grid.push_back(level);
    level.clear();

    level.push_back(0);
    level.push_back(9);
    level.push_back(0);
    grid.push_back(level);
    level.clear();

    Solution ob;
    cout<<ob.getMaximumGold(grid)<<endl;
    return 0;
}