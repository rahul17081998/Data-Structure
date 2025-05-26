/**
Intuition
-   We need to associate every lowercase english alphabet to it's lexicographically smallest equivalent using the given properties of equality and transitivity.

Approach
-   We define an array of size 26 to map each lowercase alphabet to its lexicographically smallest equivalent
-   Initialize this array with the char itself
-   Now for every index of string s1 and s2, we replace all elements pointing to the greater char between lowestEquivalent of s1[i] and lowestEquivalent of s2[i] with the smaller one.

Q. Why does this work?
After every step, we map all elements that were pointing to the greater equivalent to the smaller one (using properties of transitivity). Since we only have 26 alphabets, this can be done in roughly constant time.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        // ch = [a, b, c, . . . ,z]
        char ch[26];
        for(int i=0; i<26; i++){
            ch[i]='a'+i;
        }

        for(int i=0; i<s1.length(); i++){
            char toReplace = max(ch[s1[i]-'a'], ch[s2[i]-'a']); // find the maximum b/w two char s1[i],s2[i]
            char replaceWith = min(ch[s1[i]-'a'], ch[s2[i]-'a']);// find the minimum b/w two char s1[i],s2[i]
            // search max char in ch array and repalce it with minimum character
            // ch = [a, b, c, d, e, . . . ,z]
            // lets say => toReplace = d, replaceWith = b, 
            // then modified ch array will:
            // ch = [a, b, c, b, e, . . . ,z]

            for(int i=0; i<26; i++){ 
                if(ch[i]==toReplace)
                    ch[i]=replaceWith;
            }
        }

        for(int i=0; i<baseStr.length(); i++){
            baseStr[i] = ch[baseStr[i]-'a'];
        }
        return baseStr;
    }
};


int main(){
    string s1 = "parker", s2 = "morris", baseStr = "parser";
    Solution obj;
    cout<<obj.smallestEquivalentString(s1,s2,baseStr)<<endl;
    return 0;
}
/*
Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
*/