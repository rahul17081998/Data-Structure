/*

Best time to buy and sell 3:
Maximum 2 trnsections are allowed 
what is the maximum profit ?

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
    
    int maxProfit(vector<int>& prices) {
        // do memoizatoon
        int n = prices.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(2, vector<int>(3, -1)));
        // solve(index, buy, prices, limit, dp)
        // index starts with 0, initially we will buy(1), and maximum 2 sell-buy allow
        return solve(0, 1, prices, 2, dp);
    }
};

int main(){
    vector<int> prices;
    // Input: prices = [7,1,5,3,6,4]
    // Output: 7
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    Solution ob;
    cout<<ob.maxProfit(prices)<<endl;
    return 0;
}
