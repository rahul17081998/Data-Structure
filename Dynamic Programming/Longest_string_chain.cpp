class Solution {
public:
    static bool cmp(string &s1, string &s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        // TC : O(n * l*l) //
        // SC : O(n) // N No of words in input array
      
        // sort the word on the basis of length
        sort(words.begin(), words.end(), cmp); // O(N)
        // create a map to store string with longest chain
        map<string, int> dp;
        
        int ans=0;
        for(string word: words) // O(N)
        {
            int LCWCW=0; // longest chain with current word
            for(int i=0; i<word.length(); i++) // O(l)
            {
                // O(l)
                string predecessor = word.substr(0, i) + word.substr(i+1); 
                int value;
                // check if already present
                if(dp.find(predecessor)!=dp.end())
                    value = dp[predecessor]+1;
                else // 
                    value=1;
                
                LCWCW = max(LCWCW, value);
            }
            dp.insert({word, LCWCW});
            ans = max(ans, LCWCW);
        }
        return ans;
        
    }
};
