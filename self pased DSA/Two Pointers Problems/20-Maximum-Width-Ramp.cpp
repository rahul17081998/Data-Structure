/*
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

 

Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.

*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_arr(n, 0);
        vector<int> max_arr(n, 0);
        
        min_arr[0]=nums[0];
        max_arr[n-1]=nums[n-1];
        
        // find min from left side
        for(int i=1; i<n; i++){
            min_arr[i] = min(min_arr[i-1], nums[i]);
        }
        // find max form right side
        for(int i=n-2; i>=0; i--){
            max_arr[i] = max(max_arr[i+1], nums[i]);
            
        }
        
        int left=0; // pointing 0th index of minimum array
        int right=0; // pointing n-1th index of maximum array
        int ans=0;
        
        while(right<n){
            if(min_arr[left]<=max_arr[right]){
                ans = max(ans, right-left);
                right++;
            }
            else left++;
        }
        return ans;
    }
};