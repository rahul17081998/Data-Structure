/*
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
*/

class Solution {
public:
    // TC = O(NlogN), SC = O(1)
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // sort the array
        sort(nums.begin(), nums.end());
        long long ans=0;
        for(int i=0; i<nums.size(); i++){
            // update lower and upper bound for one elements
            // lower <= nums[i] + x <= upper
            // lower-nums[i] <= x <= upper-nums[i] fidn how many x can be btween lr and ur
            int lr=lower-nums[i], ur = upper-nums[i];
            // find how many elements between [i+1,n-1]
            ans += upper_bound(nums.begin()+(i+1), nums.end(), ur) - lower_bound(nums.begin()+(i+1), nums.end(), lr);
            // upper bound of any value lets say x is that position where we find just greater than x value
            // for example [0,2,3,3,3,5] upper bound  of 3 will be 5(just greater than 3, whose index is 5).
            // lower bound of x is what? lower bound of x will be x(that is index if x) if 'x' present into the array, other wise just above the x value index
        }
        return ans;
    }
};
