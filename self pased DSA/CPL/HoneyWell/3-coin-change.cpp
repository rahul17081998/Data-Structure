// 3-coin-change// umbrella
// Coin Change
class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>> &dp)
    {
        // base case
        if(i >= coins.size() || amount<=0)
            return amount==0 ? 0:INT_MAX-1;
        
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int res=-1;
        // check if coins value is higher than amount than you can not take that coin, you have to skip that
        if(coins[i] > amount){
            int skipKro = 0 + solve(coins, amount, i+1, dp);
            res = skipKro;
        }
        else{
            int includeKro = 1 + solve(coins, amount-coins[i], i, dp);
            int skipKro = 0 + solve(coins, amount, i+1, dp);
            res = min(includeKro, skipKro);
        }
        return dp[i][amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        // memoization
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        
        int ans = solve(coins, amount, 0, dp);
        return ans==INT_MAX-1? -1:ans;
    }
};