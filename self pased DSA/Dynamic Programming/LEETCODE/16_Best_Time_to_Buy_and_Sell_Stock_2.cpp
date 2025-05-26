

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int index, int buy, vector<int> &prices, vector<vector<int> > &dp)
    {
        // base case
        if(index==prices.size())
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
            int sell = prices[index] + solve(index+1, 1, prices, dp);
            int skip = 0 + solve(index+1, 0, prices, dp);
            profit = max(sell, skip);
        }
        
        dp[index][buy] = profit;
        return profit;
        
    }

    int maxProfit(vector<int>& prices) {
        
        // method 2: DP = recursion + memoization
        int n =prices.size();
        vector<vector<int> > dp(n+1, vector<int>(3, -1));
        return solve(0, 1, prices, dp);
        

        // Method 1:
        /*
        int n = prices.size();
        int buy=prices[0];
        int sell=prices[0];
        int profit=0;
        
        for(int i=0; i<n; i++)
        {
            // check if today's price of stack is more than last day price
            // then dont sell the stack wait now
            if(prices[i] >= sell)
                sell = prices[i];
            // check if today's price of stack decrease from last day
            // sell you stack on last day and purchase the new stack of current day
            else if(prices[i] < sell){
                profit += sell-buy;
                buy = prices[i];
                sell = prices[i];
            }
            // check if it is last day then whatever you have stack sell them
            if(i==n-1)
                profit += sell-buy;
        }
        
        return profit;*/
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
