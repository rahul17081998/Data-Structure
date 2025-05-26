/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number 
in the range that is missing from the array.


Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
*/

class Solution {
public:
    // method 2: Using XOR
    // more faster and avoid over flow situation, TC = O(N)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        
        for(int i=0; i<n; i++){
            ans =ans^nums[i];
        }

        for(int i=0; i<=n; i++){
            ans = ans^i;
        }
        return ans;
    }
    
};

/*
class Solution {
public:
    // method 1: Using mathematical equation , TC = O(N)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long total=(n*(n+1))/2;

        long long sum=0;
        for(auto val:nums){
            sum+=val;
        }
        return (int)total-sum;
    }
};
*/
