/*
    LeetCode problem
you are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.


    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
*/

#include<bits/stdc++.h>
using namespace std;
// Recursive approch
int getCount(int coins[], int n, int sum)
{
    // coins are taking from last
    int dp[n+1][sum+1];
    // sum is zeor
    for(int i=0; i<n+1; i++)
        dp[i][0] = 0;
    // you have no coins
    for(int j=1; j<sum+1; j++)
        dp[0][j] = INT_MAX-1;

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<sum+1; j++)
        {
            //we have two options either take it or not
			// so we take min of two options
            if(coins[i-1]<=j)
                dp[i][j] = min( 1+ dp[i][j-coins[i-1]], dp[i-1][j]); 
                 
            else // if cost at current index > amount skip at
                dp[i][j] =  dp[i-1][j]; // ignore last coin
        }
    }
    if(dp[n][sum] == INT_MAX-1)
        return -1;
    return dp[n][sum];
}

int main(){
    int coins[] = {2,5,3,6};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 17;
    cout<<"Min no of coins required--> "<<getCount(coins, n, sum)<<", to make sum = "<<sum<<endl;

    
    return 0;
}