#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int s, int k, int end, vector<vector<int> > &dp)
    {
        // if(s<0 || k<0) return 0;
        if(k==0)
        {
            if(s==end) return 1;
            else return 0;
        }
        
        // optimization: you can ignore this also
        if(abs(end-s)>k) return 0; // if starting-ending > remaining k steps then we can not reach furter
        
        // memoization
        if(dp[s+2000][k]!=-1) return dp[s+2000][k];
        
        int ans=0;
        int left = solve(s-1, k-1, end, dp) %mod;
        int right = solve(s+1, k-1, end, dp) %mod;
        ans = (left + right) % mod;
        return dp[s+2000][k]=ans;
            
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        
        vector<vector<int> > dp(4001, vector<int>(1001, -1));
        return solve(startPos, k, endPos, dp);
    }
};

int main(){
    int start = 1;
    int end = 2;
    int k = 3; // no of steps
    // o/p: 3
    Solution ob;
    cout<<ob.numberOfWays(start, end, k);
    return 0;
}