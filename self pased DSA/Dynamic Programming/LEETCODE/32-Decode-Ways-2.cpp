#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {

public:
    // /*
    // helper function
    int decodeChar(char c)
    {
        if(c=='*') return 9;
        else if(c=='0') return 0;
        return 1;
    }
    // /*
    int decodeTwoChar(char first, char second)
    {
        if(first=='*')
        {
            if(second=='*') return 15;
            else if(second >= '0' && second <= '6') return 2;
            else return 1;
        }
        else if(first=='1')
        {
            if(second=='*') return 9;
            else return 1;
        }
        else if(first=='2')
        {
            if(second=='*') return 6;
            else if(second >= '0' && second <= '6') return 1;
            else return 0;
        }
        
        return 0;
    }
    // */
    int numDecodings(string s) {
        
        int n = s.length();
        long mod=1e9+7;
        // create a dp array
        long dp[n+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0]=1;
        dp[1]=decodeChar(s[0]);
        
        for(int i=2; i<=n; i++)
        {
            char prev = s[i-2];
            char curr = s[i-1];
            
            // single char decoding
            dp[i] += dp[i-1]*decodeChar(curr); // 9*1
            // double char decoding
            dp[i] += dp[i-2]*decodeTwoChar(prev, curr); // 9 + 1*2=11
            dp[i]=dp[i]%mod;
        }
        return (int)dp[n];
    }
};

int main(){
    
    string s = "*1";
    Solution ob;
    cout<<ob.numDecodings(s)<<endl;
    return 0;
}