/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // take two pointer
        int s=0, e=0;
        long long sum=0;
        int minLen=INT_MAX;
        int n = nums.size();

        while(e<n){ 
            sum +=nums[e];
            // check if sum is greater than or equal to target then len = end-start+1
            if(sum >= target){
                minLen = min(minLen, e-s+1);
            }
            // if sum >= teget then then forword the start pointer to the right side 
            // and update the sum as sum=sum-nums[start] untill sum>=target and also update minimum length because you can get here minimum length
            while(s<nums.size() && sum>=target){
                // cout<<"Yes"<<" ";
                sum = sum-nums[s];
                s++;
                if(sum>=target) minLen = min(minLen, e-s+1);
            }
            e++;
        }

        if(minLen==INT_MAX) return 0;
        return minLen;
    }
};