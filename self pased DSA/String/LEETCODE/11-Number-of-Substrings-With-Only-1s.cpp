/*
Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.
*/

class Solution {
public:
    long long M = 1000000000+7;
    int numSub(string s) {
        /* approach: if we have a substring having all 1's size n then total 
        number of substring with only ones is n(n+1)/2
        So first ofall find all the longest substring which contains 1 then 
        for each calculate all 1's substring*/
        
        long long subWithOne=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='0'){
                i++;
                continue;
            } 
            int countOne=0;
            while(i<s.length() && s[i]=='1'){
                countOne++;
                i++;
            }
            long long int v = ((countOne%M)*((countOne+1)%M)/2)%M;
            subWithOne = (subWithOne + v)%M;
        }
        return (int)subWithOne;
    }
};