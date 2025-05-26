/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/

class Solution {
public:
    // TC = O(N^2), SC = O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // sort the array
        
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1; 
            int right=n-1;
            while(left<right){

                if(nums[i]+nums[left]+nums[right]>0) right--;
                else if(nums[i]+nums[left]+nums[right]<0) left++;
                else{   //nums[i]+nums[left]+nums[right]==0
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    // remove the duplicates
                    while(left<n && nums[left]==nums[left-1]) left++;
                    while(right>=0 && nums[right]==nums[right+1]) right--;
                }    
            }
        }
        return ans;
    }
};

