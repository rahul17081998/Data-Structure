#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    // recursive method
    int LCS(string s1, string s2, int n, int m)
    {
        if(n==0 || m==0) return 0;
        
        if(s1[n-1]==s2[m-1]) 
            return 1 + LCS(s1, s2, n-1, m-1);
        else
             return max(LCS(s1, s2, n-1, m), LCS(s1, s2, n, m-1));
    }
    // dp method
    int LCS_dp(string s1, string s2, int n, int m)
    {
        // base cases
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        for(int j=0; j<=m; j++)
            dp[0][j] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                // last character matches
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else// last character not matches
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }

    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        int lcs = LCS_dp(text1, text2, n, m);
        return lcs;
    }
};

int main(){
    string text1="abdsthdjsg";
    string text2="fsaxsxad";

    Solution ob;
    cout<<ob.longestCommonSubsequence(text1, text2)<<endl;
    return 0;
}