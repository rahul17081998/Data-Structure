// Least common subsequence in two strings
// Dynamic programming : Tabular method
#include<bits/stdc++.h>
using namespace std;
// tabular approch
int lcs(string s1, string s2)
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
    /*
    o/p: AZ matches from s1 and s2 thats why its lcs is 2
    */
    cout<< "Least common Subsequence: "<<lcs(s1,s2)<<endl;
    return 0;
}