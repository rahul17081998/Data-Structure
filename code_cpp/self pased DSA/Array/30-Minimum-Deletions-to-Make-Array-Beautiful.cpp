#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
   
    
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int val=nums[0], count=0;
        
        for(int i=1; i<n; i++)
        {
            if(val == nums[i] && count%2==0) continue;
            else{
                val = nums[i];
                count++;
            }
        }
        int total=count+1;
        if(total%2==1)
            total = total-1;
        
            
        return n-total;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);

    Solution ob;
    cout<<ob.minDeletion(nums)<<endl;
    return 0;
}
/*
Input: nums = [1,1,2,2,3,3]
Output: 2
*/