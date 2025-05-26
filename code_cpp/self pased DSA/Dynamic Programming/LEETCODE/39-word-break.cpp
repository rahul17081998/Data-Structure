/*
Problem:
Given a string s and a dictionary of strings wordDict, return true 
if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.


Solution explanation: https://leetcode.com/problems/word-break/discuss/609045/C%2B%2B-solution-with-Dynamic-Programming-%2B-with-explanation
*/
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n]=1; // empty word present into the dictinory
        
        // put all words into  set for easy searching
        unordered_set<string> dict;
        for(string& word: wordDict){
            dict.insert(word);
        }
        
        // we start from end of the string
        for(int i=n-1; i>=0; i--)
        {
            string word;
            // make string after 'i'th position to j
            for(int j=i; j<n; j++)
            {
                word.push_back(s[j]);
                // check this word i.e. word[i to j] or word[i:j] is present into the map
                if(dict.find(word)!=dict.end())
                    // and also chek of that string from [j+1: n-1] is already present into 
                    if(dp[j+1])
                        dp[i]=1; // then say string from [i: n-1] or(i to n-1) is present into map/dictinory
            }
        }
        return dp[0];
    }
};


int main(){
    vector<string> wordDict;
    string s = "leetcode";
    wordDict.push_back("leet");
    wordDict.push_back("code");

    Solution ob;
    cout<<ob.wordBreak(s, wordDict)<<endl;
    return 0;
}
/*
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
*/