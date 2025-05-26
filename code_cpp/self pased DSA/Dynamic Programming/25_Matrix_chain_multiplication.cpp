/*
Out task is to findout minimum number of element multiplication 
to multiply all the given matrix
*/
#include<bits/stdc++.h>
using namespace std;
// Method 1: Recursive solution
int mChain(int arr[], int i, int j)
{
    // base case 
    // when you have single matrix
    if(i+1 == j)
        return 0;
    int res = INT_MAX;
    for(int k=i+1; k<j; k++)
    {
        res = min(res, mChain(arr, i, k) + mChain(arr, k, j) + arr[i]*arr[k]*arr[j]);
    }
    return res;
}
// recursive method: Aditya Verma
// int solve(int arr[], int i, int j)
// {
    
// } 

// Method 2: Dynamic Programming
int mChain_dp(int arr[], int n)
{
    int dp[n][n];
    // base case: when j==i+1 ---> 0
    for(int i=0; i<n-1; i++)
        dp[i][i+1] = 0;
    // fill rest of enties
    for(int gap=2; gap<n; gap++)
    {
        for(int i=0; i+gap<n; i++)
        {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for(int k=i+1; k<j; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    return dp[0][n-1];
}
// main function
int main(){
    int arr[] = {20, 10, 30, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Recursive Solution: Minimum multiplications required: "<<mChain(arr, 0, n-1)<<endl;
    cout<<"DP solution: Minimum multiplications required: "<<mChain(arr, 0, n-1)<<endl;
    return 0;
}