/*
Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // binary search algorithm
        // lower_bound of element x is equal to position of x in array if exist, 
        // other wise just above value than x's index .
        int index = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        return index;
    }
};

