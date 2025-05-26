/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell 
one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // time complexity O(N^2);
    int solve(int index, int buy, vector<int> &prices, vector<vector<int> > &dp)
    {
        // base case
        if(index>=prices.size())
            return 0;
        // memoization: check if you already computed value in past
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        
        int profit=0;
        // check if you are allow to purchese/buy stock
        if(buy){
            int buyKro = -prices[index] + solve(index+1, 0, prices, dp);
            int skip = 0 + solve(index+1, 1, prices, dp);
            profit = max(buyKro, skip);
        }
        else{
            int sell = prices[index] + solve(index+2, 1, prices, dp);
            int skip = 0 + solve(index+1, 0, prices, dp);
            profit = max(sell, skip);
        }
        
        dp[index][buy] = profit;
        return profit;
        
    }

    int maxProfit(vector<int>& prices) {
        
        // method 1: DP = recursion + memoization
        int n =prices.size();
        vector<vector<int> > dp(n+2, vector<int>(3, -1));
        return solve(0, 1, prices, dp);
        

    }
};

int main(){
    vector<int> prices;
    // Input: prices = [1,2,3,0,2]
    // Output: 3
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(0);
    prices.push_back(2);

    Solution ob;
    cout<<ob.maxProfit(prices)<<endl;
    return 0;
}
