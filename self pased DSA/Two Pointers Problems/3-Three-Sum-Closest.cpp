/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

class Solution {
public:
    // TC = O(N^2), SC = O(1)
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];

        int prevDiff=INT_MAX;

        // sort the array
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            // take two pointer left and right
            int left=i+1, right=n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right]; // sum of 3 num
                int diff = abs(target-sum); // find current difference(make absolute)
                // check if current difference is smaller than previous difference, then
                // then prevdiff = curr diff, and current sum save as an answer
                if(prevDiff>diff){
                    prevDiff = diff;
                    ans = sum;
                }
                // check if sum is smaller than target, increase left pointer
                // similarly if sum is greater than target, dec right pointer
                // and if sum==target we get answer as sum
                if(sum<target) left++;
                else if(sum>target) right--;
                else return sum;

            }

        }
        return ans;

    }
};