#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Tabulation method
    int SolveTab(vector<int>& days, vector<int>& costs)
    {
        int n= days.size();
        vector<int> dp(n+1, INT_MAX); // we are finding minimum
        dp[n]=0;
        
        for(int k=n-1; k>=0; k--){
            
             // 1 day pass
            int opt1 = costs[0] + dp[k+1];

            // 7 days pass
            int i;
            for(i=k; i<n && days[i]<days[k] +7; i++);
            int opt2 = costs[1] + dp[i];

            // 30 days pass
            for(i=k; i<n && days[i]<days[k] +30; i++);
            int opt3 = costs[2] + dp[i];

            dp[k]= min({opt1, opt2, opt3});
        }
        return dp[0];
    }
    
    
    // recursive + memoization
    int solveMem(vector<int>& days, vector<int>& costs, int index, vector<int> &dp)
    {
        // base case
        if(index >= days.size())
            return 0;
        // memoization
        if(dp[index]!=-1) return dp[index];
        
        // 1 day pass
        int opt1 = costs[0] + solveMem(days ,costs, index+1, dp);
        
        // 7 days pass
        int i;
        for(i=0; i<days.size() && days[i]<days[index] +7; i++);
        int opt2 = costs[1] + solveMem(days, costs, i, dp);
        
        // 30 days pass
        for(i=0; i<days.size() && days[i]<days[index] +30; i++);
        int opt3 = costs[2] + solveMem(days, costs, i, dp);
        
        return dp[index] = min({opt1, opt2, opt3});
    }
    
    // recursive solution
    int solve(vector<int>& days, vector<int>& costs, int index)
    {
        // base case
        if(index >= days.size())
            return 0;
        
        // 1 day pass
        int opt1 = costs[0] + solve(days ,costs, index+1);
        
        // 7 days pass
        int i;
        for(i=0; i<days.size() && days[i]<days[index] +7; i++);
        int opt2 = costs[1] + solve(days, costs, i);
        
        // 30 days pass
        for(i=0; i<days.size() && days[i]<days[index] +30; i++);
        int opt3 = costs[2] + solve(days, costs, i);
        
        return min({opt1, opt2, opt3});
    }
    // main function
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n= days.size();
        // method1
        // return solve(days, costs, 0);
        // method 2
        // vector<int> dp(n+1, -1);
        // return solveMem(days, costs, 0, dp);
        
        return SolveTab(days, costs);
    }
};

int main(){
    
    return 0;
}
/*
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
*/