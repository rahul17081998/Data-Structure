/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, 
return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

*/

class Solution {
public:
    // TC = O(N^2), SC = O(N)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> mp; // <sum, frequency>

        // find the all pairs of sum[nums1[i], nums2[j]] and store its sum and frequency into map
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum_AB = nums1[i]+nums2[j];
                mp[sum_AB]++;
            }
        } 

        // find all pairs of sum_CD = sum(nums3[i], sums4[j]). Check Is -sum_CD present into map?
        // if present, then sum of nums1[i] + nums2[j] + nums3[k] + nums4[l] = 0 is possible
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum_CD = nums3[i]+nums4[j];
                // check if -sum_CD present into map
                if(mp.find(-sum_CD)!=mp.end())
                    count += mp[-sum_CD];
            }
        } 
        return count;
    }
};
