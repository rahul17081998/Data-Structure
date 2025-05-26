/*
Problem: Given a 2D integer array nums where nums[i] is a non-empty array of 
distinct positive integers, return the list of integers that are present in 
each array of nums sorted in ascending order.
*/

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> mp;
        for(auto v: nums){
            for(auto val:v)
                mp[val]++;
        }
        vector<int> ans;
        int n = nums.size();
        for(auto p : mp){
            if(p.second==n)
                ans.push_back(p.first);
        }
        
        return ans;
    }
};