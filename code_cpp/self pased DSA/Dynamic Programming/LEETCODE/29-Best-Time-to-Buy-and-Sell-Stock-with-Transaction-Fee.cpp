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
    int solve(int index, int buy, vector<int> &prices, int fee, vector<vector<int> > &dp)
    {
        // base case
        if(index==prices.size())
            return 0;
        
        // memoization use here
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        
        int profit=0;
        // check if you can buy
        if(buy){
            int buykro = -prices[index] + solve(index+1, 0, prices, fee, dp);
            int skip = 0 + solve(index+1, 1, prices, fee, dp);
            profit = max(buykro, skip);
        }
        else{
            int sell = prices[index] -fee + solve(index+1, 1, prices, fee, dp);
            int skip = 0 + solve(index+1, 0, prices, fee, dp);
            profit = max(sell, skip);
        }
        dp[index][buy] = profit;
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int index=0;
        int buy = 1; // [1 -->buy, 0-->sell]
        
        vector<vector<int> > dp(n+1, vector<int>(3, -1));
        return solve(index, buy, prices, fee ,dp);
    }
};

int main(){
    vector<int> prices;
    // Input: prices = [1,3,2,8,4,9], fee = 2
    // Output: 8
    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(8);
    prices.push_back(4);
    prices.push_back(9);
    int fee = 2;
    Solution ob;
    cout<<ob.maxProfit(prices, fee)<<endl;
    return 0;
}
