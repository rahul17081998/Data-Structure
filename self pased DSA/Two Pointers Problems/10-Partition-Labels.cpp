/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        // store the last index of each unique charecter
        for(int i=0; i<s.length(); i++){
            mp[s[i]]=i;
        }
        vector<int> ans;
        // take two pointer start and end
        int start = 0, end = mp[s[start]];
        while(start<s.length()){
            int left = start; // store the starting index because starting will change letter
            end = mp[s[start]]; // last index if current charecter

            while(start<end){
                // check if current last index > end then update end = current charecter's last index
                if(mp[s[start]]>end)
                    end = mp[s[start]];
                start++;
            }
            // this is a Partition Labels
            ans.push_back(end-left+1);
            start++;
        }
        return ans;
    }
};

