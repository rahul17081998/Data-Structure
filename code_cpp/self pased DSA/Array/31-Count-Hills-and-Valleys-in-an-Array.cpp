#include<bits/stdc++.h>
using namespace std;
// Easy
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int hill=0, valley=0;
        int n = nums.size();
        int prev = nums[0]; // keep record of previous element
        for(int i=1; i<n-1; i++)
        {
            // check if previous index have same value
            if(nums[i]==prev) continue;
            prev = nums[i];
            // find left non-equal element for current element nums[i]
            int left=-1;
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i]!=nums[j]){
                    left=nums[j];
                    break;
                }
                    
            }
            if(left==-1) continue;
            // find right non-equal element for current element nums[i]
            int right=-1;
            for(int j=i+1; j<n; j++)
            {
                if(nums[i]!=nums[j]){
                    right=nums[j];
                    break;
                }
            }
            if(right==-1) continue;
            
            
            // now check wether ith index element is a hill or a valley or nothing
            if( nums[i] > left && nums[i] > right) hill++;
            else if(nums[i] < left && nums[i] < right) valley++;
        }
        
        return hill + valley;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(7);

    Solution ob;
    cout<<ob.countHillValley(nums)<<endl;
    return 0;
}

/*
Input: nums = [2,4,1,1,6,7]
Output: 2

*/