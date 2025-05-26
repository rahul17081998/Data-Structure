/*
An alphabetical continuous string is a string consisting of consecutive letters in the alphabet. In other words, it is any substring of the string "abcdefghijklmnopqrstuvwxyz".

For example, "abc" is an alphabetical continuous string, while "acb" and "za" are not.
Given a string s consisting of lowercase letters only, return the length of the longest alphabetical continuous substring.
*/

class Solution {
public:
    /* APPROACH: take two pointers start=0, end=1 and every time check if s[end] char value is equal to 
    s[end-1] then increse end only, other wise calulate the prev length[start, end-1]--> which is an 
    Alphabetical Continuous Substringa then make start = end and increse end=end+1
    Time complexity = O(N), SC = O(1) */

    int longestContinuousSubstring(string s) {
        if(s.length()==1) return 1;
        int ans = 1;
        int start=0, end = 1;

        while(end<s.length()){
            // check if current char value is equal to previous character value +1 then increse end pointer 
            if(s[end]-'a' == (s[end-1]-'a')+1){
                end++;
            }
            else{ // calculate the length[start, end-1]--> which is an Alphabetical Continuous Substring
                ans = max(ans, end-start);
                // update the start and end pointer
                start=end; 
                end++;
            }
        }
        ans = max(ans, end-start);
        return ans;

    }
};