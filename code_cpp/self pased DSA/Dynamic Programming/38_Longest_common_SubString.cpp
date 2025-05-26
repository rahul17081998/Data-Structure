// longest consecutive substring
// Dynamic programming : Tabular method
#include<bits/stdc++.h>
using namespace std;
// tabular approch
int lcs(string s1, string s2)
{
    int m,n;
    m = s1.length();
    n = s2.length();
    int maxi=0;

    int dp[m+1][n+1];
    for (int i = 0; i < m+1; i++)
        dp[i][0] = 0;
    
    for (int j = 0; j < n+1; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for(int j =1; j<= n; j++)
        {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                maxi = max(maxi, dp[i][j]);
            }
            else 
                dp[i][j] = 0;
        }
    }
    return maxi;
}
int main(){
    string s1,s2;
    s1 = "AXYZ";
    int m = s1.length();
    s2 = "BAXZ";
    int n = s2.length();
    /*
    o/p: AX matches from s1 and s2 thats why its longest consecutive substring is 2 length [AX]
    */
    cout<< "Least common Subsequence: "<<lcs(s1,s2)<<endl;
    return 0;
}