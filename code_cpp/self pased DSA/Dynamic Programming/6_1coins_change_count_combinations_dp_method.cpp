/*
    coins[] = {2,5,3,6};
    sum = 10

    10 = 5+5
    10 = 2+2+2+2+2
    10 = 6+2+2
    10 = 3+3+2+2
    10 = 5+3+2

    There are 5 number of ways to count sum of 10 from the given count
    */

#include<bits/stdc++.h>
using namespace std;
// Recursive approch
int getCount(int coins[], int n, int sum)
{
    // coins are taking from last
    int dp[sum+1][n+1];
    for(int i=0; i<=n; i++)
        dp[0][i] = 1;
    for(int i=1; i<=sum; i++)
        dp[i][0] = 0;

    for(int i=1; i<=sum; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j] =  dp[i][j-1]; // ignore last coin
            if(coins[j-1]<=i)
                dp[i][j] += dp[(i-coins[j-1])][j];  
        }
    }
    return dp[sum][n];
} 

int main(){
    int coins[] = {2,5,3,6};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 10;
    cout<<"There are "<<getCount(coins, n, sum)<<" number of ways to count sum of "<<sum<<endl;

    
    return 0;
}