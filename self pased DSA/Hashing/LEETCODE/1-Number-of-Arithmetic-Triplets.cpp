#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    // method 2:
    //It's amazing, I improved my approach after getting this.
    //Simply for every element(x) in array, check if x+diff and x-diff also exist in array using set. That's it.
    int solve(vector<int>& nums, int diff)
    {
        int ans=0;
    
        // insert all nums[i], i into map
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp.insert({nums[i], i});
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i]+diff)!=mp.end() && mp.find(nums[i]-diff)!=mp.end())
                ans++;
        }
        return ans;
    }
    
    
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        return solve(nums, diff);
//         int i=0, count=0;
//         int n = nums.size();
        
//        for(int i=0; i<=n-3; i++){
//             for(int j=i+1; j<=n-2; j++){
//                 for(int k=j+1; k<=n-1; k++){
//                     if(nums[j]-nums[i]==diff && nums[k]-nums[j]==diff)
//                     {
//                         count++;
//                     }
//                 }
//             }
//         }
//         return count;
    }
};

int main(){
    // Input: nums = [0,1,4,6,7,10], diff = 3
    // Output: 2
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(10);
    int diff = 3;

    Solution ob;
    cout<<ob.arithmeticTriplets(nums, diff)<<endl;
    return 0;
}