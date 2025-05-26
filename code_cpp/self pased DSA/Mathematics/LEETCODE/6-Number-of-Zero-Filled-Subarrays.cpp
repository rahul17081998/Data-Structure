/*Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n =nums.size();
        int i=0;

        while(i<n){
            if(nums[i]==0){
                int x = nums[i];
                long long count=0;
                while(i<n && nums[i]==x){
                    count++;
                    i++;
                }
                ans += (count*(count+1))/2;
            }
            else i++;
        }
        return ans;
    }
};