/*
Given an integer array nums of unique elements, return all possible 
subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

class Solution {
public:
    // solving Using BITMASKING
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size(); 
        int mask = 1<<n; // 2^n

        for(int i=0; i<mask; i++){
            int curr = i;
            int j=0;
            vector<int> level;
            while(curr){
                // whenever we found a bit 1, we will include that into string level array
                if((curr&1==1)){
                    level.push_back(nums[j]);
                }
                j++;
                curr = curr>>1; // right shift
            }
            ans.push_back(level);
        }

        return ans;

    }
};


