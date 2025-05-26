/*
Minimum Window Substring / LeetCode / Hard
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in 
the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        // store all char freq of target string into freq vector
        vector<int> freq(128, 0);
        for(int i=0; i<t.length(); i++){
            freq[t[i]]++;
        }
        
        int start=0, end=0, minStart=0, minL=INT_MAX, counter = t.length();
        while(end < s.length())
        {
            // check if current element have greater than 0 frequency then decrease counter
            if(freq[s[end]] >0)
                counter--;
            
            freq[s[end]]--; // decrease the current element frequency
            end++;
            
            // check if your counter reach at zero than you find a possible solution 
            // now decrease the string size
            while(counter == 0)
            {
                // check if current minLength is greater than new one
                if(minL > end - start){
                    minL = end - start;
                    minStart = start; // store than last minStarting index
                }
                
                // increase the starting freq
                freq[s[start]]++;
                
                // check starting char have > 0 freaq
                // then increase the count
                if(freq[s[start]] > 0)
                    counter++;
                // increasethe starting freq
                start++;
            }
        }
        return minL == INT_MAX? "":s.substr(minStart, minL);
    }
};