/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /* XOR of two same elements are zero
            So after XOR all the elements we will left with the 
            signle element.
        */
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};