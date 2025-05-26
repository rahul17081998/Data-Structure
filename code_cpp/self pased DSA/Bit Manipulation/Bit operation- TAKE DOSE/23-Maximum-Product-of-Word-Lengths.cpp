/*
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. 
If no such two words exist, return 0.

 

Example 1:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn"

*/

class Solution {
public:
    // TC = O(N^2), SC = O(1)
    // BITMANIPULATION METHOD
    int maxProduct(vector<string>& words) {
        // make a unordered map <string, int> 
        unordered_map<string,int> mp;
        // cout<<(1<<0)<<endl;
        
        for(auto s: words){
            // find the value corrosponding to string s
            int val=0;
            for(int i=0; i<s.length(); i++){
                int X = (s[i]-'a'); // add this bit into the 
                // create bit value and its corrosponding position in 26 positions
                val =val | (1<<X);
            }
            mp[s]=val;
            // cout<<s<<" "<<val<<endl;
        }

        int ans = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                // check if AND of bits position is zero, means no common position bits should be 1
                if((mp[words[i]]&mp[words[j]])==0){
                    int l1 = words[i].length();
                    int l2 = words[j].length();
                    ans = max(ans, l1*l2);
                }
            }
        }
        return ans;
    }
};