/*
Date: 26/08/2022

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int> &piles, int left, int right, vector<vector<int> > &dp, bool aliceTurn)
    {
        if(left > right)
            return 0;
        // memoization
        if(dp[left][right] > 0)
            return dp[left][right];
        
        // check if this is alice ture
        if(aliceTurn)
        {
            // false says next turn -> bob
            int choseleft = helper(piles, left+1, right, dp, false) + piles[left];
            int choseright = helper(piles, left, right-1, dp, false) + piles[right];
            dp[left][right] = max(choseleft, choseright);
            return dp[left][right];
        }
        else{
            // true indicate that next ture-> alice
            int choseleft = helper(piles, left+1, right, dp, true) + piles[left]; 
            int choseright = helper(piles, left, right-1, dp, true) + piles[right];
            dp[left][right] = min(choseleft, choseright);
            return dp[left][right];
        }
    }
    
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        helper(piles, 0, n-1, dp, true);
        return dp[0][n-1] > 0;
    }
};

int main(){
    vector<int> piles;
    // Input: piles = [5,3,4,5]
    // Output: true
    piles.push_back(5);
    piles.push_back(3);
    piles.push_back(4);
    piles.push_back(5);
    

    Solution ob;
    cout<<ob.stoneGame(piles)<<endl;
    return 0;
}