#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
   // No need for O(N) space , can be done in O(1) with two variables.

    int minFlipsMonoIncr(string s) {
        int zeroToOne=0; // zero to one converted
        int ones=0; // count 1's
        
        int n = s.length();
        int j=0;
        // eliminate all leading zeros
        while(j<n && s[j]=='0'){
            j++;
        }
        
        // now start main work
        for(int i=j; i<n; i++)
        {
            if(s[i]=='0')
                zeroToOne++;
            else if(s[i]=='1')
                ones++;
            
            // compare every time if flip(zero to one count) is more than ones_count
            // than make flip  =  ones count
            // that means flipping 1 to 0 is less costelly
            if(zeroToOne > ones)
                zeroToOne = ones;
        }
        
        return zeroToOne;
    }
};

int main(){
    string s = "00100000110";
    Solution ob;
    cout<<ob.minFlipsMonoIncr(s)<<endl;
    return 0;
}