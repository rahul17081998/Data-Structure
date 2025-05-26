class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        mp[0]=1;
        int prefixSum =0, res = 0;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            int rem = prefixSum%k; 
            // coorner case, if reminder is negative do it positive
            if(rem<0){  
                rem = rem +k;
            }

            res += mp[rem];
            mp[rem]++;
        }
        return res;
    }
};