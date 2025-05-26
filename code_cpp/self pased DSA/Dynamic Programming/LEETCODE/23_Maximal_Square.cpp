


#include<bits/stdc++.h>
using namespace std;

/*Intuition:-
After reading the question we understood that, we need to find largest square of 1's and return it's area( that will be maxSqr * maxSqr ). Also given that matrix is a binary matrix.
There are two ways to solve this problem :-

Our Classical Recursion
DP
In this type of questions we believe in supremacy of DP. Since in recursion the TLE error will hunt us. Ok, now let's hunt the hunter .

Algorithm:-

Let's consider the base case that the size of matrix is 0 . So return 0.
Let's declare some variables, I always try to declare self-explanatory variables like maxSqr[maximal area of square] , rows, column
Now the dp memorization matrix that we will be making needs to have 1 extra row and column for the purpose of computing dp of first row and column .
Now we need to iterate the whole matrix and once we find a 1 we need to check the surrounding i.e left, uppper and upper left neighbours -> (dp[i-1][j-1], dp[i-1][j], dp[i][j-1])
After we get the minimum value from neighbours we will be adding 1. You say why , I say we need "+ 1" for two reasons:
If the surrounding 1's are becoming part of our maximal square then we need to increase the maximal size by 1.
If not then atleast we have our original 1x1 square matrix .
Now just find the max from our dp matrix and KABOOM we are done.*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0 || m==0) return 0;
        // create a dp array initialize with 0
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int ans=0;
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                // if we found 1 in our binary matrix
                if(matrix[i-1][j-1]=='1')
                {
                    // find min of left, up ans left-up-digonal
                    // add 1 with min
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j-1], dp[i-1][j]}) +1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        /*
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<m+1; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return ans*ans;
        
    }
};


int main(){
    vector<vector<char> > grid;
    // input generation
    vector<char> level;
    // Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
    // Output: 5

    level.push_back('1');
    level.push_back('0');
    level.push_back('1');
    grid.push_back(level);
    level.clear();
    
    level.push_back('1');
    level.push_back('1');
    level.push_back('1');
    grid.push_back(level);
    level.clear();
    
    level.push_back('0');
    level.push_back('1');
    level.push_back('1');
    grid.push_back(level);
    level.clear();
    
   
    
    Solution ob;
    cout<<ob.maximalSquare(grid)<<endl;

    // Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    // Output: 4
    return 0;
}