/*

Best time to buy and sell 4:
You are given an integer array prices where prices[i] is the price of a given 
stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // top down approach
    // recursive + memoization
    int solve(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int> > > &dp)
    {
        // base case if you are out of index
        if(index == prices.size())
            return 0;
        // if limit is zero return you can perchase and sell stack now
        if(limit==0)
            return 0;
        
        // use memoization here
        if(dp[index][buy][limit]!=-1)
            return dp[index][buy][limit];
        
        int profit=0;
        // check if you allowed to buy
        if(buy){
            int buykro = -prices[index] + solve(index+1, 0, prices, limit, dp);
            int skipkro = 0 + solve(index+1, 1, prices, limit, dp);
            profit = max(buykro, skipkro);
        }
        else{ // check if you are allow to sell
            int sellkro = prices[index] + solve(index+1, 1, prices, limit-1, dp);
            int skipkro = 0 + solve(index+1, 0, prices, limit, dp);
            profit = max(sellkro, skipkro);
        }
        dp[index][buy][limit] = profit;
        return profit;    
    }
    
    int maxProfit(int k, vector<int>& prices) {
        // do memoizatoon
        int n = prices.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(2, vector<int>(k+1, -1)));
        // solve(index, buy, prices, limit, dp)
        // index starts with 0, initially we will buy(1), and maximum k sell-buy allow
        return solve(0, 1, prices, k, dp);
    }
};

int main(){
    vector<int> prices;
    int k =1;
    // Input: 
    // k =3;
    // prices = [7,1,5,3,6,4]

    // Output: 5
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    Solution ob;
    cout<<ob.maxProfit(k ,prices)<<endl;
    return 0;
}
