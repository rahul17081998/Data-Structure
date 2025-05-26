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

    // base cases:-
    // check if sum becomes zero: one way to chose coins
    if(sum == 0) return 1; 
    if(sum<0)return 0;
    // sum is still not zero but coins[] array become empty
    if(n==0) return 0;  
    //      skip this coin              take this coin
    // return getCount(coins, n-1, sum) + getCount(coins, n, sum-coins[n-1]);
    
    // /*
    // if coin is not taken decrease size of coins[] arr
    int skipCoin = getCount(coins, n-1, sum);
    // if coin is taken
    int include=0;
    if(coins[n-1]<=sum)
        include= getCount(coins, n, sum-coins[n-1]);

    return skipCoin + include;
    // */
}


int solve(int coins[], int n, int sum, int index)
{
    if(sum==0) return 1;
    if(sum <0) return 0;
    if(index==n) return 0;

    return solve(coins, n, sum, index+1) // skip the coin
         + solve(coins, n, sum-coins[index], index); // include the coin, and next time we can also take this

}
int main(){
    int coins[] = {2,5,3,6};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 10;
    cout<<"There are "<<getCount(coins, n, sum)<<" number of ways to count sum of "<<sum<<endl;
    cout<<"There are "<<solve(coins, n, sum, 0)<<" number of ways to count sum of "<<sum<<endl;
    
    
    return 0;
}