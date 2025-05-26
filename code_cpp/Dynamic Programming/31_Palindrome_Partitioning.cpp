#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];

// util function to check if a string is palindrome
bool isPalindrome(string &s, int i, int j)
{   // is pointing first and j pointing last position of string s
    while(i<j)
    {
        if(s[i] == s[j])
        {
            i++;
            j--;
        } 
        else{
            return false;
        }    
    }
    return true;
}
// Dynamic programming solution
int palPart_dp(string s)
{
    int n = s.length();
    int dp[n][n];
    // base case
    for(int i=0; i<n; i++)
        dp[i][i]=0;

    for(int gap = 1; gap<n; gap++)
    {
        for(int i=0; i+gap<n; i++)
        {
            int j = i + gap;
            if(isPalindrome(s, i, j))
                dp[i][j] = 0;
            else{
                dp[i][j] = INT_MAX;
                for(int k=i; k<j; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k+1][j]);
                }
            }
        }
    }
    return dp[0][n-1];
}
// memoization technique
// pass the string by pass by reference, it will increase the speed
int solve(string &s, int i, int j)
{
    if(i>=j) return 0;
    // check if value present in table
    if(t[i][j] != -1)
        return t[i][j];
    // if string is a planidrome 
    if(isPalindrome(s, i, j)) return 0;
    
    int res = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int temp_ans = 1 + solve(s, i, k) + solve(s, k+1, j);
        if(temp_ans < res)
            res = temp_ans;
    }
    return t[i][j] = res;
}
// optimised memoization technique
// pass the string by pass by reference, it will increase the speed
int solve_op(string &s, int i, int j)
{
    if(i>=j) return 0;
    // check if value present in table
    if(t[i][j] != -1)
        return t[i][j];
    // if string is a planidrome 
    if(isPalindrome(s, i, j)) return 0;
    
    int res = INT_MAX;
    for(int k=i; k<j; k++)
    {
        // int temp_ans = 1 + solve(s, i, k) + solve(s, k+1, j);

        int left, right;
        // calculate left part
        if(t[i][k] != -1)    
            left = t[i][k];
        else{
            left = solve_op(s, i, k);
            t[i][k] = left;
        } 
        // calculate right part
        if(t[k+1][j] != -1)
            right = t[k+1][j];
        else{
            right = solve_op(s, k+1, j);
            t[k+1][j] = right;
        }
        // store tempary answer
        int temp_ans = 1 + left + right;


        if(temp_ans < res)
            res = temp_ans;
    }
    return t[i][j] = res;
}
// recursive solution
int palPart(string s, int i, int j)
{
    // base case
    if(i>=j) // if string is empty of single size
        return 0;
    if(isPalindrome(s, i, j)) // if string is already palindrome we need not to do partition
        return 0;
    // main code
    int res = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int temp_ans = 1 + palPart(s, i, k) + palPart(s, k+1, j);
        res = min(res,temp_ans);
    }
    return res;
}


int main(){
    memset(t, -1, sizeof(t));
    string str = "ababbbabbababa";
    cout<<"Recursive method:\nMinimum cut's required to make string palindrome: "<<palPart(str, 0, str.length()-1)<<endl;
    cout<<"DP_Memoization method:\nMinimum cut's required to make string palindrome: "<<solve(str, 0, str.length()-1)<<endl;
    cout<<"DP_Optimized Memoization method:\nMinimum cut's required to make string palindrome: "<<solve_op(str, 0, str.length()-1)<<endl;
    cout<<"DP method:\nMinimum cut's required to make string palindrome: "<<palPart_dp(str)<<endl;
    return 0;
}