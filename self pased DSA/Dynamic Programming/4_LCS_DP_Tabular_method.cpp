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
    // base case
    // if one the string have zero length than lcs=0 reeturn 
    for (int i = 0; i < m+1; i++)
        dp[i][0] = 0;
    
    for (int j = 0; j < n+1; j++)
        dp[0][j] = 0;

    // main logic
    for (int i = 1; i <= m; i++)
    {
        for(int j =1; j<= n; j++)
        {
            // if bith string have same char then add one more element into lcs
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else // else find maximum lcs from previous characters which is stored into dp array
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}


// revision
int lcs_rev(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    int t[n+1][m+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            
            if(s1[i-1]==s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
        }
    }
    return t[n][m];

}















int main(){
    string s1,s2;
    s1 = "BAXYZ";
    int m = s1.length();
    s2 = "BAZ";
    int n = s2.length();
    /*
    o/p: AZ matches from s1 and s2 thats why its lcs is 2
    */
    cout<< "Least common Subsequence: "<<lcs(s1,s2)<<endl;
    cout<< "Least common Subsequence: "<<lcs_rev(s1,s2)<<endl;
    return 0;2
}