#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        /*
        int n=nums.size();
        int countZero=0;
        int prodect=1;
        // calculate product of all element and count zeros
        for(int i=0; i<nums.size(); i++)
        {
            prodect = prodect*nums[i];
            if(nums[i]==0)
                countZero++;
        }
        
        vector<int> ans;
        // check if zeros are more than 1
        if(countZero >= 2)
        {
            for(int i=0; i<n; i++)
                ans.push_back(0);
        }
         // check if array contain exactly 1 zero
        if(countZero==1){
            for(int i=0; i<n; i++)
            {
                if(nums[i]!=0){
                    ans.push_back(0);
                }
                else if(nums[i]==0){
                    int prod=1;
                    for(int i=0; i<n; i++)
                    {
                        if(nums[i]==0)
                            continue;
                        prod=prod*nums[i];
                    }
                    ans.push_back(prod);
                }
            }
        }
        // check if array have no zero
        if(countZero==0)
        {
            for(int i=0; i<n; i++)
            {
                ans.push_back(prodect/nums[i]);
            }
        }
           
        return ans;
          */  
        
        // Method 2: without using division operator
        // time =O(N), space=(1);
        int n=nums.size();
        vector<int> ans;
        
        int leftMul=1;
        for(int i=0; i<n; i++)
        {
            ans.push_back(leftMul);
            leftMul = leftMul*nums[i];
        }
        
        int rightMul=1;
        for(int i=n-1; i>=0; i--)
        {
            ans[i]=ans[i]*rightMul;
            rightMul=rightMul*nums[i];
        }
            
        return ans;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    Solution ob;
    vector<int> ans = ob.productExceptSelf(nums);
    // print ans
    for(auto x: ans) cout<<x<<" ";
    return 0;
}
/*
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

*/