/**
 * Date 20/08/2022
 * Leetcode problem
 * 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// Time complexity = O(amount * coins_Count)
// Space = O(coins_count);  
int coinChange(vector<int>& coins, int amount) {
    // create a dp array of size amont +1 size
    vector<int> dp(amount+1, INT_MAX);
    dp[0]=0; // for sum 0, i rqeuired zero coins
    
    for(int i=0; i<amount+1; i++)
    {
        for(auto coin: coins)
        {
            if(coin<= i && dp[i-coin]!=INT_MAX)
                dp[i] = min(dp[i], 1+dp[i-coin]);
        }
    }
    if(dp[amount]==INT_MAX)
        return -1;
    return dp[amount];
}
};
int main(){
    int amount=11;
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(3);
    // 
    Solution obj;
    
    cout<<"Minimum coins required is: "<<obj.coinChange(coins, amount)<<endl;
    return 0;
}
