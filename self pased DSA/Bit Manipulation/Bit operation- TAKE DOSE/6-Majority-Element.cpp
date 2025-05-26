/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        
        // Using bit Masking / TC = O(NlogN) / [courtesy: Take Dose]
        // /*
        int n = nums.size();
        int len = sizeof(int)*8;// 32 bit size of int
        int candidate=0; 

        for(int i=0; i<len; i++){
            int count=0;
            // count the set bit at ith position of all the number of array
            for(int j=0; j<nums.size(); j++){
                if(nums[j]&(1<<i)) count++;
            }
            // if count is greater then n/2 is add into the candidate 
            if(count>(n/2))
                candidate += (1<<i); // (1<<i) means 2^i
        }

        // step2: verify freq of candidate is greater then n/2 or not
        int freq=0;
        for(int i=0; i<n; i++){
            if(nums[i]==candidate) freq++;
        }

        if(freq>(n/2)) return candidate;
        return -1; // no candidate found
        // */

        // More Effective algorithm / TC = O(N)

        /* int n = nums.size();
        int current_ele = 0, current_count=0;

        for(int i=0; i<n; i++){
            if(current_count==0) current_ele = nums[i];
               
            if(current_ele == nums[i])
                current_count++;
            else
                current_count--;
        }
        // verify current_ele can be a majority element in the array or not
        int freq = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==current_ele) freq++;
        }

        
        return freq > n/2 ? current_ele:-1;
        */
    }
};