#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0); // dp[i] means number of arethemitic slices ending with nums[i]
        
        // subsequence size should atleast be 3
        for(int i=2; i<n; i++){
            
            // if A[i-2], A[i-1], A[i] are arithmetic, then the number of 
            // arithmetic slices ending with A[i] (dp[i])
            // equals to:
            //      the number of arithmetic slices ending with A[i-1] 
            // (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
            //      +
            //      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
            // it is how dp[i] = dp[i-1] + 1 comes
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i] = 1+dp[i-1];
            }
            else
                dp[i]=0;
        }
        // sum all values;
        int sum = 0;
        for(int i=0; i<n; i++) sum+= dp[i];
        return sum;
        
        
    }
};


int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    Solution obj;
    cout<<obj.numberOfArithmeticSlices(nums)<<endl;
    return 0;
}
/*
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
*/