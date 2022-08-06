/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not 
move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Approach:
in this question we need to apply DP(recursion + memoization)
we has to memoization in DFS


*/


class Solution {
public:
    
    
    int dfs(int i, int j, vector<vector<int>>& matrix,vector<vector<int>> &dp, int n, int m)
    {
        int dirx[]={0, -1, 0, 1};
        int diry[]={1, 0, -1, 0};
       // check overflow and underflow case
        // no need to check this case
        // if(i<0 || i>=n || j<0 || j>=m)
            // return 0;
        
        // memoization condition in recursion 
        if(dp[i][j] > 0)
            return dp[i][j];
       
        int currLen=1;
        // traverse in all four diretion
        for(int k=0; k<4; k++)
        {
            int nx = i + dirx[k];
            int ny = j + diry[k];
            // check boundry
            if(nx<0 || nx>=n || ny<0 || ny>=m || matrix[i][j] >= matrix[nx][ny])
                continue;
           
            currLen = max(currLen, 1 + dfs(nx, ny, matrix, dp, n, m));
        }
        // update the dp table
        dp[i][j]=currLen;
        return currLen;
    
    }
        
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        
        // we can use BFS to solve this question
        
        int n=matrix.size(); // row
        int m=matrix[0].size(); // col
        int ans=1;
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int longPath=dfs(i, j, matrix, dp, n, m);
                ans = max(ans, longPath);
            }
        }
        return ans;
    }
};
