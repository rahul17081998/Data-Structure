// Longest common subsequence in two strings
// Dynamic programing memoization method
#include<bits/stdc++.h>
using namespace std;
// recursive approch
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