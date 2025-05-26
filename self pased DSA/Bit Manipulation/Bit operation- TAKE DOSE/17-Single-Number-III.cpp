/*
-----------------------------------------------------VVI----------------------------------------------------

Given an integer array nums, in which exactly two elements appear only once and all the other elements 
appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // do xor of all the numbers
        uint32_t  xorall=0;
        for(int i=0; i<nums.size(); i++){
            xorall = xorall^nums[i];
        }

        // now xorall that XOR of that two number which are only apperes one in array
        // find right most set bit, like x = 1001100, then right most set bit number is 1000100
        uint32_t  rightMostSetNo = xorall & ~(xorall-1); 
        int set1=0, set2=0;

        // all the numbers which has right most bit set then xor with set1 number ultimalely when 
        // two same number come it will cancile out and remaining number will be one any of one number 
        // which has rightmost set bit at same position, similaly set2 will only xor with rightmost have 0 bit .
        for(int i=0; i<nums.size(); i++){
            if((rightMostSetNo & nums[i]) > 0){
                set1 ^=nums[i];
            }
            else{
                set2 ^=nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(set1);
        ans.push_back(set2);
        return ans;
    }
};