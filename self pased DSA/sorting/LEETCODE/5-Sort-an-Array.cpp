/*
Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity 
and with the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

*/

class Solution {
public:
    // TC = O(NlogN), SC = O(N)
    void merge(vector<int> &nums, int l, int mid, int h){
        // make a copy of 'l' to 'mid' element and other copy of 'mid+1' to 'h'
        vector<int> part1, part2;
        for(int i=l; i<=mid; i++) part1.push_back(nums[i]);
        for(int i=mid+1; i<=h; i++) part2.push_back(nums[i]);

        //merge these two array
        // note: these two arrays are sorted
        int i=0, j=0, k=l;
        while(i<part1.size() && j<part2.size()){
            if(part1[i]<part2[j]){
                nums[k++]=part1[i++];
            }
            else{
                nums[k++]=part2[j++];
            }
        }
        // one of the array could left some elements
        while(i<part1.size()){
            nums[k++]=part1[i++];
        }
        while(j<part2.size()){
            nums[k++]=part2[j++];
        }
    }
    void mergeSort(vector<int> &nums, int l, int h){
        if(l<h){
            int mid = l + (h-l)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, h);
            merge(nums, l, mid, h);
        }
    }
    // main function call
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};
