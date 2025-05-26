/*
We have given a number n we need to consider n distinct keys
and we need to find how many unique bst can be make out of n keys
*/
#include<iostream>
using namespace std;

int  countBST(int n)
{
    int dp[n+1];    // tabulation method
    dp[0]=1; // base case

    for(int i=1; i<=n; i++)
    {
        dp[i]=0;
        for(int j=0; j<i; j++)
        {
            dp[i] += dp[j]*dp[i-j-1];
        }  
    }
    return dp[n];
}
int main(){
    int n=5;
    cout<<"Total "<<countBST(n)<<" distinct BST can form from "<<n<<" keys";
    return 0;
}