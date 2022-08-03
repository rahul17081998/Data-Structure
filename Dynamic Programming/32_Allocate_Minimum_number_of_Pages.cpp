#include<bits/stdc++.h>
using namespace std;

// util sum function
int sum(int arr[], int b, int e)
{
    int s = 0;
    for(int i=b; i<=e; i++){
        s += arr[i];
    }
    return s;
}
// Naive recursive solution
// time complexity: exponential
int minPages(int arr[], int n, int k)
{
    // base condition

    // you have only 1 student
    if(k==1) return sum(arr, 0, n-1);
    // you have only one book
    if(n==1) return arr[0];

    // main code
    int res = INT_MAX;
    for(int i=1; i<n; i++)
    {
        res = min(res, max(minPages(arr, i, k-1), sum(arr, i, n-1)));
    }
    return res;
}
// Dynamic programming solution
int minPages_dp(int arr[], int n, int k)
{
    int dp[k+1][n+1];
    // base case
    for(int j=1; j<n+1; j++)
        dp[1][j] = sum(arr, 0, j-1);
    for(int i=1; i<k+1; i++)
        dp[i][1] = arr[0];
    // main code
    for(int i=2; i<k+1; i++){
        for(int j=2; j<n+1; j++){

            int res = INT_MAX;
            for(int p=1; p<j; p++)
            {
                res = min(res, max(dp[i-1][p], sum(arr, p, j-1)));
            }
            dp[i][j] = res;
        }
    }
    return dp[k][n];
}

int main(){
    int arr[] = {10, 5, 30, 1, 2, 5, 10, 10};   // pages corrosponding to each books 
    int k = 3; // Number of student
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Recursive solution:\nMin No of pages: "<<minPages(arr, n, k)<<endl;
    cout<<"DP solution\nMin No of pages: "<<minPages_dp(arr, n, k)<<endl;
    return 0;
}

/*
output: 30
*/