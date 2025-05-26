class Solution {
public:
    
    int solve(vector<int> nums, int target, vector<int> &t)
    {
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        
        // memoization
        if(t[target]!=-1)
            return t[target];
        
        int ans=0;
        for(auto val: nums)
        {
            ans += solve(nums, target-val, t);
        }
        
        return t[target]=ans; // store the value 
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> t(1001, -1);
        int n=nums.size();
        return solve(nums, target, t);
    }
};
