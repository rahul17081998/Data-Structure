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
    // one way to chose coins
    if(sum == 0) return 1; 
    // sum is still not zero but coins[] array become empty
    if(n==0) return 0;  

    
    // if coin is not taken decrease size of coins[] arr
    int res = getCount(coins, n-1, sum);
    // if coin is taken
    if(coins[n-1]<=sum)
        res = res + getCount(coins, n, sum-coins[n-1]);

    return res;
}

int main(){
    int coins[] = {2,5,3,6};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 10;
    cout<<"There are "<<getCount(coins, n, sum)<<" number of ways to count sum of "<<sum<<endl;

    
    return 0;
}