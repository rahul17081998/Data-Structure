//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    // long long dp[100001][100001];
  public:


    // bottom up dp approach

    long long solve_dp(int arr[], int n, int k)
    {
        // create a dp table
        // initialize table
        // long long t[k + 1][n + 1] = { 0 };
        vector<vector<long long> > t(k+1, vector<long long>(n+1, 0));
     
        // base cases
        // k=1
        for (int i = 1; i <= n; i++)
            t[1][i] = sum(arr, 0, i - 1);
     
        // n=1
        for (int i = 1; i <= k; i++)
            t[i][1] = arr[0];
        //
        
        for(int i=2; i<k+1; i++)
        {
            for(int j=2; j<n+1; j++)
            {
                long long best = INT_MAX;
                for(int p=1; p<=j; p++)
                    best = min(best, max(t[i-1][p], sum(arr, p, j-1)));
                
                t[i][j]=best;
            }
        }
        return t[k][n];
    }
    // recursion + memoization
    // helper function
    long long sum(int arr[], int from, int to)
    {
        long long ans=0;
        for(int i=from; i<= to; i++)
            ans += arr[i];
            
        return ans;
    }
    // Naive Mathod: Recursive method
    // long long dp[100001][100001];
    long long partation(int arr[], int n, int k, vector<vector<long long> > &dp)
    {
        // base case
        // one partation --> take whole array
        // one painter case
        if(k==1)
            return sum(arr, 0, n-1);
        // only one element left in array
        // onr painting case
        if(n==1)
            return arr[0];
            
        // // memoization use
        if(dp[n][k]!=-1)
            return dp[n][k];
            
        long long best=INT_MAX;
        for(int i=1; i<=n; i++)
        {
            best = min(best, max(partation(arr, i, k-1, dp), sum(arr, i, n-1)));
        }
        dp[n][k]=best;
        return best;
    }
  
    long long minTime(int arr[], int n, int k)
    {
       
        // method 2
        return solve_dp(arr, n, k);

        // method 1
        // initialize dp array
        // memset(dp, -1, sizeof(dp));
        /*
        vector<vector<long long> > dp(n+1, vector<long long>(k+1, -1)); 
        return partation(arr, n, k, dp);
        */
    }
};

//{ Driver Code Starts.

int main()
{
	int arr[] = {5,10,30,20,15};
    int n=5;
    int k=3;
    Solution obj;
    cout << obj.minTime(arr, n, k) << endl;
	
	return 0;
}
// } Driver Code Ends