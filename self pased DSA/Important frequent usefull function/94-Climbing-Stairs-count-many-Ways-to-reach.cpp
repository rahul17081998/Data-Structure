#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    // recursive + memoization
    int solve(int n, vector<int> &dp)
    {
        if(n<=1)
            return 1;
        // memoization
        if(dp[n]!=-1)
            return dp[n];
        
        int steps=0;
        steps = solve(n-1, dp) + solve(n-2, dp);
        return dp[n]=steps;
            
    }
    
    /*
    // Dp
    int solveDp(int n)
    {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2; i<n+1; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];   
    }
    */
    int climbStairs(int n) {
        
        // return solveDp(n);
        vector<int> dp(n+1, -1);
        return solve(n, dp);
        
    }
};

int main(){
    
    int n=7;
    // o/p: 21
    Solution ob;
    cout<<ob.climbStairs(n)<<endl;
    return 0;
}