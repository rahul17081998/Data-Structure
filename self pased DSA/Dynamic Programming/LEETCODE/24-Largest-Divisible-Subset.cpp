#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findLis(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis(n, 1);
        
        for(int i=1; i<n; i++)
        {
            // find that number which can devide the current no
            // and compare lis[j]+1 with lis[i] if greater lis[j]+1 > lis[i]
            // keep it stored
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0)
                    lis[i] = max(lis[i], lis[j]+1);
            }
        }
        // print lis
        // for(auto x: lis) cout<<x<<" ";
        return lis;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans, lis;
        sort(nums.begin(), nums.end());
        
        // first find lis array
        lis = findLis(nums);
        int maxi=0; // find maximum of lis
        for(int i=0; i<n; i++) maxi = max(maxi, lis[i]);
        int prevNo=-1; // previous number
        int temp = maxi;
        // find the possible solution
        for(int i=n-1; i>=0; i--)
        {
            // first value just insert it
            if(lis[i]==maxi && maxi==temp)
            {
                ans.push_back(nums[i]);
                prevNo=nums[i];
                maxi--;  
            }
            // for rest of the value
            else if(lis[i]==maxi && maxi!=temp)
            {
                // check if current value devides the previous value
                if(prevNo % nums[i]==0)
                {
                    ans.push_back(nums[i]);
                    prevNo=nums[i];
                    maxi--;  
                }
            }
            
        }
        
        return ans;
    }
};

int main(){
    vector<int> nums;
    // 4 1 7 2 10
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(10);

    Solution ob;
    vector<int> divSub = ob.largestDivisibleSubset(nums);
    for(int i=0; i<divSub.size(); i++) cout<<divSub[i]<<" ";
    return 0;
}