/*
Given a string s, find the length of the longest substring without repeating characters.
*/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        /*
        Method 2: 
        Once we've landed on a character we've seen before, we want to move the 
        left pointer of our window to the index after the last occurrence of that character.

        tc = O(N)
        */
        
        unordered_set<char> set;
        int maxLength=0;
        int i=0; // slow pointer
        int j=0; // fast pointer
        
        while(j<s.length())
        {
            // if you dont find char in set, put that char into set
            if(set.find(s[j])==set.end())
            {
                set.insert(s[j]);
                maxLength = max(maxLength, (int)set.size());
                j++;
            }
            // already have s[j] in set
            // it is working here as like jabtak jth character set me hai 
            // starting index element delete karte raho
            else
            {
                set.erase(s[i]);
                i++;
            }
        }
        
        return maxLength;
        
        /*
        // Method 1: O(N^2)
        int maxi=0; 
        for(int x=0; x<s.length(); x++)
        {
            int count=0;
            unordered_set<char> st;
            for(int i=x; i<s.length(); i++)
            {
                // check if you not already included
                if(st.find(s[i])==st.end()){
                    count++;
                    maxi = max(maxi, count);
                    // include the element into set
                    st.insert(s[i]);
                }
                else{
                    break;
                }

            }
        }
            return maxi;
        */
    }
};

int main(){

    // intput
    string s="abcabcbb";
    Solution ob;
    cout<<ob.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
/*
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

*/