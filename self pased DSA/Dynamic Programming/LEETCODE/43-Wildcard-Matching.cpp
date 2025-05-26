#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // recursive + memoization
    bool f(string &s, string &p, int i, int j, vector<vector<int> > &dp)
    {
        // 3: base case
        // check if both string exhusted
        if(i<0 && j<0) return true;
        // check if patterent is exhusted but string is not
        if(i>=0 && j<0) return false;
        // check if string is exhusted but opattern is not exhusted
        if(i<0 && j>=0)
        {
            for(int k=0; k<=j; k++)
                if(p[k]!='*')
                    return false;
            return true;
        }
        // memoization
        if(dp[i][j]!=-1) return dp[i][j];
        
        // if last char matches, decrease the both length
        if(s[i]==p[j] || p[j]=='?')
            return dp[i][j] = f(s, p, i-1, j-1, dp);
        
        // if last char not matches than check is patern last char is '*'. if yes then
        // it has two option star can repalce with two chigs
        // first '*' ---> '' (empty) OR
        // second '*' ---> '*c', where c is the character of s[i]the position, so the ith position char matehc 


        else if(p[j]=='*')
            return dp[i][j] = (f(s, p, i, j-1, dp)   // first '*' ---> '' (empty)
                            || f(s, p, i-1, j, dp)); // second '*' ---> '*c'
        else
            return dp[i][j] = false;
        
        
    }
    
    bool isMatch(string s, string p) {
        
        vector<vector<int> > dp(s.length(), vector<int>(p.length(), -1));
        return f(s, p, s.length()-1, p.length()-1, dp);
    }
};


int main(){
    string s = "cb", p = "?a";
    Solution ob;
    cout<<ob.isMatch(s,p)<<endl;
    
    return 0;
}
/*Input: s = "cb", p = "?a"
Output: false*/