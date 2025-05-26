/*
You are given an integer array nums and two integers minK and maxK.
A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res=0;
        bool minf=false, maxf=false;
        int start=0;
        int minStart=0, maxStart=0;

        for(int i=0; i<nums.size(); i++){
            int num=nums[i];

            if(num>maxK || num<minK){
                minf=false, maxf=false;
                start=i+1;
            }

            if(num==minK){
                minf=true;
                minStart=i;
            }

            if(num==maxK){
                maxf=true;
                maxStart=i;
            }

            if(minf && maxf){
                res += min(minStart, maxStart)-start+1;
            }
        }
        return res;
    }
};