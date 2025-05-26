#include <bits/stdc++.h>
using namespace std;
int dp[101][101][100];
int solve(int i,int j,int k,string &s,string &t)
{
    if(i==0 || j==0)
    {
        return 0;
    }
    else if(dp[i][j][k]!=-1)
    {
        return dp[i][j][k];
    }
    else 
    {
        int ma=0;
        if(s[i-1]==t[j-1])
        {
            ma=solve(i-1,j-1,k,s,t)+1;
        }
        else 
        {
            ma=max(solve(i-1,j,k,s,t),ma);
            ma=max(solve(i,j-1,k,s,t),ma);
            int diff=abs(s[i-1]-t[j-1]);
            if(diff<=k)
            {
                ma=max(ma,1+solve(i-1,j-1,k-diff,s,t));
            }
            
        }
        return dp[i][j][k]=ma;
    }
}
int main()
{
    string s="fpelqanxyk";
    string t="hackerrank";
    int k=6;
    int m=s.size();
    int n=t.size();
    memset(dp,-1,sizeof(dp));
    cout<< solve(m,n,k,s,t)<<endl;
}