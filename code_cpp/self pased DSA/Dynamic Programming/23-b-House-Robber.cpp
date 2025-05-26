#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        //create a dp array
        int n=nums.size();
        int dp[n];
        //cornor cases
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        // base case
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[2] + nums[0]; // adjacent robbery in house can not possible 
        
        for(int i=3; i<n; i++)
        {
            // maximum from previous to last to house + current house
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        }
        // find maximum in dp array
        int res=dp[0];
        for(int i=0; i<n; i++)
            res = max(res, dp[i]);
        return res;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(1);

    Solution ob;
    cout<<ob.rob(nums)<<endl;
    return 0;
}
/*
Input: nums = [2,7,9,3,1]
Output: 12
*/