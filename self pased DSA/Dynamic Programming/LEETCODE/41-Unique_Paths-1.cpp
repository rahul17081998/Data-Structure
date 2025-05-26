/**
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either 
down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach 
the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.
 * 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // BFS Method: it will give TLE
        /*
        // use bfs to solve this problem
        int dirx[]={0, 1};
        int diry[]={1, 0};
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int count=0;
        
        while(!q.empty())
        {
            pair<int, int> temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            
            if(x==m-1 && y==n-1)
            {
                count++;
                continue;
            }
            for(int i=0; i<2; i++)
            {
                int nx=x+dirx[i];
                int ny=y+diry[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n)
                {
                    q.push({nx,ny});
                }
            }
            
        }
        return count;
        */
        
        // DP method : time=O(M*N), space=O(M*N)
        int dp[m][n];
        // fill first row and column with 1
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(i==0 || j==0)
                    dp[i][j]=1;
            
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j]=dp[i-1][j] + dp[i][j-1];
            
        
        return dp[m-1][n-1];
    }
};


int main(){
    
    cout<<"number of possible unique paths that the robot can take to reach the bottom-right corner:\n";
    Solution obj;
    cout<<obj.uniquePaths(3,7)<<endl;


    return 0;
}
/*
Sample example
Input: m = 3, n = 7
Output: 28

*/