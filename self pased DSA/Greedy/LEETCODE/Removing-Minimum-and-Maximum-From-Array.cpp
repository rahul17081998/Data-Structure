/*You are given a 0-indexed array of distinct integers nums.

There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.

Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

 

Example 1:

Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.
Example 2:

Input: nums = [0,-4,19,1,8,-2,-3,5]
Output: 3
Explanation: 
The minimum element in the array is nums[1], which is -4.
The maximum element in the array is nums[2], which is 19.
We can remove both the minimum and maximum by removing 3 elements from the front.
This results in only 3 deletions, which is the minimum number possible.*/

 class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // find the both maxi and mini index
        int maxi=nums[0], mini=nums[0];
        int maxiIndex=0, miniIndex=0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]<mini){
                mini=nums[i];
                miniIndex=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                maxiIndex=i;
            }
        }

        int index1, index2;
        if(maxiIndex>miniIndex){
            index1=miniIndex;
            index2=maxiIndex;
        }else{
            index1=maxiIndex;
            index2=miniIndex;
        }

        // now three possiblities are
        // 1. delete from left side
        int delFromLeft_Len = (index2+1);

        // 2. delete from right side 
        int delFromRight_Len = (n-index1) ;

        // 3. delete from left and right side
        int delFromLeftRight_Len = (index1+1) + (n-index2);

        return min({delFromLeft_Len, delFromRight_Len, delFromLeftRight_Len});


    }
};