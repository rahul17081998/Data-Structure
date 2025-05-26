/*You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

 

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort the pairs besed on starting time
        sort(pairs.begin(), pairs.end());
        vector<int> prev=pairs[0];
        int total=1; // at least we have to take one pair in chain

        for(int i=1; i<pairs.size(); i++){
            auto current = pairs[i];
            int currStart = current[0], currEnd = current[1];
            int prevStart = prev[0], prevEnd = prev[1];
            // check if previous interval end time is less than current interval start time than these are seprate pairs we will consider it in our chain
            if(prevEnd<currStart){
                prev = current;
                total++;
            }else{
                // chose that pair as prev pair which has end time is less
                if(prevEnd>currEnd){
                    prev = current;
                }
            }
        }
        return total;
    }
};