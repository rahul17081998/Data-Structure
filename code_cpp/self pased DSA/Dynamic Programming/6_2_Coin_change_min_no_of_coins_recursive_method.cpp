#include<bits/stdc++.h>
using namespace std;

/*Recursion
Time: O(2^n)
Space: O(n)

Writing a recursive function is all about find two things:

The base case: Just calculate the output for the smallest possible input
The choice diagram: For any given input, just see what all choices do we have.*/

class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, vector<vector<int> > &dp)
    {
        // base case
        if(i >= coins.size() || amount<=0)
            return amount==0 ? 0:INT_MAX-1; // if amount reach 0 our including elements are correct
        // memoization 
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int res=-1;
        // check if coins value is higher than amount than you can not take that coin, you have to skip that
        if(coins[i] > amount){
            int skipKro = 0 + solve(coins, amount, i+1, dp);
            res = skipKro;
        }
        else{ // valid coins 
            int includeKro = 1 + solve(coins, amount-coins[i], i, dp); // we are taking the coin, index will not change becasue we can further take that item
            int skipKro = 0 + solve(coins, amount, i+1, dp); // if you skip mens you are not taking so increase the index
            res = min(includeKro, skipKro);
        }
        return dp[i][amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        // memoization
        vector<vector<int> > dp(n+1, vector<int>(amount+1, -1));
        
        int ans = solve(coins, amount, 0, dp);
        return ans==INT_MAX-1? -1:ans;
    }
};


int main(){
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(5);
    coins.push_back(2);
    int amount = 11;
    Solution ob;
    cout<<ob.coinChange(coins, amount)<<endl;
    return 0;
}
/*
Input: coins = [1,2,5], amount = 11
Output: 3
*/