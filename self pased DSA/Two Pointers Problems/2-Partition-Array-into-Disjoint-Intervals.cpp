/*
Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.

Test cases are generated such that partitioning exists.


 */

// method 2
// TC = O(N, SC = O(1)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxUntilI = nums[0];
        int maxInLeftPartation = nums[0];
        int partationId=0;

        for(int i=1; i<nums.size(); i++){
            // find global maxima
            maxUntilI = max(maxUntilI, nums[i]);
            if(nums[i] < maxInLeftPartation){
                maxInLeftPartation = maxUntilI;
                partationId = i;
            }
        }
        return partationId+1;
    }
};

// method 1
// TC = O(N), SC = O(N)
 class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        // we have to make two array 
        // left array will keep record maximum element upto its index 
        // right array will keep record minimum element upro its index
        int n = nums.size();
        vector<int> left = nums;
        vector<int> right = nums;

        // find maximum elements from left
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], nums[i]);
        }

        // find minimum elements from right side
        for(int i=n-2; i>=0; i--){
            right[i]= min(right[i+1], nums[i]);
        }

        // now start from left side and check if left side maximum is <= right side minimum than we get the answer
        for(int i=0; i<n-1; i++){
            if(left[i]<=right[i+1])
                return i+1;
        }
        return n;
    }
};