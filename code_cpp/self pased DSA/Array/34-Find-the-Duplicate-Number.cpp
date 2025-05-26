/*
Given an array of integers nums containing n + 1 integers where each 
integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only 
constant extra space.

// TC: O(N), SC: O(1)
Approach
        Since the numbers are [1:N], so we use the array indices for storing the
        visited state of each number, only the duplicate will be visited twice.
        For each number we goto its index position and multiply by -1. In case
        of duplicate it will be multiplied twice and the number will be +ve.


*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i])-1;
            
            nums[index] = nums[index]*-1;
            if(nums[index] > 0)
                return abs(nums[i]);
        }
        return -1;
    }
};