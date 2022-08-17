class Solution {
public:
    int dfs(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp)
    {
        // base case
        if(row == triangle.size())
            return 0;
        
        // memoization
        if(dp[row][col]!=INT_MAX)
            return dp[row][col];
        
        // either go to [row+1, col] or [row+1, col+1]
        int minimum = min(dfs(triangle, row+1, col, dp), dfs(triangle, row+1, col+1, dp));
        
        // combine current value with ans
        dp[row][col] = triangle[row][col] + minimum;
        return dp[row][col];
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        
        // inset of this we can use map
        vector<vector<int>> dp(n, vector<int> (m, INT_MAX));
        return dfs(triangle, 0, 0, dp);
    }
};
