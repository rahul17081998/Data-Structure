#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 3: recursion + memoization
    
    int getVal(int x, int y, vector<vector<int> > &grid, int m, int n, vector<vector<int> > &dp)
    {
       // Base case : we have crossed the matrix, ie. out of bound
        /// if current row crosses then my row is below the princess or 
        /// if current column crosses then my column is ahead the column of princess
        /// and beacause we can go only down and right so we wont be able reach princess
        if(x==m || y==n)
            return INT_MAX;
        
       // Base Case : we have reached our destination ie. last cell
        /// we reached princess , cheers return this cost;
        if(x==m-1 && y==n-1)
            return (grid[x][y]<=0)? 1-grid[x][y]:1;
        
        if(dp[x][y]!=INT_MAX)
            return dp[x][y];
        
         /// now we must try all possible paths , we ask our right and and down cell
        int goRight = getVal(x, y+1, grid, m, n, dp);
        int goDown = getVal(x+1, y, grid, m, n, dp);
        /// min of either values and then cost of this cell
        int minPowerReq = min(goDown, goRight) - grid[x][y];
        
        
        int ans =  (minPowerReq <=0)? 1: minPowerReq;
        return dp[x][y]=ans;
    }
    
    
    // Method 2: dp
    int solve(vector<vector<int> > &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX));
        // base case
        dp[m][n]=1;
        dp[m-1][n]=1;
        dp[m][n-1]=1;
        
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int mini = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
                dp[i][j] =  mini<=0 ? 1:mini ;
               
            }
        }
        return dp[0][0];
    }
    
    /*
    */
    
    
    // Method 1: DFS and backtracking
    int res = INT_MAX;
    void minStartValue(vector<int>& nums) {
        
        int ans=INT_MAX;
        int n = nums.size();
        int sum=0;
        int minSum=INT_MAX;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            // cout<<sum<<" ";
            minSum = min(minSum, sum);
        }
        
       
        if(minSum >=1) 
            ans = 1;
        else ans = (1 -minSum);
        
        res = min(res, ans);
    }
    // dfs to find path from {0, 0} to {m-1, n-1}
    void dfs(int x, int y, vector<vector<int> >& dungeon, vector<int> path, int m, int n)
    {
        // check boundry
        if(x<0 || x>=m || y<0 || y>=n)
            return;
        // add current element into path
        path.push_back(dungeon[x][y]);
        
        // check of at princess
        if(x==m-1 && y==n-1){
            minStartValue(path);
            return;
        }
        // call down and right
        dfs(x+1, y, dungeon, path, m, n);
        dfs(x, y+1, dungeon, path, m, n);
    }
    /*
    */
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        // Method 3: memoization
        vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX));
        return getVal(0, 0, dungeon, m, n, dp);
        
        /*
        // method 2: dp
        return solve(dungeon);
        
        
        // Method 1: dfs + rec
        // vector<int> path;
        // dfs(0, 0, dungeon, path, m, n);
        // return res;
        
        */
    }
};

int main(){
    // input
    // Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
    // Output: 7
    // Explanation: The initial health of the knight must be at least 7 if he 
    // follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
    vector<vector<int> > dungeon;
    vector<int> level;


    level.push_back(-2);
    level.push_back(-3);
    level.push_back(3);
    dungeon.push_back(level);
    level.clear();

    
    level.push_back(-5);
    level.push_back(-10);
    level.push_back(1);
    dungeon.push_back(level);
    level.clear();

    level.push_back(10);
    level.push_back(30);
    level.push_back(-5);
    dungeon.push_back(level);
    level.clear();

   
    Solution ob;
    cout<<ob.calculateMinimumHP(dungeon)<<endl;
    return 0;
}