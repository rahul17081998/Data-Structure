/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.
Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int L=0, R=n-1, mid;

        while(L<=R){
            mid = (L+R) >> 1;
            bool isHalfEven = (mid-L)%2==0;

            if(mid+1<n && nums[mid]==nums[mid+1]){
                if(isHalfEven) L = mid+2; // if true then element is in right side else in left side
                else R = mid-1;
            }
            else if(mid>0 && nums[mid]==nums[mid-1]){
                if(isHalfEven) { // if true then element is in left side else in right side
                    R = mid-2;
                }
                else L=mid+1;
            }
            else return nums[mid];
        }
        return -1;
    }
};