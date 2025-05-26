/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.
*/


class Solution {
public:
    /* APPROACH: array is sorted so just take two pointer left and right and start with
    left=0, and right=n-1. Now check if arr[left]+arr[right]== target then we get our 
    soultion then return {left+1, right+1} becausr we are taking 1 index 
    else if arr[left]+arr[right] > target, then decrese right pointer 
    ans if arr[left]+arr[right] < target, increase left pointer
    
    TC = O(N), SC = O(1)
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0, right=numbers.size()-1;

        while(left<right){
            if(numbers[left]+numbers[right]>target)
                right--;
            else if(numbers[left]+numbers[right]==target){
                return {left+1, right+1};
            }
            else{
                left++;
            }
        }
        return {-1,-1}; // this line will never exicute bcz it is guranteed to have a solution 
    }
};