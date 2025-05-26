#include<bits/stdc++.h>
using namespace std;

// recursive solution
int getMin(int coins[], int n, int val)
{
    
    if(val==0) return 0;
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {   if(coins[i] <= val)
        {
            int sub_res = getMin(coins, n, val-coins[i]);
            if(sub_res!=INT_MAX){
                res = min(res, sub_res+1);
            }
        }
    }
    return res;
}
// Dynamic programming solution
int getMinCoins(int coins[], int n, int val)
{
    int dp[val+1];
    // initialize base case if val is zero fill 0th index as 0 
    // and rest of with INT_MAX
    dp[0] = 0;
    for(int i=1; i<=val; i++)
    {
        dp[i] = INT_MAX;
    }

    for(int i=1; i<=val; i++){
        for(int j=0; j<n; j++){
            if(coins[j]<=i)
            {
                int sub_res = dp[i-coins[j]];
                if(sub_res!=INT_MAX)
                {
                    dp[i] = min(dp[i], sub_res+1);
                }
            }
        }
    }
    return dp[val];
}
int main(){
    int coins[] = {25, 10, 5};
    int n = sizeof(coins)/sizeof(coins[0]);
    int val = 30;
    // cout<<"No of coins required to get sum value: "<<getMin(coins, n, val)<<endl;
    cout<<"No of coins required to get sum value: "<<getMinCoins(coins, n, val);
    return 0;
}