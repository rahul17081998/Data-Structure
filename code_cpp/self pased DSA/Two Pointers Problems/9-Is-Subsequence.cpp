/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // use two pointer approach
        if(s.length()>t.length()) return false;
        int p1=0, p2=0;
        while(p1<s.length() && p2<t.length()){
            if(s[p1]==t[p2]){
                p1++;
                p2++;
            }
            else{
                p2++;
            }
        }
        if(p1==s.length()) return true;
        return false;
    }
};