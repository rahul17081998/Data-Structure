#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+3, -1);
        return fun(nums, 0, dp);
    }
    
    bool fun(vector<int> &nums, int i, vector<int> &dp)
    {
        int n = nums.size();
        // base case
        if(i==n)
            return true;
        
        if(dp[i]!=-1) return dp[i];
        // 3 casea
        // case 1: 2 equal elements
        if(i+1<n && nums[i]==nums[i+1])
        {
            if(fun(nums, i+2, dp)) return dp[i]=true;
        }
        // case 2: 3 queal element
        if(i+2<n && nums[i]==nums[i+1] && nums[i]==nums[i+2])
        {
            if(fun(nums, i+3, dp)) return dp[i]=true;
        }
        // case 3: 3 increasing elements
        if(i+2<n && nums[i+1]==nums[i]+1 && nums[i+2]==nums[i]+2)
        {
            if(fun(nums, i+3, dp)) return dp[i]=true;
        }
        
        return dp[i]=false;
    }
};

int main(){
    // input
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    Solution ob;
    cout<<ob.validPartition(nums)<<endl;
    return 0;
}

// Input: nums = [4,4,4,5,6]
// Output: true
// Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
// This partition is valid, so we return true.