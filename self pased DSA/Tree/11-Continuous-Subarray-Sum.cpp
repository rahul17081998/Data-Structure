/**
 * Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 */


 class Solution {
public:
    /* 
    approach: the approach is simple we calculate prefix Sum and check if reminder of prefixSum % k is already present 
    and its index is not same than we have a subarray sum which is divisible by k
     Example: 
     [a, b, c, d, e, f, ... ]
     lets say (c+d+e) is divisible by k
     sum1 = a+b, sum2 = a+b+c+d+e
     then (sum2-sum1) = c+d+e, which is divisible by k
     => so we can write (sum2-sum2)%k==0
     => sum2%k == sum1%k
     => we can say if remider divided by k for sum1 and sum2 is equal than we have a contiguous subarray sum which could be divisible by k
     */
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        // coorner case: if divider is zero i.e. k=0 then check 2 consecutive zeros 
        if(k==0){
            for(int i=1; i<nums.size(); i++){
                if(nums[i]==0 && nums[i-1]==0)  
                    return true;
            }
            return false;
        }


        long long sum = 0;
        mp.insert({0, -1}); // insert reminder 0 have -1 index this will work for prefixhum zero reminder
        //  in case if you get prefixSum % k==0 then check if its length is greater than 1
        // then 
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]; // prefix sum
            int rem = sum%k; // reminder of prefix sum

            if(mp.find(rem)!=mp.end() && i-mp[rem]>1){
                return true;
            }
            mp.insert({rem, i});
        }
        return false;
    }
};