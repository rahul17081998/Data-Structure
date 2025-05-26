#include<bits/stdc++.h>
using namespace std;

//write your function here
int minCoinChange(vector<int> &coins, int sum)
{
    vector<int> dp(sum+1, INT_MAX);
    dp[0]=0; //for sum = 0 we need 0 coins
    
    for(int i=1; i<sum+1; i++)
    {
        for(auto coin: coins){
            if(coin <= i && dp[i-coin]!=INT_MAX)
                dp[i] = min(dp[i], dp[i-coin]+1);
        }
    }

    if(dp[sum]==INT_MAX)
        return -1;
    return dp[sum];
}

int main(){
    vector<int> coins;
    coins.push_back(3);
    coins.push_back(1);
    coins.push_back(5);
    coins.push_back(10);

    int target = 23;
    cout<<minCoinChange(coins, target);
    return 0;
}