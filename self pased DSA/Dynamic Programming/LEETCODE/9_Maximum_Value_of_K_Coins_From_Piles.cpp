/**
 * Date: 22/08/2022
 * 
 * 
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int dp[1001][2001];
    int solve(vector<vector<int> > &p, int k, int i)
    {
        // base case 
        // if you are rejecting all the files
        if(i >= p.size())
            return 0;
        
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int maxi=0;
        maxi = max(maxi, solve(p, k, i+1)); // not select any element from current file/ we ignore the current file
        
        for(int j=0; j<p[i].size(); j++)
        {
            // if you selecting coins less than equalto k
            if(j+1<=k)
                maxi = max(maxi, p[i][j] + solve(p, k-(j+1), i+1));
            else
                break;
        }
        
        dp[i][k]=maxi;
        return dp[i][k];
    }
    
    int maxValueOfCoins(vector<vector<int> >& piles, int k) {
        
        // create prefix array
        for(int i=0; i<piles.size(); i++)
            for(int j=1; j<piles[i].size(); j++)
                piles[i][j] = piles[i][j] + piles[i][j-1];
        
        int n = piles.size();
        // initialize dp array with -1;
        for(int i=0; i<n+1; i++)
            for(int j=0; j<k+1; j++)
                dp[i][j]=-1;
             
        
        return solve(piles, k, 0); // 0--> current file/ bunch of coins
    }
};


int main(){
    
    // input
    vector<vector<int> > piles;
    int k=2;
    /*
    Input: piles = [[1,100,3],[7,8,9]], k = 2
    Output: 101
    */

    // fill the input
    vector<int> level;

    level.push_back(1);
    level.push_back(100);
    level.push_back(3);
    piles.push_back(level);
    level.clear();

    
    level.push_back(7);
    level.push_back(8);
    level.push_back(9);
    piles.push_back(level);
    level.clear();

    Solution ob;
    cout<<ob.maxValueOfCoins(piles, k)<<endl;
    
    return 0;
}