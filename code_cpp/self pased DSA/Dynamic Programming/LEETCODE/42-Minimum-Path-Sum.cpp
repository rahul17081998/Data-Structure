#include<bits/stdc++.h>
using namespace std;

/*Approach: 
This is a typical DP problem. Suppose the minimum path sum of arriving at point (i, j) is S[i][j], \
then the state equation is S[i][j] = min(S[i - 1][j], S[i][j - 1]) + grid[i][j].
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        // Code here
        int row = grid.size();
        if(row == 0){
            return 0;
        }
        int col = grid[0].size();
        int dp[row][col];
        // base case
        dp[0][0] = grid[0][0];
        // Handel base cases: 
        // fill the first column
        for(int r=1; r<row; r++){
            dp[r][0] = dp[r-1][0]+grid[r][0];
        }
        // fill the first row
        for(int c=1; c<col; c++){
            dp[0][c] = dp[0][c-1] + grid[0][c];
        }
        
        // now fill rest of the cells
        for(int r=1; r<row; r++){
            for(int c=1; c<col; c++){
                // find the minimum of current cell's left and up and add the current cell value
                // that is left -> dp[i][j-1], up -> dp[i-1][j]
                dp[r][c] = grid[r][c] + min(dp[r-1][c], dp[r][c-1]);
            }
        }
        return dp[row-1][col-1];
    }
};


int main(){
    vector<vector<int>> grid;
    vector<int> level;

    level.push_back();

    Solution ob;
    cout<<ob.
    return 0;
}
/*
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*/