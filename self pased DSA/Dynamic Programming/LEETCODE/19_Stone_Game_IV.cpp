/*
Date: 28/08/2022

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // For finding out wether alice win or not, we had written some test cases, 
    // because for all the game theory question try to write down some of the starting values and 
    // then try to calculate some further values using the backward values because the
    // answer will be pre-defined 
    // if they are playing optimally.
    bool solve2(int n)
    {
        
        vector<bool> dp(n+1);
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j*j <= i; j++)
            {
                if(dp[i-j*j]==false){
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
    
    // method 1: memoization
    // this is a different method
    bool solve(int n, vector<int> &dp)
    {
        if(dp[n]!=0) return dp[n];
        
        bool aliceWon=false;
        for(int move=1; n >= move*move; move++){
            if(n-move*move==0)
            {
                // current perdon won
                aliceWon = true;
                break;
            }
            else{
                aliceWon = aliceWon || !solve(n-move*move, dp);
            }
            
        }
        return dp[n] = aliceWon;
    }
    
    bool winnerSquareGame(int n) {
        
        // method 2
        return solve2(n);
        
        // method 1
        /*
        vector<int> dp(100001, 0);
        return solve(n, dp);
        */
    }
};

int main(){
    // input
    int n=8;

    Solution ob;
    cout<<ob.winnerSquareGame(n)<<endl;
    return 0;
}