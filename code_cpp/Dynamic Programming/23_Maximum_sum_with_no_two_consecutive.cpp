#include<bits/stdc++.h>
using namespace std;
// recursive solution: method 1
int maxSum(int arr[], int n)
{
    if(n==1)
        return arr[0];
    else if(n==2)
        return max(arr[0],arr[1]);
    else{
        return max(maxSum(arr, n-1), maxSum(arr, n-2) + arr[n-1]);
    }
}
// Dynamic programming: method 2
// Tabulation based solution
// Tc = 𝜃(n), Aux. space = 𝜃(n)
int maxSum_dp(int arr[], int n)
{
    if(n==1) 
        return arr[0];
    int dp[n+1];
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);
    for(int i=3; i<=n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]+arr[i-1]);
    }
    return dp[n];
}

// Dynamic programming: method 3
// more effective solution
// Tc = 𝜃(n), Aux. space = 𝜃(n)
int maxSum_dp_eff(int arr[], int n)
{
    if(n==1)
        return arr[0];
    int prev_prev = arr[0];
    int prev = max(arr[0], arr[1]);
    int res = prev;

    for(int i=3; i<=n; i++)
    {
        res = max(prev, prev_prev + arr[i-1]);
        prev_prev = prev;
        prev = res;
    }
    return res;
}

int main(){
    int arr[] = {10, 5, 15, 20, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Method1: maximum sum with no two consicutive sum: "<<maxSum(arr, n)<<endl;
    cout<<"Method2: maximum sum with no two consicutive sum: "<<maxSum_dp(arr, n)<<endl;
    cout<<"Method3: maximum sum with no two consicutive sum: "<<maxSum_dp_eff(arr, n)<<endl;
    return 0;
}