/**
 * Date: 21/08/2022
 * Count Number of texts
 * 
 * 
Explanation:
When we traverse the string S and we are at the index i, there are 3 (or 4 for "7" and "9") 
cases to be considered for the letter at index i:

consider that letter separately, so combination[i] = combination[i - 1]
if the two last letters stopping at index i are the same, we have an option to combine them, 
then combination[i] += combination[i - 2]

if the three last letters stopping at index i are the same, we have an option to combine them, 
then combination[i] += combination[i - 3]

if the four last letters (for "7" and "9") stopping at index i are the same, 
we have an option to combine them, then combination[i] += combination[i - 4]

Take "2222" as an example and we are at the last "2":
case 1: "222(2)", combination["2222"] = combination["222"]
case 2: "22(22)", combination["2222"] += combination["22"]
case 3: "2(222)", combination["2222"] += combination["2"]
        
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int countTexts(string pressedKeys) {
    
    int n = pressedKeys.length();
    string s = pressedKeys;
    long dp[n+1];
    int mod = 1000000000+7;
    dp[0] = 1;
    
    for(int i=1; i<=n; i++)
    {
        // consider that letter separately, so combination[i] = combination[i - 1]
        dp[i]=dp[i-1];
        
        // if two last letters stopping at index i are the same, we have an option to combine them
        // then combination[i] += combination[i-2]
        if(i>=2 && s[i-2]==s[i-1])  dp[i] = (dp[i] + dp[i-2]) % mod;
        else continue;
        
        // if three last letters stopping at index i are the same, we have an option to combine them
        // then combination[i] += combination[i-3]
        if(i>=3 && s[i-3]==s[i-1])  dp[i] = (dp[i] + dp[i-3]) % mod;
        else continue;
        // if the four last letters (for "7" and "9") stopping at index i are the same, 
        // we have an option to combine them, then combination[i] += combination[i - 4]
        if((s[i-1]=='7' || s[i-1]=='9') && i>=4 && s[i-4]==s[i-1])  dp[i] = (dp[i] + dp[i-4]) % mod;
        
    }
    
    return (int)(dp[n]%mod);
}

};


int main(){
    // input
    string pressedKeys = "22266777789";
    // O/P: 64
    Solution ob;
    cout<<ob.countTexts(pressedKeys)<<endl;
    return 0;
}