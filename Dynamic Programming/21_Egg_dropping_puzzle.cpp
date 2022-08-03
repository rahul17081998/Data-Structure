/*
Find the minimum no of trails to find the thresold floor
in the worst case consedring every floor are thresold 
floor or any of them may be not a thresold floor.

Example:-

e=2, f=10
o/p: 4

*/

#include<bits/stdc++.h>
using namespace std;

// declear global dp table for memoization
int t[1001][1001];
// Adity Verma solution: Recursive solution
int solve(int e, int f)
{
    // base case
    if(f==0 || f==1)
        return f;
    if(e==1)    // if you have only one egg in worst case total floor you need to check
        return f;
    
    int mn=INT_MAX;
    for(int k=1; k<=f; k++){
        int temp = 1 + max(solve(e-1, k-1), solve(e, f-k)); // max is used for worst case
        mn = min(mn, temp);
    }
    return mn;
}
// Adity Verma solution: memoization bottom up
int solve_memo(int e, int f)
{
    // base case
    if(f==0 || f==1)
        return f;
    if(e == 1)
        return f;
    
    // check if value is present in table
    if(t[e][f] != -1)
        return t[e][f];
    
    int mn = INT_MAX;
    for(int k=1; k<=f; k++)
    {
        int temp = 1 + max(solve_memo(e-1, k-1), solve_memo(e, f-k));
        mn = min(mn, temp);
    }
    t[e][f] = mn;
    return mn;
}
// Recursive solution
int eggDrop(int e, int f)
{
    // base case
    if(f==1 || f==0)    // when No of floor is 0 trails required 0 OR No of floor is 1 trails required 1 
        return f;
    if(e==1)    // if No of egg left is 1 then in worst case you need trail all the floor 
        return f;
    
    int min = INT_MAX, x, res;
    for(x=1; x<=f; x++)
    {
        res = max(eggDrop(e, f-x),      // if egg does not break from xth floor then do recursively for x+1 to f th floor
                  eggDrop(e-1, x-1));   // if egg breaks from xth floor then do recursively for 1 to x-1 th floor

        if(res<min) 
            min = res;
    }
    return min+1;
}

// dynamic solution
int eggDrop_dp(int e, int f)
{
    int dp[f+1][e+1];
    // base cases
    // if No of floor is 0 or 1 trail required 0 or 1 respectively
    for(int i=1; i<=e; i++){ 
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
    // if No of egg left 1 then trail required total no of floor left
    for(int j=0; j<=f; j++){
        dp[j][1] = j;
    }

    // fill rest of cell
    for(int i=2; i<=f; i++)
    {
        for(int j=2; j<=e; j++)
        {
            dp[i][j] = INT_MAX;
            for(int x=1; x<=i; x++){
                dp[i][j] = min(dp[i][j], 1+ max(dp[x-1][j-1], dp[i-x][j]));
            }
        }
    }
    return dp[f][e];
}


int main(){
    int e=2;    // No of egg's
    int f=10;   // No of floor's
    memset(t, -1, sizeof(t));
    cout<<"Adity Verma: No of trails requird: "<<solve(e,f)<<endl;
    cout<<"Adity Verma: No of trails requird: "<<solve_memo(e,f)<<endl;
    cout<<"No of trails requird: "<<eggDrop(e,f)<<endl;
    cout<<"No of trails requird: "<<eggDrop_dp(e,f)<<endl;
    return 0;
}