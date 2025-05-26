#include<iostream>
using namespace std;
// method 1
// Recursive solution
// time complexity = O(2^n)
int countSubset(int arr[], int n, int sum)
{
    if(n==0)
        return sum==0? 1:0;
    return countSubset(arr, n-1, sum) + countSubset(arr, n-1, sum-arr[n-1]);
}
/*
method 2
DP based solution
time complexity = 𝜃(n *sum)
space complexity = 𝜃(n*sum)
Note this method is only valid for positive number


This method is valid only for those arrays which contains positive elements.
In this method we use a 2D array of size (arr.size() + 1) * (target + 1) of type integer.
Initialization of Matrix:
mat[0][0] = 1 because If the size of sum is


if (A[i] > j)
DP[i][j] = DP[i-1][j]
else 
DP[i][j] = DP[i-1][j] + DP[i-1][j-A[i]]f
*/

int countSubset_dp(int arr[], int n, int sum)
{
    // create a dp array of size (n+1)xsum
    int dp[n+1][sum+1];
    // base cases
    dp[0][0] = 1;
    for(int j=1; j<=sum; j++) dp[0][j] = 0;

    // for rest of the entry
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(j<arr[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][sum];
}


int main(){
    int arr[]={9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    int sum = 31;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Method 1: Recursive solution.\nNumber of subset's whose sum is "<<sum<<" si "<<countSubset(arr, n, sum)<<endl;
    cout<<"Method 2: DP solution.\nNumber of subset's whose sum is "<<sum<<" si "<<countSubset_dp(arr, n, sum)<<endl;
    return 0;
}