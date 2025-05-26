#include<bits/stdc++.h>
using namespace std;

//write your function here

int solve(int a, vector<int> &dp)
{
    if(a==0) return 0;
    if( a==1 || 1==2) return 1;
    if(a==3) return 2;

    if (dp[a]!=-1) return dp[a];

    return dp[a]= solve(a-1, dp) + solve(a-3, dp);
}
int main(){
    vector<int> dp(1000, -1);
    cout<<solve(4, dp)<<endl;
    return 0;
}