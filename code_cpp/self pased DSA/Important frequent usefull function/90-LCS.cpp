// Longest common subsequence in two strings
// Dynamic programing memoization method
#include<bits/stdc++.h>
using namespace std;
// recursive approch
int lcs(string s1, string s2, int m, int n)
{
    if(m==0 || n==0)    // base case
        return 0;
    if(s1[m-1] == s2[n-1]) // if last character of both string matches
        return 1+lcs(s1, s2, m-1, n-1);
    else // if last character not matches
        return max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
}
// recursive + memoization approch
int memo[1000][1000];// you can also declare this array in main function and pass into lcs_dp function
// fill(*memo, *memo + 1000*1000, -1);
int lcs_dp(string s1, string s2, int m, int n)
{
    if(memo[m][n]!=-1)
        return memo[m][n];    
    if(m==0 || n==0)
        memo[m][n] = 0;
    else
    {
        if(s1[m-1] == s2[n-1])
            return memo[m][n] =  1+lcs_dp(s1, s2, m-1, n-1);
        else
            return memo[m][n]=max(lcs_dp(s1, s2, m-1, n), lcs_dp(s1, s2, m, n-1));
        
    }
    return memo[m][n];
}
// top down
int lcs_td(string s1, string s2)
{
    int m,n;
    m = s1.length();
    n = s2.length();
    int dp[m+1][n+1];

    for (int i = 0; i < m+1; i++)
        dp[i][0] = 0;
    
    for (int j = 0; j < n+1; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for(int j =1; j<= n; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}
int main(){
    string s1,s2;
    s1 = "AXYZ";
    int m = s1.length();
    s2 = "BAZ";
    int n = s2.length();
    // filling 2D matrix with specific value
    memset(memo, -1, sizeof memo);
    // fill(*memo, *memo + 1000*1000, -1);

    /*
    o/p: AZ matches from s1 and s2 thats why its lcs is 2
    */
    cout<< "Least common Subsequence: "<<lcs_dp(s1,s2,m,n)<<endl;
    return 0;
}