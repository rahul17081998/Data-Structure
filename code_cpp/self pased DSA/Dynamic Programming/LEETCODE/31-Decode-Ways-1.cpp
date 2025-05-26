#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    int t[102];
    int decode(string s, int idx, int n)
    {
        // base case
        if(idx<n && s[idx]=='0')
            return 0;
        if(idx>=n)
            return 1;
        // Memoization
        if(t[idx]!=-1)
            return t[idx];
        int ways=0;
        // select single
        if(s[idx]!='0') ways = decode(s, idx+1, n);

         // Pick couple
        if(idx+1 < n && ((s[idx] == '1' && s[idx+1] <= '9') || (s[idx]=='2' && s[idx+1] < '7')))
           ways += decode(s, idx+2, n);
           
        
        return t[idx] = ways;
    }
    int numDecodings(string s) {
        int n = s.length();
        // vector<int> t(n+2, -1);
        memset(t, -1, sizeof(t));
        return decode(s, 0, n);
    }
};



int main(){
    
    string s = "3241";
    Solution ob;
    cout<<ob.numDecodings(s)<<endl;
    return 0;
}