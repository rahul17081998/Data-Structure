// link: https://leetcode.com/problems/cherry-pickup/#:~:text=The%20total%20number%20of%20cherries,this%20is%20the%20maximum%20possible.


class Solution {
public:
    
    // Method 2: recursive + memoization
    
    int cp(int r1, int c1, int r2, int c2, vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp)
    {
        int n = grid.size();
        // base case
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
            
        // if p1 and p2 reach destination
        if(r1==grid.size()-1 && c1==grid[0].size()-1)
        {
            return grid[r1][c1];
        }
        
         // if person 2 reached the bottom right, return what's in there (could be 1 or 0)
        if(r2==grid.size()-1 && c2==grid[0].size()-1)
        {
            return grid[r2][c2];
        }
            
        if(dp[r1][c1][r2][c2]!=0)
            return dp[r1][c1][r2][c2];
        
        int cherry=0;
        // collect cerry
        if(r1==r2 && c1==c2)
            cherry += grid[r1][c1];
        else
            cherry += grid[r1][c1] + grid[r2][c2];
        
        int f1=cp(r1, c1+1, r2, c2+1, grid, dp); // h, h
        int f2=cp(r1+1, c1, r2, c2+1, grid, dp); // v, h
        int f3=cp(r1+1, c1, r2+1, c2, grid, dp); // v, v
        int f4=cp(r1, c1+1, r2+1, c2, grid, dp); // h, v
        
        cherry += max({f1, f2, f3, f4});
        dp[r1][c1][r2][c2] = cherry;
        return cherry;
    }
    
    
    
    /*
    // Method 1:
    // Backtracking solution
    // time complecity = O(2^nn) * O(2^nn) = O(4^nn)
    // ccsf --> cherry collected so far
    int maxcc=0; // maximum cherry collection
    
    void helper(int row, int col, vector<vector<int>> &grid, int ccsf)
    {
        // boundry check and wall
        if(row<0 || row>=grid.size() || col<0 || col >= grid[0].size() || grid[row][col]==-1)
            return;
        
        if(row==0 && col==0){
            maxcc = max(maxcc, ccsf);
            return;
        }
            
        
        int cherries = grid[row][col];
        grid[row][col] = 0; // collect charray, remove cherry 
        helper(row, col-1, grid, ccsf + cherries); // left move
        helper(row-1, col, grid, ccsf + cherries); // up move
        grid[row][col] = cherries; // back tracking
    }
    
    void cp1(int row, int col, vector<vector<int>> &grid, int ccsf)
    {
        // boundry check and wall
        if(row<0 || row>=grid.size() || col<0 || col >= grid[0].size() || grid[row][col]==-1)
            return;
        
        if(row == grid.size()-1 && col == grid[0].size()-1)
            helper(row, col, grid, ccsf);
        
        int cherries = grid[row][col];
        grid[row][col]=0; // collect charray, remove cherry 
        cp1(row, col+1, grid, ccsf + cherries); // right move
        cp1(row+1, col, grid, ccsf + cherries); // down move
        grid[row][col] = cherries; // back tracking
    }
    */
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        // method 2
        int n = grid.size();
        // int dp[n+1][n+1][n+1][n+1]={0};
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0))));
        
        int ans = cp(0, 0, 0, 0, grid, dp);
        return max(0, ans);
        
        /*
        // Method 1:
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1) 
            return max(grid[n-1][m-1], 0);
        
        cp1(0, 0, grid, 0);
        return maxcc;*/
    }
};
