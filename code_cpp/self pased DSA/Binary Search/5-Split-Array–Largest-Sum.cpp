/*
VVI
Given an integer array nums and an integer k, split nums into k non-empty subarrays 
such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
*/


class Solution {

private:
    bool isSuccessful(int mid, vector<int> &nums, int givenSplit){
        int splited=1;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum>mid){
                splited++;
                sum = nums[i];
            }
        }
        return splited<=givenSplit;
    }

public:
    // Capacity To Ship Packages Within D Days(same question)
    // minimum book allocation(same question)
    // TC = O(NlogN), SC = O(1)
    int splitArray(vector<int>& nums, int k) {
        int maxi=0;
        int sum=0;

        for(int val: nums){
            sum += val;
            maxi = max(maxi, val);
        }

        if(nums.size()==k) return maxi;
        // we will apply binary search
        int lo=maxi, hi=sum;
        int ans = 0;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(isSuccessful(mid, nums, k)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};