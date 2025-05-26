/**
 * Date: 20/08/2022
 * Leetcode
 * You are given an m x n integer array grid. There is a robot initially located at the 
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner 
 * (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.
    An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot 
    takes cannot include any square that is an obstacle.
    Return the number of possible unique paths that the robot can take to reach the 
    bottom-right corner.
    The testcases are generated so that the answer will be less than or equal to 2 * 109.
 * 
 * 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    
    // base case
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();
    
    // create a dp array
    int dp[n][m];
    
    // base case
    int temp=1;
    // basically if you find any obstracle then then there is no path 
    // from obstracle side
    //  fill first col
    for(int i=0; i<n; i++)
    {
        if(obstacleGrid[i][0]==1) // found obstracle
            temp=0;
        dp[i][0]=temp;
    }
    
    temp=1;
    // fill 1st row
    for(int j=0; j<m; j++)
    {
        if(obstacleGrid[0][j]==1) // found obstracle
            temp=0;
        dp[0][j]=temp;
    }
    
    // fill the rest of the cases
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            // check if obstracle found
            if(obstacleGrid[i][j]==1)
                dp[i][j]=0;
            // if no obstrace
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j]; // you can only come from up and left side
        }
    }
    return dp[n-1][m-1];
}
};
int main(){
    vector<vector<int> > obstacleGrid;
    vector<int> level;
    level.push_back(0);
    level.push_back(0);
    level.push_back(0);
    obstacleGrid.push_back(level);
    level.clear();

    
    level.push_back(0);
    level.push_back(1);
    level.push_back(0);
    obstacleGrid.push_back(level);
    level.clear();

    level.push_back(0);
    level.push_back(0);
    level.push_back(0);
    obstacleGrid.push_back(level);
    level.clear();

    Solution obj;
    cout<<"number of possible unique paths that the robot can take to reach the bottom-right corner:\n";

    cout<<obj.uniquePathsWithObstacles(obstacleGrid)<<endl;


    return 0;
}
/*
Sample example
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/