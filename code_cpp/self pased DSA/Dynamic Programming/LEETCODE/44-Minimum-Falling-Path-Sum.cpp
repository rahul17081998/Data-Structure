#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given an n x n array of integers matrix, return the minimum sum of any 
falling path through matrix.
A falling path starts at any element in the first row and chooses the 
element in the next row that is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), 
(row + 1, col), or (row + 1, col + 1).

Approach: for any cell we have 3 choice below it we will chose minimum 
of that 3 choice and add that value with current cell value and 
write it to current cell indp table
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        // create a dp table, initialize with 0
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        // base case: fill the last row of dp tablw with matrix last row
        for(int j=0; j<m; j++)
        {
            dp[n-1][j]=matrix[n-1][j];
        }
        
        // start from just above last row of dp table
        for(int i=n-2; i>=0; i--)
        {
            // for each element we have 3 option to chose any one
            for(int j=0; j<m; j++)
            {
                int left=INT_MAX, down, right=INT_MAX;
                // check if we have down-left valid value: that we are into boundry
                if(j-1>=0)
                    left = dp[i+1][j-1];
                // check if we have down-right valid value: that we are into boundry
                if(j+1 <=n-1)
                    right = dp[i+1][j+1];
                down = dp[i+1][j];
                // find min of above 3 value and add with current cell value
                dp[i][j] = min({left, right, down}) + matrix[i][j];
            }
        }
        // find min of first row of dp, that will be our answer
        int ans = INT_MAX;
        for(int j=0; j<m; j++)
        {
            ans = min(ans, dp[0][j]);
        }
        return ans;
        
    }
};


int main(){
    
    return 0;
}

/*
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
*/